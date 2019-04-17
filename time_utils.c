#ifdef _WIN32
#include <windows.h>
#endif

#include "time_utils.h"

bool gettime(struct timespec *ts) {
#ifdef _WIN32
    if(timespec_get(ts, TIME_UTC) == TIME_UTC) {
        return true;
    }
#else
    if(clock_gettime(CLOCK_REALTIME, ts) == 0) {
        return true;
    }
#endif
    return false;
}

bool delay(uint32_t tms) {
#ifdef _WIN32
    Sleep(tms);
    return true;
#else
    time_t tv_sec = tms / 1000;
    long tv_nsec = (tms % 1000) * 1000000;
    const struct timespec req = {.tv_sec = tv_sec, .tv_nsec = tv_nsec};
    if(nanosleep(&req, NULL) == 0) {
        return true;
    }
    return false;
#endif    
}

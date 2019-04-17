// Works on Posix systems (Linux, macOS, ...), doesn't work on Windows
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    struct timespec t0, t1;

    if(clock_gettime(CLOCK_REALTIME, &t0) != 0) {
        perror("Error in calling clock_gettime");
        exit(EXIT_FAILURE);
    }

    // Do some work ...

    if(clock_gettime(CLOCK_REALTIME, &t1) != 0) {
        perror("Error in calling clock_gettime");
        exit(EXIT_FAILURE);
    }

    // Calculate the elapsed time
    double diff = (double)(t1.tv_sec - t0.tv_sec) + ((double)(t1.tv_nsec - t0.tv_nsec)/1000000000L);
    printf("Elapsed time: %lf seconds\n", diff);
}

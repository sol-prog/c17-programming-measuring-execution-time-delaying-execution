// This works on Posix systems (e.g. macOS, Linux).doesn't work on Windows
#include <stdio.h>
#include <stdlib.h>
#include "time_utils.h"

int main(void) {
    struct timespec t0, t1;

    if(!gettime(&t0)) {
        printf("Error in calling gettime\n");
        exit(EXIT_FAILURE);
    }

    // Delay program execution for half a second
    const struct timespec req = {.tv_nsec = 500000000L};
    if(nanosleep(&req, NULL) != 0) {
        perror("Error in calling clock_gettime");
        exit(EXIT_FAILURE);
    }

    if(!gettime(&t1)) {
        printf("Error in calling gettime\n");
        exit(EXIT_FAILURE);
    }

    // Calculate the elapsed time
    double diff = (double)(t1.tv_sec - t0.tv_sec) + ((double)(t1.tv_nsec - t0.tv_nsec)/1000000000L);
    printf("Elapsed time: %lf seconds\n", diff);
}

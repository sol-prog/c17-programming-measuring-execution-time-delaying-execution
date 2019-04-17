#pragma once

#include <time.h>
#include <stdbool.h>
#include <stdint.h>

// Portable timspec_get equivalent, returns bool true on success
bool gettime(struct timespec *ts);

// Portable sleep function.
// input: time in milliseconds from 0 to 4294967295
// output: bool true on success or false on failure
// on Windows the function will always returns true since Sleep has no return value
bool delay(uint32_t tms);

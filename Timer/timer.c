#include "timer.h"
#include <time.h>

clock_t Timer_start() {
    return clock();
}

double Timer_stop(clock_t start) {
    return (double)(clock() - start) / CLOCKS_PER_SEC;
}
#include "Dummy.h"

Dummy::Dummy(long start, long stop) : start(start), stop(stop) {}

long Dummy::integrate() const {

    long integral = 0;

    for (long i = start; i <= stop; i++) {
        integral += i;
    }

    return integral;
}

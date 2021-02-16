#include "TimeImpl.h"
#include <chrono>
#include <thread>

void TimeImpl::create(bool end_less) {
    TimeImpl::endless = end_less;
    year = 0;
}

long long TimeImpl::now() const {
    return year;
}

void TimeImpl::flow() {
    std::this_thread::sleep_for(std::chrono::hours(365*24));
    ++year;
}

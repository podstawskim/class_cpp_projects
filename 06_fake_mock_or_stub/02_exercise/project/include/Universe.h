#pragma once

#include "Time_.h"
#include "Space.h"
#include "Observer.h"

class Universe {
public:

    explicit Universe(Time_ &time, Space &space, Observer &observer);

    void create();
    void simulate(long years);

private:
    Time_ &time;
    Space &space;
    Observer &observer;
};

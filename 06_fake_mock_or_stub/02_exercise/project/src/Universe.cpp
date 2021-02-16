#include "Universe.h"

Universe::Universe(Time_ &time, Space &space, Observer &observer)
    : time(time), space(space), observer(observer) {

}

void Universe::create() {

    time.create(true);
    space.create(11);
    observer.remember("How many dimensions there are?", std::to_string(space.dimensions()));
}

void Universe::simulate(long years) {

    long long now;

    while ((now = time.now()) < years) {

        if (now == 9300000000) {
            observer.remember("Is there planet Earth?", "Yes!");
        }

        if (now == 9900000000) {
            observer.remember("Does life exist?", "Yes!");
        }

        if (now == 13800000000) {
            observer.remember("Have People evolved?", "Yes!");
        }

        time.flow();
    }
}

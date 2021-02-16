//
// Created by Michał Podstawski on 13/12/2020.
//

#include <observer/observers/Speed.h>

float observer::observers::Speed::get() {
    if (this->isHasFirstValue() && this->isHasSecondValue())
        return this->getSecondValue() - this->getFirstValue();
    return 0;
}

bool observer::observers::Speed::isHasFirstValue() const {
    return hasFirstValue;
}

bool observer::observers::Speed::isHasSecondValue() const {
    return hasSecondValue;
}

float observer::observers::Speed::getFirstValue() const {
    return firstValue;
}

float observer::observers::Speed::getSecondValue() const {
    return secondValue;
}

void observer::observers::Speed::notify(float d) {
    if (isHasFirstValue()) {
        if (isHasSecondValue()) {
            firstValue = secondValue;
            secondValue = d;
        } else {
            hasSecondValue = true;
            secondValue = d;
        }

    } else {
        firstValue = d;
        hasFirstValue = true;
    }
}


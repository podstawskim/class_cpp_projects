//
// Created by Michał Podstawski on 13/12/2020.
//

#include <observer/observers/Acceleration.h>

float observer::observers::Acceleration::get() {
    if(isHasFirstValue() && isHasSecondValue() && isHasThirdValue()) {
        return (this->getThirdValue() - this->getSecondValue()) - (this->getSecondValue() - this->getFirstValue());
    }
    return 0;
}

bool observer::observers::Acceleration::isHasFirstValue() const {
    return hasFirstValue;
}

bool observer::observers::Acceleration::isHasSecondValue() const {
    return hasSecondValue;
}

bool observer::observers::Acceleration::isHasThirdValue() const {
    return hasThirdValue;
}

float observer::observers::Acceleration::getFirstValue() const {
    return firstValue;
}

float observer::observers::Acceleration::getSecondValue() const {
    return secondValue;
}

float observer::observers::Acceleration::getThirdValue() const {
    return thirdValue;
}

void observer::observers::Acceleration::notify(float d) {
    if(isHasFirstValue()) {
        if(isHasSecondValue()) {
            if(isHasThirdValue()) {
                firstValue = secondValue;
                secondValue = thirdValue;
                thirdValue = d;
            }
            hasThirdValue = true;
            thirdValue = d;

        } else {
            hasSecondValue = true;
            secondValue = d;
        }
    } else {
        hasFirstValue = true;
        firstValue = d;
    }

}


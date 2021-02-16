#include "acceleration.h"

Acceleration::Acceleration(QObject *parent) : QObject(parent)
{

}
float Acceleration::get() {
    if(isHasFirstValue() && isHasSecondValue() && isHasThirdValue()) {
        return (this->getThirdValue() - this->getSecondValue()) - (this->getSecondValue() - this->getFirstValue());
    }
    return 0;
}

bool Acceleration::isHasFirstValue() const {
    return hasFirstValue;
}

bool Acceleration::isHasSecondValue() const {
    return hasSecondValue;
}

bool Acceleration::isHasThirdValue() const {
    return hasThirdValue;
}

float Acceleration::getFirstValue() const {
    return firstValue;
}

float Acceleration::getSecondValue() const {
    return secondValue;
}

float Acceleration::getThirdValue() const {
    return thirdValue;
}

void Acceleration::notify(float d) {
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

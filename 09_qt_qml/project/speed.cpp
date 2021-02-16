#include "speed.h"
#include <QDebug>
Speed::Speed(QObject *parent) : QObject(parent)
{

}

float Speed::get() {
    if (this->isHasFirstValue() && this->isHasSecondValue())
        return this->getSecondValue() - this->getFirstValue();

    return 0;
}

bool Speed::isHasFirstValue() const {
    return hasFirstValue;
}

bool Speed::isHasSecondValue() const {
    return hasSecondValue;
}

float Speed::getFirstValue() const {
    return firstValue;
}

float Speed::getSecondValue() const {
    return secondValue;
}

void Speed::notify(float d) {
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

    emit changed();
}

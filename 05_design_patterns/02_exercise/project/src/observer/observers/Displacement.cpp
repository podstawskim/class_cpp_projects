//
// Created by Michał Podstawski on 13/12/2020.
//

#include "observer/observers/Displacement.h"

float observer::observers::Displacement::getValue() const {
    return this->value;
}

void observer::observers::Displacement::set(float val) {
    this->value = val;
    this->notifyObservers(val);
}


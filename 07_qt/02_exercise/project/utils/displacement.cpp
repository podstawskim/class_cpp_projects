#include "displacement.h"

Displacement::Displacement(QObject *parent) : QObject(parent)
{

}

float Displacement::getValue() const {
    return this->value;
}

void Displacement::set(float val) {
    this->value = val;
    emit valueChanged(this->value);
}

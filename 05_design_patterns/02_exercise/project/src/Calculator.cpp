#include "Calculator.h"

Calculator::Calculator(int a, int b) : a(a), b(b) {}

int Calculator::add() const {
    return a + b;
}

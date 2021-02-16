#pragma once
#include <iostream>
#include <sstream>
#include <cstring>
class RingBuffer {
private:
    int capacity;
    int size;
    int head;
    int tail;
    int *buffer;

public:

    explicit RingBuffer(int capacity = 0);

    [[nodiscard]] int getSize() const;

    [[nodiscard]] int getCapacity() const;

    [[nodiscard]] int getHead() const;

    [[nodiscard]] int getTail() const;
    int writeToBuffer(int data);
    int readFromBuffer();

    [[nodiscard]] int *getBuffer() const;

    [[nodiscard]] std::string printBuffer() const;

};
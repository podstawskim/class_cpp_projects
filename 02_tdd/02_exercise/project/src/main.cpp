#include <iostream>

#include "TextWrap.h"
#include "RingBuffer.h"

int main(int argc, char* argv[])
{
    // TODO: ...

    RingBuffer ringBuffer{5};
    ringBuffer.writeToBuffer(1);
    ringBuffer.writeToBuffer(2);
    ringBuffer.writeToBuffer(3);
    ringBuffer.readFromBuffer();
    std::cout<<ringBuffer.printBuffer();



    return 0;
}
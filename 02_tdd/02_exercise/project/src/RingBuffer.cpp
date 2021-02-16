#include "RingBuffer.h"

// TODO: ...
RingBuffer::RingBuffer(int capacity) : capacity(capacity), size(0), head(0), tail(0) {
    this->buffer = new int[capacity];
    memset(this->buffer, 0, this->capacity * sizeof(int));
}

int RingBuffer::getCapacity() const {
    return capacity;
}

int RingBuffer::getSize() const {
    return size;
}

int RingBuffer::getHead() const {
    return head;
}

int RingBuffer::getTail() const {
    return tail;
}

int RingBuffer::writeToBuffer(int data) {

    if(this->getCapacity() == 0)
        return EXIT_FAILURE;
    this->getBuffer()[this->getHead()] = data;
    if(this->getCapacity()-this->getSize() == 0)
    {
        this->tail = (this->tail + 1) % this->getCapacity();
    }
    this->head = (this->head + 1) % this->getCapacity();
    if(this->getSize() < this->getCapacity()) //jesli bufor jest dalej pelny po dodaniu elemntu to nie zwiekszamy wartosci size
    {
        this->size++;
    }
    return data;
}

std::string RingBuffer::printBuffer() const {
    std::stringstream sOut;

    sOut << "[";
    for (int i = 0; i < this->getCapacity(); i++) {
        //jesli w komorce bufora nic nie ma to print -
        if(this->getBuffer()[i] != 0) sOut<<this->getBuffer()[i]<<" ";
        else
            sOut<<"- ";
    }
    sOut << "] Size " <<this->getSize()<< std::endl;
    return sOut.str();
}

int RingBuffer::readFromBuffer() {
    if(this->getSize() == 0)
        return EXIT_FAILURE;

    //czytam to co mam aktualnie w ogonie
    int data = this->getBuffer()[this->getTail()];
    //przesuwam ogon
    this->getBuffer()[this->getTail()] = 0;
    this->tail = (this->getTail() + 1) % this->getCapacity();
    //zmniejszam

    this->size--;
    return data;

}

int *RingBuffer::getBuffer() const {
    return buffer;
}









#pragma once

class Dummy {
public:

    Dummy(long start, long stop);

    long integrate() const;

private:
    long start;
    long stop;
};
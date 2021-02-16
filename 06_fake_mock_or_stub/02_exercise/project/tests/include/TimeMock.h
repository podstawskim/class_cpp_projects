//
// Created by Michał Podstawski on 20/12/2020.
//

#ifndef PROJECT_TIMEMOCK_H
#define PROJECT_TIMEMOCK_H
#include "TestIncludes.h"
#include "Time_.h"

class TimeMock : public Time_ {
public:
    MOCK_METHOD1(create, void(bool endless));
    MOCK_CONST_METHOD0(now, long long());
    MOCK_METHOD0(flow, void());
};
#endif //PROJECT_TIMEMOCK_H

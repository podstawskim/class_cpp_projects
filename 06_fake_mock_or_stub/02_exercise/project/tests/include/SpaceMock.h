//
// Created by Michał Podstawski on 20/12/2020.
//

#ifndef PROJECT_SPACEMOCK_H
#define PROJECT_SPACEMOCK_H
#include "TestIncludes.h"
#include "Space.h"

class SpaceMock : public Space {
public:
    MOCK_METHOD1(create, void(unsigned int dimensions));
    MOCK_CONST_METHOD0(dimensions, unsigned int());
};

#endif //PROJECT_SPACEMOCK_H

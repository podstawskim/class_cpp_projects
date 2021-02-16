//
// Created by Michał Podstawski on 20/12/2020.
//

#ifndef PROJECT_OBSERVERMOCK_H
#define PROJECT_OBSERVERMOCK_H
#include "TestIncludes.h"
#include "Observer.h"

class ObserverMock : public Observer {
public:
    MOCK_METHOD2(remember, void(std::string question, std::string answer));
    MOCK_CONST_METHOD1(answer, std::string(std::string question));

};
#endif //PROJECT_OBSERVERMOCK_H

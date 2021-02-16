//
// Created by Michał Podstawski on 18/12/2020.
//

#ifndef PROJECT_OBSERVER_H
#define PROJECT_OBSERVER_H

#include <map>
#include <string>

class Observer {
public:
    virtual ~Observer() = default;
    virtual void remember(std::string question, std::string answer) = 0;
    [[nodiscard]] virtual std::string answer(std::string question) const = 0;

};

#endif //PROJECT_OBSERVER_H

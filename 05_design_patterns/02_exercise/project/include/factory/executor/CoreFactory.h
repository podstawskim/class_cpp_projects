//
// Created by Michał Podstawski on 13/12/2020.
//

#ifndef PROJECT_COREFACTORY_H
#define PROJECT_COREFACTORY_H

#include "factory/executor/Core.h"
#include <iostream>
#include <memory>
namespace factory::executor {
    class CoreFactory {
    public:
        virtual ~CoreFactory() = default;
        virtual std::shared_ptr<Core> create(std::string equation) = 0;
    };
}
#endif //PROJECT_COREFACTORY_H

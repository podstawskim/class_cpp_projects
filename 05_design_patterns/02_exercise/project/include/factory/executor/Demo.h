//
// Created by Michał Podstawski on 13/12/2020.
//

#ifndef PROJECT_DEMO_H
#define PROJECT_DEMO_H

#include "factory/executor/CoreFactory.h"

namespace factory::executor{
    class Demo {
    private:
        std::shared_ptr<CoreFactory> factory;
    public:
        explicit Demo(std::shared_ptr<CoreFactory>factory);
        void run (std::string equation);
    };
}
#endif //PROJECT_DEMO_H

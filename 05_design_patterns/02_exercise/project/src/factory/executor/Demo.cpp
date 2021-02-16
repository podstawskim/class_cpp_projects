//
// Created by Michał Podstawski on 13/12/2020.
//

#include "factory/executor/Demo.h"

#include <utility>

factory::executor::Demo::Demo(std::shared_ptr<executor::CoreFactory> factory) : factory(std::move(factory)) {

}

void factory::executor::Demo::run(std::string equation) {
    auto core = factory->create(std::move(equation));
    core->execute();
}

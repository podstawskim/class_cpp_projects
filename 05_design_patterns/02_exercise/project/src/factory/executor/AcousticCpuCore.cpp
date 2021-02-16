//
// Created by Michał Podstawski on 13/12/2020.
//

#include <factory/executor/AcousticCpuCore.h>
#include <iostream>
factory::executor::AcousticCpuCore::AcousticCpuCore(int threads) : threads(threads) {

}

void factory::executor::AcousticCpuCore::execute() {
    std::cout<<"factory::executor::AcousticCpuCore{threads: " << this->threads << "}" << std::endl;
}


//
// Created by Michał Podstawski on 13/12/2020.
//

#include <factory/executor/AnisotropicCpuCore.h>
#include <iostream>
factory::executor::AnisotropicCpuCore::AnisotropicCpuCore(int threads) : threads(threads) {

}

void factory::executor::AnisotropicCpuCore::execute() {
    std::cout<<"factory::executor::AnisotropicCpuCore{threads: " << this->threads << "}" << std::endl;
}


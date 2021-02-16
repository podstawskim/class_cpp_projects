//
// Created by Michał Podstawski on 13/12/2020.
//


#include <factory/executor/AcousticCudaCore.h>
#include <iostream>
factory::executor::AcousticCudaCore::AcousticCudaCore(int gpuId) : gpuId(gpuId) {

}

void factory::executor::AcousticCudaCore::execute() {
    std::cout<<"factory::executor::AcousticCudaCore{gpuId: " << this->gpuId << "}" << std::endl;
}


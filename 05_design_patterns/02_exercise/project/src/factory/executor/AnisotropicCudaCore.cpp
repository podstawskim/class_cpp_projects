//
// Created by Michał Podstawski on 13/12/2020.
//

#include <factory/executor/AnisotropicCudaCore.h>
#include <iostream>

factory::executor::AnisotropicCudaCore::AnisotropicCudaCore(int gpuId) : gpuId(gpuId) {

}

void factory::executor::AnisotropicCudaCore::execute() {
    std::cout<<"factory::executor::AnisotropicCudaCore{gpuId: " << this->gpuId << "}" << std::endl;
}




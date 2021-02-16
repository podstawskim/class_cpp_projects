//
// Created by Michał Podstawski on 13/12/2020.
//

#include <factory/executor/ElasticCudaCore.h>
#include <iostream>

factory::executor::ElasticCudaCore::ElasticCudaCore(int gpuId) : gpuId(gpuId) {

}

void factory::executor::ElasticCudaCore::execute() {
    std::cout<<"factory::executor::ElasticCudaCore{gpuId: " << this->gpuId << "}" << std::endl;
}


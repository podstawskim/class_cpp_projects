//
// Created by Michał Podstawski on 13/12/2020.
//

#include "factory/executor/CudaCoreFactory.h"
#include "factory/executor/AcousticCudaCore.h"
#include "factory/executor/AnisotropicCudaCore.h"
#include "factory/executor/ElasticCudaCore.h"

factory::executor::CudaCoreFactory::CudaCoreFactory(int gpuId) : gpuId(gpuId){}

std::shared_ptr<factory::executor::Core> factory::executor::CudaCoreFactory::create(std::string equation) {
    if(equation == "acoustic") {
        return std::make_shared<AcousticCudaCore>(this->gpuId);
    }

    if(equation == "anisotropic"){
        return std::make_shared<AnisotropicCudaCore>(this->gpuId);
    }

    if(equation == "elastic") {
        return std::make_shared<ElasticCudaCore>(this->gpuId);
    }

    throw std::runtime_error("Unsupported Cuda equation type: " + equation);
}

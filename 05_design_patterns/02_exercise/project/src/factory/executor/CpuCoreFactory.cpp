//
// Created by Michał Podstawski on 13/12/2020.
//

#include "factory/executor/CpuCoreFactory.h"
#include "factory/executor/AcousticCpuCore.h"
#include "factory/executor/AnisotropicCpuCore.h"
#include "factory/executor/ElasticCpuCore.h"

factory::executor::CpuCoreFactory::CpuCoreFactory(int threads) : threads(threads) {

}

std::shared_ptr<factory::executor::Core> factory::executor::CpuCoreFactory::create(std::string equation) {
    if(equation == "acoustic") {
        return std::make_shared<AcousticCpuCore>(this->threads);
    }

    if(equation == "anisotropic") {
        return std::make_shared<AnisotropicCpuCore>(this->threads);
    }

    if(equation == "elastic") {
        return std::make_shared<ElasticCpuCore>(this->threads);
    }

    throw std::runtime_error("Unsupported Cpu equation type: " + equation);

}

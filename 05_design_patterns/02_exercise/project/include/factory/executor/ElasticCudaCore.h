//
// Created by Michał Podstawski on 13/12/2020.
//

#ifndef PROJECT_ELASTICCUDACORE_H
#define PROJECT_ELASTICCUDACORE_H

#include "factory/executor/Core.h"

namespace factory::executor {
    class ElasticCudaCore : public Core {
    private:
        int gpuId;
    public:
        explicit ElasticCudaCore(int gpuId);
        void execute() override;
    };

}

#endif //PROJECT_ELASTICCUDACORE_H

//
// Created by Michał Podstawski on 13/12/2020.
//

#ifndef PROJECT_CUDACOREFACTORY_H
#define PROJECT_CUDACOREFACTORY_H

#include "factory/executor/CoreFactory.h"

namespace factory::executor {
    class CudaCoreFactory : public CoreFactory {
    private:
        int gpuId;
    public:
        explicit CudaCoreFactory(int gpuId);
        std::shared_ptr<Core> create(std::string equation) override;

    };
}

#endif //PROJECT_CUDACOREFACTORY_H

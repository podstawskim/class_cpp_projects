//
// Created by Michał Podstawski on 13/12/2020.
//

#ifndef PROJECT_ANISOTROPICCUDACORE_H
#define PROJECT_ANISOTROPICCUDACORE_H

#include "factory/executor/Core.h"

namespace factory::executor {
    class AnisotropicCudaCore : public Core {
    private:
        int gpuId;
    public:
        explicit AnisotropicCudaCore(int gpuId);
        void execute() override;
    };
}

#endif //PROJECT_ANISOTROPICCUDACORE_H

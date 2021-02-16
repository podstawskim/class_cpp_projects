//
// Created by Michał Podstawski on 13/12/2020.
//

#ifndef PROJECT_ACOUSTICCUDACORE_H
#define PROJECT_ACOUSTICCUDACORE_H

#include "factory/executor/Core.h"

namespace factory::executor {
    class AcousticCudaCore : public Core {
    private:
        int gpuId;
    public:
        explicit AcousticCudaCore(int gpuId);
        void execute() override;
    };
}

#endif //PROJECT_ACOUSTICCUDACORE_H

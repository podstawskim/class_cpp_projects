//
// Created by Michał Podstawski on 13/12/2020.
//

#ifndef PROJECT_ANISOTROPICCPUCORE_H
#define PROJECT_ANISOTROPICCPUCORE_H

#include "factory/executor/Core.h"

namespace factory::executor {
    class AnisotropicCpuCore : public Core {
    private:
        int threads;
    public:
        explicit AnisotropicCpuCore(int threads);
        void execute() override;
    };
}
#endif //PROJECT_ANISOTROPICCPUCORE_H

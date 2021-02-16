//
// Created by Michał Podstawski on 13/12/2020.
//

#ifndef PROJECT_ACOUSTICCPUCORE_H
#define PROJECT_ACOUSTICCPUCORE_H
#include "factory/executor/Core.h"

namespace factory::executor {
    class AcousticCpuCore : public Core {
    private:
        int threads;
    public:
        explicit AcousticCpuCore(int threads);
        void execute() override;
    };
}
#endif //PROJECT_ACOUSTICCPUCORE_H

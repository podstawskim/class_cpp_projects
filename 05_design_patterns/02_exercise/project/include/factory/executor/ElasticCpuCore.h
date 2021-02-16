//
// Created by Michał Podstawski on 13/12/2020.
//

#ifndef PROJECT_ELASTICCPUCORE_H
#define PROJECT_ELASTICCPUCORE_H
#include "factory/executor/Core.h"

namespace factory::executor {
    class ElasticCpuCore : public Core {
    private:
        int threads;
    public:
        explicit ElasticCpuCore(int threads);
        void execute() override;
    };
}
#endif //PROJECT_ELASTICCPUCORE_H

//
// Created by Michał Podstawski on 13/12/2020.
//

#ifndef PROJECT_CPUCOREFACTORY_H
#define PROJECT_CPUCOREFACTORY_H

#include "factory/executor/CoreFactory.h"

namespace factory::executor {
    class CpuCoreFactory : public CoreFactory {
    private:
        int threads;
    public:
        explicit CpuCoreFactory(int threads);
        std::shared_ptr<Core> create(std::string equation) override;

    };
}

#endif //PROJECT_CPUCOREFACTORY_H

//
// Created by Michał Podstawski on 13/12/2020.
//

#include <factory/executor/ElasticCpuCore.h>
#include <iostream>
factory::executor::ElasticCpuCore::ElasticCpuCore(int threads) : threads(threads){

}

void factory::executor::ElasticCpuCore::execute() {
    std::cout<<"factory::executor::ElasticCpuCore{threads: " << this->threads << "}" << std::endl;

}


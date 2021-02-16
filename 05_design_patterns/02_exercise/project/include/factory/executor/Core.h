//
// Created by Michał Podstawski on 13/12/2020.
//

#ifndef PROJECT_CORE_H
#define PROJECT_CORE_H

namespace factory::executor {
        class Core {
        public:
            virtual ~Core() = default;
            virtual void execute() {

            }
        };
    }
#endif //PROJECT_CORE_H

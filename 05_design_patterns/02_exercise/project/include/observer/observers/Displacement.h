//
// Created by Michał Podstawski on 13/12/2020.
//


#pragma once

#include "observer/observers/Observable.h"

namespace observer::observers {
        class Displacement : public Observable {
        private:

            float value = 0;
        public:
            void set(float val);
            [[nodiscard]] float getValue() const;
        };
    }


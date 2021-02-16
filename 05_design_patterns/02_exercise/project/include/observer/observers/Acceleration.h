//
// Created by Michał Podstawski on 13/12/2020.
//

#ifndef PROJECT_ACCELERATION_H
#define PROJECT_ACCELERATION_H

#include "observer/observers/Observer.h"

namespace observer::observers {
        class Acceleration : public Observer {
        private:
            bool hasFirstValue = false;
            bool hasSecondValue = false;
            bool hasThirdValue = false;
            float firstValue = 0;
            float secondValue = 0;
            float thirdValue = 0;
        public:
            float get();

            void notify(float d) override;

            [[nodiscard]] bool isHasFirstValue() const;

            [[nodiscard]] bool isHasSecondValue() const;

            [[nodiscard]] bool isHasThirdValue() const;

            [[nodiscard]] float getFirstValue() const;

            [[nodiscard]] float getSecondValue() const;

            [[nodiscard]] float getThirdValue() const;
        };
    }

#endif //PROJECT_ACCELERATION_H

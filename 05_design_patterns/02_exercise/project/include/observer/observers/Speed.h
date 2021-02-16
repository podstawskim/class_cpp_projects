//
// Created by Michał Podstawski on 13/12/2020.
//

#ifndef PROJECT_SPEED_H
#define PROJECT_SPEED_H

#include "observer/observers/Observer.h"

namespace observer::observers{
        class Speed : public Observer{
        private:
            bool hasFirstValue = false;
            bool hasSecondValue = false;
            float firstValue = 0;
            float secondValue = 0;
        public:
            float get();

            void notify(float d) override;

            [[nodiscard]] bool isHasFirstValue() const;

            [[nodiscard]] bool isHasSecondValue() const;

            [[nodiscard]] float getFirstValue() const;

            [[nodiscard]] float getSecondValue() const;
        };
    }
#endif //PROJECT_SPEED_H

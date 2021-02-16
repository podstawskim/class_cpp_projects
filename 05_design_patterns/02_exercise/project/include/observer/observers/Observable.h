//
// Created by Michał Podstawski on 13/12/2020.
//

#ifndef PROJECT_OBSERVABLE_H
#define PROJECT_OBSERVABLE_H
#include "observer/observers/Observer.h"
#include <set>

namespace observer::observers{
        class Observable : public Observer{
        private:
            std::set<Observer*> observers;
        public:
            void registerObserver(Observer* observer);
            void unregisterObserver(Observer* observer);

        protected:
            void notifyObservers(float value);
        };
    }
#endif //PROJECT_OBSERVABLE_H

//
// Created by Michał Podstawski on 13/12/2020.
//

#include <observer/observers/Observable.h>

void observer::observers::Observable::registerObserver(Observer *observer) {
    this->observers.insert(observer); //dodawanie nowego obserwatora

}

void observer::observers::Observable::unregisterObserver(observer::observers::Observer *observer) {
    this->observers.erase(observer); //usuwanie obserwatora
}

void observer::observers::Observable::notifyObservers(float value) {
    for(Observer* observer: observers) {
        observer->notify(value);
    }
}




//
// Created by Maria on 15/06/2026.
//

#include "subject.h"

void Subject::registerObserver(Observer *obs) {
    observers.push_back(obs);
}

void Subject::unregisterObserver(Observer *obs) {
    observers.erase(std::remove(observers.begin(),observers.end(),obs),observers.end());
}

void Subject::notify() {
    for (auto o:observers) {
        o->update();
    }
}

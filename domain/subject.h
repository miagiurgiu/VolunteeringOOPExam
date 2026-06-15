//
// Created by Maria on 15/06/2026.
//

#ifndef VOLUNTEERINGOOPEXAM_SUBJECT_H
#define VOLUNTEERINGOOPEXAM_SUBJECT_H

#include <vector>
#include "observer.h"

class Subject {
private:
    std::vector<Observer*> observers;
public:
    Subject()=default;
    void registerObserver(Observer* obs);
    void unregisterObserver(Observer* obs);
    void notify();
};



#endif //VOLUNTEERINGOOPEXAM_SUBJECT_H

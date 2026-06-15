//
// Created by Maria on 15/06/2026.
//

#ifndef VOLUNTEERINGOOPEXAM_OBSERVER_H
#define VOLUNTEERINGOOPEXAM_OBSERVER_H

class Observer {
public:
    virtual void update()=0; // every window must refresh itself
    virtual ~Observer()=default; // base class virtual destructor
};


#endif //VOLUNTEERINGOOPEXAM_OBSERVER_H


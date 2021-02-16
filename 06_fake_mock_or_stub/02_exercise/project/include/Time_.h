//
// Created by Michał Podstawski on 18/12/2020.
//

#ifndef PROJECT_TIME__H
#define PROJECT_TIME__H

class Time_ {
public:
    virtual ~Time_() = default;
    virtual void create(bool endless) = 0;
    virtual void flow() = 0;
    [[nodiscard]] virtual long long int now() const = 0 ;

};

#endif //PROJECT_TIME__H

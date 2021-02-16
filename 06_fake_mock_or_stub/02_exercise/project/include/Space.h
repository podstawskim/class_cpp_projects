//
// Created by Michał Podstawski on 18/12/2020.
//

#ifndef PROJECT_SPACE_H
#define PROJECT_SPACE_H

class Space {

public:
    virtual ~Space() = default;
    virtual void create(unsigned int dimensions) = 0;
    [[nodiscard]] virtual unsigned int dimensions() const = 0;

};

#endif //PROJECT_SPACE_H

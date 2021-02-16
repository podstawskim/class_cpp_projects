#pragma once

#include "Point.h"
#include "Space.h"

#include <vector>

class SpaceImpl : public Space{
public:

    void create(unsigned int dimensions) override;
    [[nodiscard]] unsigned int dimensions() const override;

private:
    unsigned int dimensionsCount;
    std::vector<Point> points;
};
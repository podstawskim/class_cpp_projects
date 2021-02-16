#include "SpaceImpl.h"

#include <limits>

void SpaceImpl::create(unsigned int dimensions) {

    dimensionsCount = dimensions;

    auto infiniteNumberOfPoints = std::numeric_limits<std::size_t>::max();
    points.resize(infiniteNumberOfPoints);
}

unsigned int SpaceImpl::dimensions() const {
    return dimensionsCount;
}

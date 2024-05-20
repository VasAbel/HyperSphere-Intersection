#include "Point.h"
#include <cmath>

//default constructor gives back a point in the origo
Point::Point() {
    coordinates.fill(0.0f);
}

Point::Point(const std::array<float, N>& coords) : coordinates(coords) {}

//calculates the euclidean distance to another Point "p"
float Point::distanceTo(const Point& p) const {
	float distance = 0.0f;
    for (int i = 0; i < N; ++i) {
        float diff = coordinates[i] - p.coordinates[i];
        distance += diff * diff;
    }
    return std::sqrtf(distance);
}
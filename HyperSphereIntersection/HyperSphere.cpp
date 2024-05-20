#include "HyperSphere.h"

//default constructor returns a point with negative radius, indicating non-existent object for cases
//where no intersection was found. 
HyperSphere::HyperSphere() : p(), r(-1.0f) {}

HyperSphere::HyperSphere(const Point& center, float radius) : p(center), r(radius) {}

//calculates the tangent point with another sphere s. The boolean ext determines if we are looking for an external or an internal tangent.
Point HyperSphere::tangentPointWith(const HyperSphere& s, bool ext) const {
    Point tangentPoint;
    std::array<float, N> unitVector;
    float d = p.distanceTo(s.getCenter());

    // Calculate the unit vector from this center to the other center
    for (int i = 0; i < N; i++) {
        unitVector[i] = (s.getCenter().getCoords()[i] - p.getCoords()[i]) / d;
    }

    if (ext) {
        // External tangent point
        for (int i = 0; i < N; i++) {
            tangentPoint.setOneCoord(p.getCoords()[i] + r * unitVector[i], i);
        }
    }
    else {
        // Internal tangent point: correct direction has to be ensured by moving from the center of the larger hypersphere to the
        //center of the smaller one.
        HyperSphere smaller = (r < s.getRadius()) ? *this : s;
        HyperSphere larger = (r < s.getRadius()) ? s : *this;
        d = smaller.getCenter().distanceTo(larger.getCenter());
        for (int i = 0; i < N; ++i) {
            unitVector[i] = (larger.getCenter().getCoords()[i] - smaller.getCenter().getCoords()[i]) / d;
            tangentPoint.setOneCoord(smaller.getCenter().getCoords()[i] + smaller.getRadius() * unitVector[i], i);
        }
    }

    return tangentPoint;
}
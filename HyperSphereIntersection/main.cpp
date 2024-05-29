#include <iostream>
#include "Intersection.h"

//aid function to calculate the normal vector
static std::array<float, N> calculateOrientation(const HyperSphere& s1, const HyperSphere& s2) {
    std::array<float, N> orientation;
    float normalize = 0.0;

    for (int i = 0; i < N; i++) {
        orientation[i] = s2.getCenter().getCoords()[i] - s1.getCenter().getCoords()[i];
        normalize += orientation[i] * orientation[i];
    }

    normalize = std::sqrtf(normalize);

    for (int i = 0; i < N; i++) {
        orientation[i] /= normalize;
    }


    return orientation;
}

//checks intersection between two hyperspheres s1 and s2. Returns an Intersection object containing the data of the relation.
//if branches are checking for specific relations using the proper mathematical formulas.
static Intersection checkIntersection(const HyperSphere& s1, const HyperSphere& s2) {
    float distance = s1.getCenter().distanceTo(s2.getCenter());

    //No intersection
    if (distance > s1.getRadius() + s2.getRadius()) {
        return Intersection();
    }

    //External tangent
    else if (distance == s1.getRadius() + s2.getRadius()) {
        Point tangentPoint = s1.tangentPointWith(s2, true);
        return Intersection(IntersectionRelation::TangentExternally, IntersectingHyperSphere(tangentPoint, 0.0f));
    }

    //Internal tangent
    else if (distance == std::abs(s1.getRadius() - s2.getRadius()) && s1.getRadius() != s2.getRadius()) {
        Point tangentPoint = s1.tangentPointWith(s2, false);
        return Intersection(IntersectionRelation::TangentInternally, IntersectingHyperSphere(tangentPoint, 0.0f));
    }

    //One hypersphere is inside the other without touching its surface
    else if (distance < std::abs(s1.getRadius() - s2.getRadius())) {
        return Intersection(IntersectionRelation::OneInsideAnother, IntersectingHyperSphere());
    }

    //The two hyperspheres have exactly the same center and radius
    else if (distance == 0 && s1.getRadius() == s2.getRadius()) {
        return Intersection(IntersectionRelation::Coincident, IntersectingHyperSphere(s1.getCenter(), s1.getRadius()));
    }

    //Regular intersection 
    else {
        float a = (s1.getRadius() * s1.getRadius() - s2.getRadius() * s2.getRadius() + distance * distance) / (2 * distance);

        Point intersectionCenter;
        for (int i = 0; i < N; ++i) {
            intersectionCenter.setOneCoord(s1.getCenter().getCoords()[i] + a * (s2.getCenter().getCoords()[i] - s1.getCenter().getCoords()[i]) / distance, i);
        }

        float intersectionRadius = std::sqrt(s1.getRadius() * s1.getRadius() - a * a);
        std::array<float, N> orientation = calculateOrientation(s1, s2);

        return Intersection(IntersectionRelation::Intersecting, IntersectingHyperSphere(intersectionCenter, intersectionRadius, orientation));
    }
}

int main() {
    //Example use of the checkIntersection function
    Point center1 = { {0.0, 0.0, 0.0} };
    Point center2 = { {1.0f, 0.7f, 0.0f} };

    HyperSphere sphere1 = { center1, 1.0f };
    HyperSphere sphere2 = {center2, 1.0f};

    Intersection result = checkIntersection(sphere1, sphere2);

    result.printResult();
    
    std::cin.get();

    return 0;
}


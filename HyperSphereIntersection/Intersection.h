#pragma once

#include "IntersectingHyperSphere.h"
#include "IntersectionRelation.h"
#include <iostream>

//the data structure for the result of intersection detection. It contains an enum for maintaining the type of the relation
//and an IntersectingHyperSphere collidingObjects field to represent the structure of the collision which is a one dimension lower hypersphere
//than the inspected ones.
class Intersection {
private:
    IntersectionRelation relation;
    IntersectingHyperSphere collidingPoints;

public:
    Intersection();
    Intersection(IntersectionRelation rel, const IntersectingHyperSphere& points);

    inline IntersectionRelation getRelation() const { return relation; }
    inline IntersectingHyperSphere getCollidingPoints() const { return collidingPoints; }

    //prints out the data of the structure
    void printResult() const;
};

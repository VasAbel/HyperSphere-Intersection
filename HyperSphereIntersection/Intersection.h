#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "HyperSphere.h"
#include "IntersectionRelation.h"
#include <iostream>

//the data structure for the result of intersection detection. It contains an enum for maintaining the type of the relation
//and a HyperSphere collidingObjects field to represent the structure of the collision which is a one dimension lower hypersphere
//than the inspected ones. 2D circles are an exception, where 2 points of intersection can be found instead of one hypersphere
//But in this case, the same calculation works in a way that it gives back the point between the two intersection points and the radius represents
//the distance of this point from them.
class Intersection {
private:
    IntersectionRelation relation;
    HyperSphere collidingPoints;

public:
    Intersection();
    Intersection(IntersectionRelation rel, const HyperSphere& points);

    inline IntersectionRelation getRelation() const { return relation; }
    inline HyperSphere getCollidingPoints() const { return collidingPoints; }

    //prints out the data of the structure
    void printResult() const;
};

#endif

#pragma once

#include "Point.h"

//class for representing hyperspheres with a center and a radius
class HyperSphere {
private:
    const Point p;
    const float r;

public:
    HyperSphere();
    HyperSphere(const Point& center, float radius);
    //Intersection checkIntersection(const HyperSphere& s) const; function would be reasonable here too, but it is currently realized as an individual function 
    //getting two hyperspheres as parameter
     
    //calculates the tangent point with another hypersphere 
    Point tangentPointWith(const HyperSphere& s, bool ext) const;

    inline Point getCenter() const {return p;}
    inline float getRadius() const {return r;}
}; 

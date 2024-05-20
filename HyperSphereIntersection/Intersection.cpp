#include "Intersection.h"

//Default constructor returns an intersection object with NoIntersection relation.
Intersection::Intersection() : relation(IntersectionRelation::NoIntersection), collidingPoints(){}

Intersection::Intersection(IntersectionRelation rel, const HyperSphere& points)
    : relation(rel), collidingPoints(points) {}

//prints out the data stored in the object. Basically the type of the relation and the center and radius of the hypersphere 
//formed by the intersection of the two inspected hyperspheres, if it makes sense considering the relation type.
void Intersection::printResult() const {
    switch (relation) {
    case IntersectionRelation::NoIntersection:
        std::cout << "No Intersection" << std::endl;
        break;
    case IntersectionRelation::TangentExternally:
        std::cout << "Tangent Externally" << std::endl;
        std::cout << "Point: " << std::endl;
        for (float coord : collidingPoints.getCenter().getCoords()) {
            std::cout << coord << " ";
        }
        break;
    case IntersectionRelation::TangentInternally:
        std::cout << "Tangent Internally" << std::endl;
        std::cout << "Point: " << std::endl;
        for (float coord : collidingPoints.getCenter().getCoords())
            std::cout << coord << " ";
        break;
    case IntersectionRelation::Intersecting:
        std::cout << "Intersecting" << std::endl;
        std::cout << "Intersection Hypersphere Center: " << std::endl;
        for (float coord : collidingPoints.getCenter().getCoords()) {
            std::cout << coord << " ";
            std::cout << std::endl;
        }
        std::cout << "\nIntersection Hypersphere Radius: " << collidingPoints.getRadius() << std::endl;
        break;
    case IntersectionRelation::OneInsideAnother:
        std::cout << "One Inside Another" << std::endl;
        break;
    case IntersectionRelation::Coincident:
        std::cout << "Coincident" << std::endl;
        break;
    }
}
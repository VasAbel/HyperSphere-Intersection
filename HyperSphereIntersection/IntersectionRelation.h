#ifndef INTERSECTIONRELATION_H
#define INTERSECTIONRELATION_H

//enum class representing the possible relations between two hyperspheres
enum class IntersectionRelation {
    NoIntersection,
    TangentExternally,
    TangentInternally,
    Intersecting,
    OneInsideAnother,
    Coincident
};

#endif // INTERSECTIONRELATION_H

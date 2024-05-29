#pragma once

//enum class representing the possible relations between two hyperspheres
enum class IntersectionRelation {
    NoIntersection,
    TangentExternally,
    TangentInternally,
    Intersecting,
    OneInsideAnother,
    Coincident
};

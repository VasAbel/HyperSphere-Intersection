#pragma once

#include <array>
constexpr int N = 3;    //prepocessor macro for the dimension of the hyperspheres.

//This class represents a point in the geometry. It contains an array of N elements representing the coordinates of the point.
class Point {
private:
    std::array<float, N> coordinates;

public:
    Point();
    Point(const std::array<float, N>& coords);

    //calculates the euclidean distance to another point
    float distanceTo(const Point& p) const;

    inline std::array<float, N> getCoords() const {return coordinates;}

    //setOneCoord is a setter function for setting one element of the coordinates at a time.
    inline void setOneCoord(float coord, int element) { coordinates[element] = coord; }
};
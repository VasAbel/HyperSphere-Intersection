#pragma once

#include "HyperSphere.h"

//Subclass of HyperSphere to represent the hypersphere of the intersection. Technically, the intersection is also a hypersphere, but one
//dimension lower. An N dimensional hypersphere can be identified by only its center and radius in the N dimensional space, but the N-1
//dimensional hypersphere formed by the intersection needs an additional orientation value, calculated as the normal vector of the hyperplane
//it lays on.  
class IntersectingHyperSphere : public HyperSphere {
private:
	std::array<float, N> orientation;
public:
	IntersectingHyperSphere() : HyperSphere() { orientation.fill(0.0f); }
	IntersectingHyperSphere(const Point& center, float radius) : HyperSphere(center, radius) { orientation.fill(0.0f); }
	IntersectingHyperSphere(const Point& center, float radius, std::array<float, N>& o) : HyperSphere(center, radius), orientation(o) {}
	inline std::array<float, N> getOrientation() const { return orientation; }
};

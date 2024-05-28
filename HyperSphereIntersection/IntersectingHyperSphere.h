#pragma once

#include "HyperSphere.h"

class IntersectingHyperSphere : public HyperSphere {
private:
	std::array<float, N> orientation;
public:
	IntersectingHyperSphere() : HyperSphere() { orientation.fill(0.0f); }
	IntersectingHyperSphere(const Point& center, float radius) : HyperSphere(center, radius) { orientation.fill(0.0f); }
	IntersectingHyperSphere(const Point& center, float radius, std::array<float, N>& o) : HyperSphere(center, radius), orientation(o) {}
	inline std::array<float, N> getOrientation() const { return orientation; }
};

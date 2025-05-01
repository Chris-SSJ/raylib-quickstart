#pragma once
#include "shape.h"
#include <vector>

class Brush : public Shape {
public:
	Brush(Color color);

	void Draw() override;
	void Update() override;
	Type GetType() override { return Type::Brush; }

private:
	std::vector<Vector2> m_points;
};

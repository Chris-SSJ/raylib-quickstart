#pragma once
#include "shape.h"

class Triangle :public Shape {
public:
	Triangle() = default;
	Triangle(const Vector2& position, float size = 40, const Color& color = WHITE) :
		Shape(position, size, color)
	{

	}


	void Update() override;
	void Draw() override;
	Type GetType() override { return Type::Triangle; }
};

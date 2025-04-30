#pragma once
#include "shape.h"

class Square : public Shape {
public:

	Square() = default;
	Square(const Vector2& position, float size = 40, const Color& color = WHITE, float roate=90.0f) :
		Shape(position, size, color,roate)
	{

	}


	void Update() override;
	void Draw() override;
	Type GetType() override { return Type::Square; }

};
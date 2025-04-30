#pragma once
#include "shape.h"

class Circle : public Shape {
public:

	Circle() = default;
	Circle(const Vector2& position, float size = 20, const Color& color = WHITE, float roate=90.0f) :
		Shape(position, size, color,roate) 
	{

	}


	void Update() override;
	void Draw() override;
	Type GetType() override {return Type::Circle;}

};

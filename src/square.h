#pragma once
#include "shape.h"

class Square : public Shape {
public:

	Square() = default;
	Square(const Vector2& position, float size = 40, const Color& color = WHITE) :
		Shape(position, size, color)
	{

	}


	void Update() override;
	void Draw() override;
	Type GetType() override { return Type::Square; }


protected:
	float m_roation{ 0 };

};
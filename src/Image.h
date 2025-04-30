#pragma once
#include "shape.h"

class ImageShape : public Shape {
public:
	ImageShape() = default;
	ImageShape(const Texture2D& texture,const Vector2& position, float size = 20, const Color& color = WHITE) :
		Shape(position, size, color),
		m_texture{ texture }
	{

	}


	void Update() override;
	void Draw() override;
	Type GetType() override { return Type::Image; }

protected:
	Texture2D m_texture;
};

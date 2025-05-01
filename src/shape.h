#pragma once

#include "raylib.h"

class Shape {
public:
	enum class Type {
		Circle,
		Square,
		Image,
		Triangle,
		Brush,
		NumShapes
	};
public:
	Shape() = default;
	Shape(const Vector2& position, float size = 20, const Color& color = WHITE) :
		m_position{ position },
		m_size{ size },
		m_color{ color }
	{

	}
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual Type GetType() = 0;

	const Vector2& GetPosition() const { return m_position; }
	void SetPostion(const Vector2& position)  { m_position = position; }

	float GetSize() const { return m_size; }
	void SetSize(float size)  { m_size = size; }

	const Color& GetColor() const { return m_color; }
	void SetColor(const Color& color) { m_color = color; }
	virtual void SetRotation(float angle) { m_rotation = angle; }

protected:
	Vector2 m_position{ 0,0 };
	float m_size = 20;
	Color m_color = WHITE;
	float m_rotation =90.0f;
};

#include "triangle.h"
#include <cmath>
void Triangle::Update()
{
}

void Triangle::Draw()
{
	// Equilateral triangle points
	float halfSize = m_size / 2.0f;
	float height = halfSize * sqrtf(3.0f);

	Vector2 p1 = { m_position.x, m_position.y - (2.0f / 3.0f) * height };
	Vector2 p2 = { m_position.x - halfSize, m_position.y + (1.0f / 3.0f) * height };
	Vector2 p3 = { m_position.x + halfSize, m_position.y + (1.0f / 3.0f) * height };



	DrawTriangle(p1, p2, p3, m_color);
}


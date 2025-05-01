#include "brush.h"

Brush::Brush(Color color)
{
	m_color = color;
}

void Brush::Draw()
{
	if (m_points.size() < 2) return;

	for (size_t i = 0; i < m_points.size() - 1; i++) {
		DrawLineV(m_points[i], m_points[i + 1], m_color);
	}

}

void Brush::Update()
{
	if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
		m_points.push_back(GetMousePosition());
	}
}

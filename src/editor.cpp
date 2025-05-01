#include "editor.h"
#include "square.h"
#include "Circle.h"
#include "Image.h"
#include "triangle.h"
#include "brush.h"
#include <iostream>
using namespace std;

Editor::Editor()
{
	m_textures.push_back(LoadTexture("wabbit_alpha.png"));
	m_shape = Create(m_type);
}

Editor::~Editor()
{
	ClearAll();
	delete m_shape;
}

void Editor::Draw()
{



	// Draw current shape
	const char* shapeName = "";

	switch (m_type) {
	case Shape::Type::Circle:   shapeName = "Circle"; break;
	case Shape::Type::Square:   shapeName = "Square"; break;
	case Shape::Type::Triangle: shapeName = "Triangle"; break;
	case Shape::Type::Image:    shapeName = "Image"; break;
	case Shape::Type::Brush:    shapeName = "Brush"; break;
	default:                    shapeName = "Unknown"; break;
	}

	DrawText(TextFormat("Shape: %s", shapeName), 10, 50, 20, WHITE);


	const char* rotateText = TextFormat("Rotation: %d", (int)m_rotate);
	DrawText(rotateText, 10, 220, 20, WHITE);

	const char* sizeText = TextFormat("Size: %d", (int)m_size);
	DrawText(sizeText, 10, 200, 20, WHITE);

	const char* clearText = "Press D To clear all";
	DrawText(clearText, 10, 130, 20, WHITE);

	const char* rotationText = "Press E & R to Rotate";
	DrawText(rotationText, 10, 150, 20, WHITE);

	const char* shapeText = "Press Tab to switch shapes";
	DrawText(shapeText, 10, 170, 20, WHITE);


	//Draw editor shapes
	for (auto shape : m_shapes) {
		shape->Draw();
	}
	//draw current shape
	m_shape->Draw();
}

void Editor::Update()
{
	//Scale Shape
	if (IsKeyDown(KEY_RIGHT)) {
		m_size += 1.5f;
		m_size = std::min(m_size, 100.0f);
	}

	if (IsKeyDown(KEY_LEFT)) {
		m_size -= 1.5f;
		m_size = std::max(m_size,1.0f);
	}
	m_shape->SetSize(m_size);



	if (IsKeyDown(KEY_R)) {
		m_rotate += 5.0f; // Rotate clockwise
		if (m_rotate > 360.0f) m_rotate -= 360.0f;
	}

	if (IsKeyDown(KEY_E)) {
		m_rotate -= 5.0f; // Rotate counter-clockwise
		if (m_rotate < 0.0f) m_rotate += 360.0f;
	}

	// Apply rotation to current shape
	m_shape->SetRotation(m_rotate);




	if(IsKeyPressed(KEY_UP)){
		m_colorIndex++;
		m_colorIndex = m_colorIndex % m_colors.size();
		m_shape->SetColor(m_colors[m_colorIndex]);
	}

	if (IsKeyPressed(KEY_TAB)) {
		m_type = static_cast<Shape::Type>((static_cast<int>(m_type) +1) % static_cast<int>(Shape::Type::NumShapes));
		delete m_shape;
		m_shape = Create(m_type);
	}

	if (m_type != Shape::Type::Brush &&
		(IsMouseButtonPressed(0) || (IsMouseButtonDown(0) && IsKeyDown(KEY_LEFT_CONTROL)))) {
		m_shapes.push_back(m_shape);
		m_shape = Create(m_type);
	}
	else if (m_type == Shape::Type::Brush && IsMouseButtonReleased(0)) {
		m_shapes.push_back(m_shape);
		m_shape = Create(m_type);
	}

	if (IsKeyPressed(KEY_D)) {
		ClearAll();
	}

	m_shape->SetPostion(GetMousePosition());
	//update editor shapes
	for (auto shape : m_shapes) {
		shape->Update();
	}
	m_shape->Update();





}

Shape* Editor::Create(Shape::Type type)
{
	Shape* shape = nullptr;

	switch (type)
	{
	case Shape::Type::Circle:
		shape = new Circle(GetMousePosition(), m_size, m_colors[m_colorIndex]);
		break;
	case Shape::Type::Square:
		shape = new Square(GetMousePosition(), m_size, m_colors[m_colorIndex]);
		break;
	case Shape::Type::Image:
		shape = new ImageShape(m_textures[m_textureIndex],GetMousePosition(),m_size,m_colors[m_colorIndex]);
			break;
	case Shape::Type::Triangle:
		shape = new Triangle(GetMousePosition(), m_size, m_colors[m_colorIndex]);
		break;
	case Shape::Type::Brush:
		shape = new Brush(m_colors[m_colorIndex]);
		break;
	default:
		break;
	}


	return shape;
}

void Editor::ClearAll()
{
	for (auto shape : m_shapes) {
		delete shape;
	}
	m_shapes.clear();
}

#pragma once
#include "shape.h"
#include <vector>
#include <array>


class Editor{
public:
	Editor();

	~Editor();


	void Draw();
	void Update();

private:
	Shape* Create(Shape::Type type);
	void ClearAll();



private:
	float m_rotate;
	float m_size = 20;
	Shape::Type m_type = Shape::Type::Circle;
	const std::array< Color ,3> m_colors = { WHITE,BLUE,GREEN };
	int m_colorIndex = 0;

	//textures

	std::vector<Texture2D> m_textures;
	int m_textureIndex;

	Shape* m_shape = nullptr;
	std::vector<Shape*> m_shapes;



};

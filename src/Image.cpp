#include "Image.h"

void ImageShape::Update()
{
}

void ImageShape::Draw()
{
	DrawTextureEx(m_texture, m_position,0,m_size, m_color);


	Rectangle src{ 0,0,m_texture.width,m_texture.height };
	Rectangle dest{ m_position.x,m_position.y,m_size,m_size };

	DrawTexturePro(m_texture, src, dest, Vector2{ m_texture.width / 2.0f,m_texture.height / 2.0f },0 , m_color);

}

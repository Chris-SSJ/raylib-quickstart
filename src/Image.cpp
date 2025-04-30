#include "Image.h"

void ImageShape::Update()
{
}

void ImageShape::Draw()
{
	//DrawTextureEx(m_texture, m_position,0,m_size, m_color);


	Rectangle src{ 0,0,m_texture.width,m_texture.height };
	Rectangle dest{ m_position.x,m_position.y,m_size,m_size };

	DrawTexturePro(m_texture,src,dest, Vector2{ m_size / 2, m_size / 2 }, m_rotation,m_color);

}

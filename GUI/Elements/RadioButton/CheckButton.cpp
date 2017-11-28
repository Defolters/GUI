#include "CheckButton.h"

CheckButton::CheckButton(RenderWindow * renderWindow_, float x, float y, float width, float height, GUIStyle *gstyle)
	:GUIBox(renderWindow_, x, y, width, height, gstyle)
{
	for (auto& border : frames)
		border.setColor(Color::Transparent);
}


CheckButton::~CheckButton()
{
}

void CheckButton::setActive()
{
	sprite.setTexture(gstyle->pressTex);
	active = true;

}

void CheckButton::setDeactive()
{
	sprite.setTexture(gstyle->mainTex);
	active = false;
}

bool CheckButton::contain(Vector2f pos)
{
	if (sprite.getGlobalBounds().contains(pos))
		return true;
	else
		return false;
}

void CheckButton::Draw()
{
	GUIBox::Draw();
}
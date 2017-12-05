#include "GUICheckButton.h"

GUICheckButton::GUICheckButton(GUILayer * layer_, RenderWindow * renderWindow_, float x, float y, float width, float height, std::string text, TextStyle * tstyle, GUIStyle * gstyle, void(*action)())
	: GUIButton(layer_, renderWindow_, x, y, width, height, text, tstyle, gstyle, action)
{
}

GUICheckButton::~GUICheckButton()
{
}

bool GUICheckButton::GetState()
{
	return clicked;
}

void GUICheckButton::handleEvent(const sf::Event & event)
{
	if (event.type == sf::Event::MouseMoved)
	{
		if (!clicked)
		{
			if (sprite.getGlobalBounds().contains(Vector2f(event.mouseMove.x, event.mouseMove.y)))
			{
				if (!entered)
				{
					entered = true;
					sprite.setTexture(gstyle->overTex);
					GUIBox::Recalc();
				}
			}
			else
			{
				if (entered)
				{
					entered = false;
					sprite.setTexture(gstyle->mainTex);
					GUIBox::Recalc();
				}
			}
		}
		/*else
			if (!sprite.getGlobalBounds().contains(Vector2f(event.mouseMove.x, event.mouseMove.y)))
			{
				sprite.setTexture(gstyle->mainTex);
				entered = false;
				clicked = false;
				GUIBox::Recalc();
			}*/
	}
	if (event.type == sf::Event::MouseButtonPressed)
		if (event.mouseButton.button == Mouse::Left)
		{
			if (sprite.getGlobalBounds().contains(Vector2f(event.mouseButton.x, event.mouseButton.y)))
			{
				if (!clicked)
					action();
				clicked = !clicked;
				if (clicked)
					sprite.setTexture(gstyle->pressTex);
				else
					sprite.setTexture(gstyle->overTex);
				GUIBox::Recalc();
			}
		}
	if (event.type == sf::Event::MouseButtonReleased)
		if (event.mouseButton.button == Mouse::Left)
		{
			if (!sprite.getGlobalBounds().contains(Vector2f(event.mouseButton.x, event.mouseButton.y)) && !clicked)
				sprite.setTexture(gstyle->mainTex);
			GUIBox::Recalc();
		}
}
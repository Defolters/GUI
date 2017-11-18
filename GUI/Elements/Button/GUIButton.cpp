#include "GUIButton.h"

GUIButton::GUIButton(RenderWindow* renderWindow_, float x, float y, float width, float height, std::string text_, TextStyle *Ctstyle, GUIStyle *Cgstyle, void(*Caction)()) : GUIBox(renderWindow_, x, y, width, height, text_, Ctstyle, Cgstyle)
{
	action = Caction;
	clicked = false;
}
GUIButton::GUIButton(RenderWindow* renderWindow_, Vector2f position_, Vector2f size_, std::string text_, TextStyle *Ctstyle, GUIStyle *Cgstyle, void(*Caction)()) : GUIBox(renderWindow_, position_, size_, text_, Ctstyle, Cgstyle)
{
	action = Caction;
	clicked = false;
}
GUIButton::GUIButton(RenderWindow* renderWindow_, Vector2f position_, float width, float height, std::string text_, TextStyle *Ctstyle, GUIStyle *Cgstyle, void(*Caction)()) : GUIBox(renderWindow_, position_, width, height, text_, Ctstyle, Cgstyle)
{
	action = Caction;
	clicked = false;
}
GUIButton::GUIButton(RenderWindow* renderWindow_, float x, float y, Vector2f size_, std::string text_, TextStyle *Ctstyle, GUIStyle *Cgstyle, void(*Caction)()) : GUIBox(renderWindow_, x, y, size_, text_, Ctstyle, Cgstyle)
{
	action = Caction;
	clicked = false;
}

void GUIButton::handleEvent(const sf::Event & event)
{

}


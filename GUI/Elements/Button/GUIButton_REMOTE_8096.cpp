#include "GUIButton.h"
#include "../../GUI/GUILayer.h"
GUIButton::GUIButton(GUILayer* layer_, RenderWindow* renderWindow_, float x, float y, float width, float height, std::string text_, TextStyle *Ctstyle, GUIStyle *Cgstyle, void(*Caction)()) : GUIBox(renderWindow_, x, y, width, height, Cgstyle)
{
	auto label = layer_->CreateLabel(Vector2f(x, y), Vector2f(width, height), text_, Ctstyle, Cgstyle);
	AddElement(label);
	action = Caction;
	clicked = false;
	entered = false;
}
GUIButton::GUIButton(GUILayer* layer_, RenderWindow* renderWindow_, Vector2f position_, Vector2f size_, std::string text_, TextStyle *Ctstyle, GUIStyle *Cgstyle, void(*Caction)()) : GUIBox(renderWindow_, position_, size_, Cgstyle)
{
	auto label = layer_->CreateLabel(position_, size_, text_, Ctstyle, Cgstyle);
	AddElement(label);
	action = Caction;
	clicked = false;
	entered = false;
}
GUIButton::GUIButton(GUILayer* layer_, RenderWindow* renderWindow_, Vector2f position_, float width, float height, std::string text_, TextStyle *Ctstyle, GUIStyle *Cgstyle, void(*Caction)()) : GUIBox(renderWindow_, position_, width, height, Cgstyle)
{
	auto label = layer_->CreateLabel(position_, Vector2f(width, height), text_, Ctstyle, Cgstyle);
	AddElement(label);
	action = Caction;
	clicked = false;
	entered = false;
}
GUIButton::GUIButton(GUILayer* layer_, RenderWindow* renderWindow_, float x, float y, Vector2f size_, std::string text_, TextStyle *Ctstyle, GUIStyle *Cgstyle, void(*Caction)()) : GUIBox(renderWindow_, x, y, size_, Cgstyle)
{
	auto label = layer_->CreateLabel(Vector2f(x, y), size_, text_, Ctstyle, Cgstyle);
	AddElement(label);
	action = Caction;
	clicked = false;
	entered = false;
}


void GUIButton::handleEvent(const sf::Event & event)
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
		else
			if (!sprite.getGlobalBounds().contains(Vector2f(event.mouseMove.x, event.mouseMove.y)))
			{
				sprite.setTexture(gstyle->mainTex);
				entered = false;
				clicked = false;
				GUIBox::Recalc();
			}
	}
	if (event.type == sf::Event::MouseButtonPressed)
		if (event.mouseButton.button == Mouse::Left)
		{
			if (sprite.getGlobalBounds().contains(Vector2f(event.mouseButton.x, event.mouseButton.y)))
			{
				action();
				clicked = true;
				sprite.setTexture(gstyle->pressTex);
				GUIBox::Recalc();
			}
		}
	if (event.type == sf::Event::MouseButtonReleased)
		if (event.mouseButton.button == Mouse::Left)
		{
			if (!sprite.getGlobalBounds().contains(Vector2f(event.mouseButton.x, event.mouseButton.y)))
				sprite.setTexture(gstyle->mainTex);
			else
				sprite.setTexture(gstyle->overTex);
			clicked = false;
			GUIBox::Recalc();
		}
}

void GUIButton::Draw()
{
	GUIBox::Draw();
	IDrawable::Draw();
}
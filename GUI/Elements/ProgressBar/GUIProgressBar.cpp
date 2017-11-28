#include "GUIProgressBar.h"


GUIProgressBar::GUIProgressBar(RenderWindow* renderWindow_, float x, float y, float width,
	float height, std::string text_, TextStyle *Ctstyle, GUIStyle *Cgstyle,
	float leftBorder, float rightBorder, Color staticBarColor, Color dynamicBarColor) :
	GUIBox(renderWindow_, x, y, width, height, Cgstyle),
	staticBar(new RectangleShape()), dynamicBar(new RectangleShape())
{
	tstyle = Ctstyle;
	text.setString(text_);
	text.setFont(tstyle->font);
	text.setCharacterSize(tstyle->fontSize);
	text.setFillColor(tstyle->color);
	text.setPosition((x + width / 2 - text.getGlobalBounds().width / 2), y + height);
	iconT = nullptr;
	icon = nullptr;

	leftBord = leftBorder;
	rightBord = rightBorder;
	timer = leftBord;

	staticBar->setPosition(x, y);
	staticBar->setSize(Vector2f(width, height));
	staticBar->setFillColor(staticBarColor);
	dynamicBar->setFillColor(dynamicBarColor);

	point = (width - 2) / rightBord;

	Recalc();
}


void GUIProgressBar::Recalc()
{
	Vector2f pos = GetPosition();
	Vector2f sz = GetSize();

	float posX = pos.x;
	float posY = pos.y;
	float width = sz.x;
	float height = sz.y;

	if (timer < width - 2);
	{
		dynamicBar->setPosition(posX + 1, posY + 1);
		dynamicBar->setSize(Vector2f(timer, height - 2));
	}
}

void GUIProgressBar::increase()
{
	if (timer < staticBar->getSize().x - 2)
	{
		timer += point;
	}
}

void GUIProgressBar::Draw()
{
	// Костыль для теста на время, пока нет Observer.
	Recalc();

	if (text.getString() != "")
	{
		renderWindow->draw(text);
	}
	if (icon != nullptr)
	{
		renderWindow->draw(*icon);
	}

	renderWindow->draw(*staticBar);
	renderWindow->draw(*dynamicBar);
}


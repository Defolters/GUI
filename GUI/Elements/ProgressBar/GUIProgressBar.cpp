#include "GUIProgressBar.h"
#include "../../GUI/GUILayer.h"

GUIProgressBar::GUIProgressBar(RenderWindow* renderWindow_, std::shared_ptr<GUILayer> _layer, float x, float y, float width,
	float height, std::string text_, TextStyle *Ctstyle, GUIStyle *Cgstyle,
	float _minValue, float _maxValue, Color staticBarColor, Color dynamicBarColor) :
	GUIBox(renderWindow_, x, y, width, height, Cgstyle),
	staticBar(new RectangleShape()), dynamicBar(new RectangleShape())
{
	layer = _layer;
	//float textWidth = static_cast<float>(text_.size());

	text.setString(text_);
	text.setFont(Ctstyle->font);
	text.setCharacterSize(Ctstyle->fontSize);
	text.setFillColor(Ctstyle->color);

	label = layer->CreateLabel(((x + width / 2) - (text.getGlobalBounds().width / 2)), y - height, text.getGlobalBounds().width, height / 2 , text_, Ctstyle, Cgstyle);
	iconT = nullptr;
	icon = nullptr;

	minValue = _minValue;
	maxValue = _maxValue;
	value = _minValue;

	staticBar->setPosition(x, y);
	staticBar->setSize(Vector2f(width, height));
	staticBar->setFillColor(staticBarColor);
	dynamicBar->setFillColor(dynamicBarColor);
	dynamicBar->setPosition(x + 1, y + 1);
	dynamicBar->setSize(Vector2f(value, height - 2));

	point = (width - 2) / _maxValue;

	Recalc();
}

void GUIProgressBar::setValue(float _value)
{
	Vector2f pos = GetPosition();
	Vector2f sz = GetSize();

	float posX = pos.x;
	float posY = pos.y;
	float width = sz.x;
	float height = sz.y;

	if (value < width - 2)
	{	
		value = _value * point;
		dynamicBar->setSize(Vector2f(value, height - 2));
	}
}


void GUIProgressBar::increase()
{
	if (value < staticBar->getSize().x - 2)
	{
		value += point;
	}
}

void GUIProgressBar::setText(const std::string & _text)
{
	char cstr[1000];
	strcpy_s(cstr, _text.c_str());
	label->SetText(cstr);
}

void GUIProgressBar::SetPosition(float x, float y)
{
	GUIBox::SetPosition(x, y);
	label->SetPosition(x, y);
	dynamicBar->setPosition(x + 1, y + 1);
	staticBar->setPosition(x, y);
}

void GUIProgressBar::SetPosition(Vector2f position_)
{
	GUIBox::SetPosition(position_);
	label->SetPosition(position_);
	dynamicBar->setPosition(position_.x + 1, position_.y + 1);
	staticBar->setPosition(position_.x, position_.y);
}

void GUIProgressBar::SetSize(float width, float height)
{
	GUIBox::SetSize(width, height);
	label->SetSize(width, height);
	staticBar->setSize(Vector2f(width, height));
	dynamicBar->setSize(Vector2f(value, height - 2));

	point = (width - 2) / maxValue;
}

void GUIProgressBar::SetSize(Vector2f size_)
{
	GUIBox::SetSize(size_);
	label->SetSize(size_);
	staticBar->setSize(Vector2f(size_.x, size_.y));
	dynamicBar->setSize(Vector2f(value, size_.y - 2));

	point = (size_.x - 2) / maxValue;
}

void GUIProgressBar::Recalc()
{
	Vector2f pos = GetPosition();
	Vector2f sz = GetSize();

	float posX = pos.x;
	float posY = pos.y;
	float width = sz.x;
	float height = sz.y;

	if (value < width - 2);
	{
		dynamicBar->setSize(Vector2f(value, height - 2));
	}
}

void GUIProgressBar::Draw()
{
	// Костыль для теста на время, пока нет Observer.
	Recalc();

	/*if (text.getString() != "")
	{
		renderWindow->draw(text);
	}
	if (icon != nullptr)
	{
		renderWindow->draw(*icon);
	}*/

	renderWindow->draw(*staticBar);
	renderWindow->draw(*dynamicBar);
}


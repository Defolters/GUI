#include "GUIBox.h"

GUIBox::GUIBox(RenderWindow* renderWindow_, float x, float y, float width, float height, std::string text_, TextStyle *Ñtstyle, GUIStyle *Cgstyle) : IDisplayable(renderWindow_, x, y, width, height)
{
	gstyle = Cgstyle;
	tstyle = Ñtstyle;
	text.setString(text_);
	text.setFont(tstyle->font);
	text.setCharacterSize(tstyle->fontSize);
	text.setFillColor(tstyle->color);
	Recalc();
}

GUIBox::GUIBox(RenderWindow* renderWindow_, Vector2f position_, Vector2f size_, std::string text_, TextStyle *Ñtstyle, GUIStyle *Cgstyle) : IDisplayable(renderWindow_, position_,size_)
{
	gstyle = Cgstyle;
	tstyle = Ñtstyle;
	text.setString(text_);
	text.setFont(tstyle->font);
	text.setCharacterSize(tstyle->fontSize);
	text.setFillColor(tstyle->color);
	Recalc();
}

GUIBox::GUIBox(RenderWindow* renderWindow_, float x, float y, Vector2f size_, std::string text_, TextStyle *Ñtstyle, GUIStyle *Cgstyle) : IDisplayable(renderWindow_, x, y, size_)
{
	gstyle = Cgstyle;
	tstyle = Ñtstyle;
	text.setString(text_);
	text.setFont(tstyle->font);
	text.setCharacterSize(tstyle->fontSize);
	text.setFillColor(tstyle->color);
	Recalc();
}

GUIBox::GUIBox(RenderWindow* renderWindow_, Vector2f position_, float width, float height, std::string text_, TextStyle *Ñtstyle, GUIStyle *Cgstyle) : IDisplayable(renderWindow_, position_, width, height)
{
	gstyle = Cgstyle;
	tstyle = Ñtstyle;
	text.setString(text_);
	text.setFont(tstyle->font);
	text.setCharacterSize(tstyle->fontSize);
	text.setFillColor(tstyle->color);
	Recalc();
}

void GUIBox::Recalc()
{
	Vector2f pos = GetPosition();
	Vector2f sz = GetSize();
	float posX = pos.x;
	float posY = pos.y;
	float width = sz.x;
	float height = sz.y;
	if (tstyle->align == 'c')
	{
		FloatRect textRect = text.getLocalBounds();
		text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
		text.setPosition(Vector2f(posX + (width / 2.0f), posY + (height / 2.0f)));
	}
	if (tstyle->align == 'l')
		text.setPosition(Vector2f(posX + 1, posY + 1));
	sprite.setTexture(gstyle->mainTex);
	sprite.setPosition(posX, posY);
	sprite.setTextureRect(IntRect(0, 0, width, height));
	for (int i = 0; i < 4; i++)
		frames[i].setTexture(gstyle->frame);
	frames[0].setTextureRect(IntRect(0, 0, gstyle->frameWid, width));
	frames[1].setTextureRect(IntRect(0, 0, gstyle->frameWid, width));
	frames[2].setTextureRect(IntRect(0, 0, gstyle->frameWid, height));
	frames[3].setTextureRect(IntRect(0, 0, gstyle->frameWid, height));
	frames[0].setPosition(posX, posY + gstyle->frameWid);
	frames[1].setPosition(posX, posY + height);
	frames[0].setRotation(-90);
	frames[1].setRotation(-90);
	frames[2].setPosition(posX, posY);
	frames[3].setPosition(posX + width - gstyle->frameWid, posY);
}

void GUIBox::SetPosition(Vector2f position_)
{
	IDisplayable::SetPosition(position_);
	Recalc();
}
void GUIBox::SetPosition(float x, float y)
{
	IDisplayable::SetPosition(x, y);
	Recalc();
}

void GUIBox::SetSize(Vector2f size_)
{
	IDisplayable::SetSize(size_);
	Recalc();
}
void GUIBox::SetSize(float width, float height)
{
	IDisplayable::SetSize(width, height);
	Recalc();
}

void GUIBox::SetGStyle(GUIStyle *Cgstyle)
{
	gstyle = Cgstyle;
	Recalc();
}
void GUIBox::SetTStyle(TextStyle *Ctstyle)
{
	tstyle = Ctstyle;
	Vector2f pos = GetPosition();
	Vector2f sz = GetSize();
	float posX = pos.x;
	float posY = pos.y;
	float width = sz.x;
	float height = sz.y;
	if (tstyle->align == 'c')
	{
		FloatRect textRect = text.getLocalBounds();
		text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
		text.setPosition(Vector2f(posX + (width / 2.0f), posY + (height / 2.0f)));
	}
	if (tstyle->align == 'l')
		text.setPosition(Vector2f(posX + 1, posY + 1));
}

void GUIBox::SetText(char *Ctext)
{
	text.setString(Ctext);
}

void GUIBox::Draw()
{
	renderWindow->draw(sprite);
	renderWindow->draw(frames[0]);
	renderWindow->draw(frames[1]);
	renderWindow->draw(frames[2]);
	renderWindow->draw(frames[3]);
	renderWindow->draw(text);
}
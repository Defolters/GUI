﻿#include "GUIBox.h"

GUIBox::GUIBox(RenderWindow* renderWindow_, float x, float y, float width, float height, GUIStyle *Cgstyle) : IDisplayable(renderWindow_, x, y, width, height)
{
	gstyle = Cgstyle;
	sprite.setTexture(gstyle->mainTex);
	Recalc();
}

GUIBox::GUIBox(RenderWindow* renderWindow_, Vector2f position_, Vector2f size_, GUIStyle *Cgstyle) : IDisplayable(renderWindow_, position_,size_)
{
	gstyle = Cgstyle;
	sprite.setTexture(gstyle->mainTex);
	Recalc();
}

GUIBox::GUIBox(RenderWindow* renderWindow_, float x, float y, Vector2f size_, GUIStyle *Cgstyle) : IDisplayable(renderWindow_, x, y, size_)
{
	gstyle = Cgstyle;
	sprite.setTexture(gstyle->mainTex);
	Recalc();
}

GUIBox::GUIBox(RenderWindow* renderWindow_, Vector2f position_, float width, float height, GUIStyle *Cgstyle) : IDisplayable(renderWindow_, position_, width, height)
{
	gstyle = Cgstyle;
	sprite.setTexture(gstyle->mainTex);
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
    if (resizing == false)
    {
        for (auto& elem : elements)
        {
            elem->SetPosition(position_);
        }
    }
    resizing = false;
	Recalc();
}
void GUIBox::SetPosition(Vector2f position_, Vector2f coefficient_)
{
    resizing = true;
    SetPosition(Vector2f(position.x * coefficient_.x, position.y * coefficient_.y));
    for (auto& elem : elements)
    {
        elem->SetPosition(position_, coefficient_);
        //elem->SetPosition(Vector2f(elem->GetPosition().x * coefficient_.x, elem->GetPosition().y * coefficient_.y));
    }
    Recalc();
    /*IDisplayable::SetPosition(Vector2f(position.x * coefficient_.x, position.y * coefficient_.y));
    for (auto& elem : elements)
    {
        elem->SetPosition(position_, coefficient_);
    }
    Recalc();*/
}
void GUIBox::SetPosition(float x, float y)
{
    SetPosition(Vector2f(x, y));
}

void GUIBox::SetSize(Vector2f size_)
{
	IDisplayable::SetSize(size_);
    if (resizing == false)
    {
        for (auto& elem : elements)
        {
            elem->SetSize(size_);
        }
    }
    resizing = false;
	Recalc();
}

void GUIBox::SetSize(Vector2f size_, Vector2f coefficient_)
{
    resizing = true;
    SetSize(Vector2f(size.x * coefficient_.x, size.y * coefficient_.y));
    for (auto& elem : elements)
    {
        elem->SetSize(size_, coefficient_);
        //elem->SetSize(Vector2f(elem->GetSize().x * coefficient_.x, elem->GetSize().y * coefficient_.y));
    }
    Recalc();
}

void GUIBox::SetSize(float width, float height)
{
    SetSize(Vector2f(width, height));
}

void GUIBox::SetGStyle(GUIStyle *Cgstyle)
{
	gstyle = Cgstyle;
	Recalc();
}

void GUIBox::Draw()
{
    Recalc();
	renderWindow->draw(sprite);
	renderWindow->draw(frames[0]);
	renderWindow->draw(frames[1]);
	renderWindow->draw(frames[2]);
	renderWindow->draw(frames[3]);
}
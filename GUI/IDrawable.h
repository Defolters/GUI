#pragma once
#include <SFML/Graphics.hpp>
#include "Observer.h"
//FOR DEBUG ONLY
#include <iostream>
using namespace sf;

//Элементы интерфейса НЕ ДОЛЖНЫ наследовать от этого класса
//им надо наследовать от IDisplayable если это композиция
//и от GUIBox если это одиночный элемент
//подробнее см. GUIBox.h
class IDrawable abstract : Observer
{
public:
	//Геттеры/сеттеры позиции и размера. счет идет от верхнего левого угла эелемента.
	//Позиция относительно GUILayer в котором находится элемент, а не окна!
	//для большей информации см. GUIlayer,h
	virtual void SetPosition(float x, float y);
	virtual void SetPosition(Vector2f position_);
	virtual void SetSize(float width, float height);
	virtual void SetSize(Vector2f size_);
	Vector2f GetSize();
	Vector2f GetPosition();
	//Функция отрисовки
	//КАЖДЫЙ элемент интерфейса должен переопределять ее по своему
	//но главное - в этой функции он должен отрисовывать свой Sprite в RenderWindow
	//для большей информации см. IDisplayable.h
	virtual void Draw() = 0;
	//Конструкторы, сначала позиция (x,y)
	//потом размер (ширина, высота)
	IDrawable(float, float, float, float);
	IDrawable(Vector2f, float, float);
	IDrawable(float, float, Vector2f);
	IDrawable(Vector2f, Vector2f);
	~IDrawable();
protected:
	//размер и позиция
	Vector2f size;
	Vector2f position;
};


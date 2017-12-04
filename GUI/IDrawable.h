#pragma once
#include <memory>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include "Observer.h"
#include "UIDGenerator.h"
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
	virtual void SetValue(Vector2f value_);
	Vector2f GetSize();
	Vector2f GetPosition();
	Vector2f GetValue();
	int GetID();
	std::shared_ptr<IDrawable> GetElement(int);
	//Функция отрисовки
	//КАЖДЫЙ элемент интерфейса должен переопределять ее по своему
	//но главное - в этой функции он должен отрисовывать свой Sprite в RenderWindow
	//для большей информации см. IDisplayable.h
	virtual void Draw();
	virtual void DrawforScr(RenderWindow *swindow);
	//Конструкторы, сначала позиция (x,y)
	//потом размер (ширина, высота)
	IDrawable();
	IDrawable(float, float, float, float);
	IDrawable(Vector2f, float, float);
	IDrawable(float, float, Vector2f);
	IDrawable(Vector2f, Vector2f);
	~IDrawable();

	//ВИРТУАЛЬНЫЙ ОБРАБОТЧИК СОБЫТИЙ!
	//Его надо перегружать и в нем все обрабатывать
	//Пример как есть в GUIBox.h (он там закомменчен)
	virtual void handleEvent(const sf::Event& event) {};
	virtual void AddElement(std::shared_ptr<IDrawable>);
protected:
	int id;
	IDrawable* parent;
	//вектора элементов на этом слое
	//в CreateElement() методах для своих элементов добавляйте share_ptr на свои элементы в этот вектор
	//пусть ваш элемент - elementType
	//тогда в CreateElementType()
	//в конце пишите 
	//elements.push_back(тут_shared_ptr_на ваш элемент);
	//return тут_shared_ptr_на_ваш_элемент;
	std::vector<std::shared_ptr<IDrawable>> elements;
	//размер и позиция
	Vector2f size;
	Vector2f position;
	Vector2f value;
};


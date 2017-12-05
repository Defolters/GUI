#pragma once
#include <memory>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include "Observer.h"
#include "UIDGenerator.h"
//FOR DEBUG ONLY
#include <iostream>
using namespace sf;

/*!
\brief Базовый класс рисуемых объектов

Базовый абстрактный класс рисуемых объектов, предоставляет функции работы с размером и позицией, методы отрисовки и пр.
*/
class IDrawable abstract : Observer
{
public:
	/*!
	\brief Устанавливает позицию
	\param x х-координата
	\param y y-координата
	*/
	virtual void SetPosition(float x, float y);
	/*!
	\brief Устанавливает позицию
	\param position_ позиция
	*/
	virtual void SetPosition(Vector2f position_);
  virtual void SetPosition(Vector2f size_, Vector2f coefficient_);
	/*!
	\brief Устанавливает размер
	\param width ширина
	\param height высота
	*/
	virtual void SetSize(float width, float height);
	/*!
	\brief Устанавливает размер
	\param size_ размер
	*/
	virtual void SetSize(Vector2f size_);
  virtual void SetSize(Vector2f size_, Vector2f coefficient_);
	/*!
	\brief Устанавливает значение отображения
	\param x value_ значение
	*/
	virtual void SetValue(Vector2f value_);

	//! Получить размер
	Vector2f GetSize();
	//! Получить позицию
	Vector2f GetPosition();
	//! Получить значение отображения
	Vector2f GetValue();
	//! Получить ID
	int GetID();
	/*!
	\brief Получить указатель на дочерний элемент
	\param id id искомого элемента
	*/
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
	/*!
	\brief Конструктор класса

	\param x х-координата
	\param y y-координата
	\param width ширина
	\param height высота

	*/
	IDrawable(float, float, float, float);
	/*!
	\brief Конструктор класса

	\param position_ позиция
	\param width ширина
	\param height высота

	*/
	IDrawable(Vector2f, float, float);
	/*!
	\brief Конструктор класса

	\param x х-координата
	\param y y-координата
	\param size_ размер

	*/
	IDrawable(float, float, Vector2f);
	/*!
	\brief Конструктор класса

	\param position_ позиция
	\param size_ размер

	*/
	IDrawable(Vector2f, Vector2f);
	~IDrawable();

	/*!
	\brief обработчик событий
	\param event обрабатываемое событие
	*/
	virtual void handleEvent(const sf::Event& event);
	/*!
	\brief Метод добавления элемента
	\param element элемент который добавляем как дочерний
	*/
	virtual void AddElement(std::shared_ptr<IDrawable>);
protected:
	int id;//!< id элемента
	IDrawable* parent;//!< родитель элемента
	std::vector<std::shared_ptr<IDrawable>> elements;//!< вектора дочерних жлементов
	Vector2f size;//!< позиция
	Vector2f position;//!< размер
	Vector2f value;//!< значение
};

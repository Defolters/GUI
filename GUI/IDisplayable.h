#pragma once
#include "IDrawable.h"
//базовый класс сложных элементов
class IDisplayable abstract : public IDrawable
{
private:
	bool toDraw;//!< отвечает за то будет элемент рисоваться или нет
public:
	/*!
	\brief Узнать риуется ли элемент
	*/
	virtual bool GetDrawState();
	/*!
	\brief Устанавливает отрисовку
	\param state параметр отрисовки
	*/
	virtual void SetDrawState(bool);
	
	virtual bool IsClickedThrough();//TODO
	//virtual sf::Vector2f GetScreenSize() = 0;//TODO

protected:
	bool clicksThrough;//!< прокликивается ли элемент
	RenderWindow* renderWindow;//!< указатель на окно на котором он расположен
	/*!
	\brief Конструктор класса

	\param x х-координата
	\param y y-координата
	\param width ширина
	\param height высота

	*/
	IDisplayable(RenderWindow*, float, float, float, float);
	/*!
	\brief Конструктор класса

	\param position_ позиция
	\param width ширина
	\param height высота

	*/
	IDisplayable(RenderWindow*, Vector2f, float, float);
	/*!
	\brief Конструктор класса

	\param x х-координата
	\param y y-координата
	\param size_ размер

	*/
	IDisplayable(RenderWindow*, float, float, Vector2f);
	/*!
	\brief Конструктор класса

	\param position_ позиция
	\param size_ размер

	*/
	IDisplayable(RenderWindow*, Vector2f, Vector2f);
};

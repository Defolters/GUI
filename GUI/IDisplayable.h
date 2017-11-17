#pragma once
#include "IDrawable.h"

//базовый класс сложных элементов
class IDisplayable abstract : public IDrawable
{
private:
	//отвечает за то будет элемент рисоваться или нет
	bool toDraw;
public:
	//позволяет получить toDraw
	virtual bool GetDrawState();
	//позволяет назначить toDraw
	virtual void SetDrawState(bool);
	//проверка на то прокликивается ли элемент мышкой, нужно для event
	virtual bool IsClickedThrough();//пока не думаем об этом
	//virtual sf::Vector2i GetScreenSize() = 0;//TODO
	//TODO events
protected:
	bool clicksThrough;
	//указатель на окно в которое надо рисовать
	RenderWindow* renderWindow;
	IDisplayable(RenderWindow*, float, float, float, float);
	IDisplayable(RenderWindow*, Vector2f, float, float);
	IDisplayable(RenderWindow*, float, float, Vector2f);
	IDisplayable(RenderWindow*, Vector2f, Vector2f);
};


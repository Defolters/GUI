#pragma once
#include "IDrawable.h"
//базовый класс сложных элементов
class IDisplayable abstract : public IDrawable
{
private:
	//std::vector<std::shared_ptr<IDrawable>> elements;
	//отвечает за то будет элемент рисоваться или нет
	bool toDraw;
public:
	//позволяет получить toDraw
	virtual bool GetDrawState();
	//позволяет назначить toDraw
	virtual void SetDrawState(bool);
	virtual bool IsClickedThrough();//пока не думаем об этом
	//virtual sf::Vector2f GetScreenSize() = 0;//TODO

protected:
	bool clicksThrough;
	//указатель на окно в которое надо рисовать
	RenderWindow* renderWindow;
	IDisplayable(RenderWindow*, float, float, float, float);
	IDisplayable(RenderWindow*, Vector2f, float, float);
	IDisplayable(RenderWindow*, float, float, Vector2f);
	IDisplayable(RenderWindow*, Vector2f, Vector2f);
};


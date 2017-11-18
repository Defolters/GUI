#pragma once
#include "IDrawable.h"

//базовый класс сложных элементов
class IDisplayable abstract : public IDrawable
{
private:
	//отвечает за то будет элемент рисоватьс€ или нет
	bool toDraw;
public:
	//позвол€ет получить toDraw
	virtual bool GetDrawState();
	//позвол€ет назначить toDraw
	virtual void SetDrawState(bool);
	virtual bool IsClickedThrough();//пока не думаем об этом
	//virtual sf::Vector2f GetScreenSize() = 0;//TODO

	//¬»–“”јЋ№Ќџ… ќЅ–јЅќ“„»  —ќЅџ“»…!
	//≈го надо перегружать и в нем все обрабатывать
	//ѕример как есть в GUIBox.h (он там закомменчен)
	virtual void handleEvent(const sf::Event& event) {};

protected:
	bool clicksThrough;
	//указатель на окно в которое надо рисовать
	RenderWindow* renderWindow;
	IDisplayable(RenderWindow*, float, float, float, float);
	IDisplayable(RenderWindow*, Vector2f, float, float);
	IDisplayable(RenderWindow*, float, float, Vector2f);
	IDisplayable(RenderWindow*, Vector2f, Vector2f);
};


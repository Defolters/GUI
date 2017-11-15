#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class IDisplayable abstract
{
private:
	bool toDraw;
public:
	virtual bool IsClickedThrough();
	virtual bool GetDrawState();
	virtual void SetDrawState(bool);
	//virtual sf::Vector2i GetScreenSize() = 0;//TODO

	virtual void SetPosition(float x, float y);
	virtual void SetPosition(Vector2f position_);
	virtual void SetSize(float width, float height);
	virtual void SetSize(Vector2f size_);
	Vector2f GetSize();
	Vector2f GetPosition();
	virtual void Draw() = 0;
protected:
	Vector2f size;
	Vector2f position;
	bool clicksThrough;
	RenderWindow* renderWindow;
	IDisplayable(RenderWindow*, float, float, float, float);
	IDisplayable(RenderWindow*, Vector2f, float, float);
	IDisplayable(RenderWindow*, float, float, Vector2f);
	IDisplayable(RenderWindow*, Vector2f, Vector2f);
};


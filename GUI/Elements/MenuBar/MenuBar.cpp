#include "MenuBar.h"



MenuBar::MenuBar(RenderWindow* renderWindow_, float x, float y, float width,
	float height, std::string text_, TextStyle *Ctstyle, GUIStyle *Cgstyle,
	float leftBorder, float rightBorder, Color staticBarColor, GUILayer* layer) :
	GUIBox(renderWindow_, x, y, width, height, Cgstyle),
	staticBar(new RectangleShape())
{
	this->layer = layer;
	iconT = nullptr;
	icon = nullptr;

	leftBord = leftBorder;
	rightBord = rightBorder;


	staticBar->setPosition(x, y);
	staticBar->setSize(Vector2f(width, height));
	staticBar->setFillColor(staticBarColor);


	
}


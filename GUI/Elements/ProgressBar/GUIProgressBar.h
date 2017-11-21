#pragma once
#include "../../GUI/GUIBox.h"
class GUIProgressBar : public GUIBox
{
private:
	friend class GUILayer;
	TextStyle *tstyle;
	Text text;
	Texture *iconT;
	Sprite *icon;

	RectangleShape * staticBar;
	RectangleShape * dynamicBar;

	float leftBord;
	float rightBord;

	float point;
	float timer;
protected:
	GUIProgressBar(RenderWindow* renderWindow_, float x, float y, float width, float height,
		std::string text, TextStyle *tstyle, GUIStyle *gstyle,
		float leftBorder, float rightBorder, Color staticBarColor, Color dynamicBarColor);

	virtual void Draw() override;
	virtual void Recalc() override;
public:
	void increase();
};


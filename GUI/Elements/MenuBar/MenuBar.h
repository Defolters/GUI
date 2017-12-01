#pragma once
#include "../../GUI/GUIBox.h"
#include <vector>
#include <string.h>
#include "../../Observable.h"

class MenuBar : public GUIBox 
{
private:
	std::vector<std::shared_ptr <GUIBox> > buttonVect;
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	int buttonPosHelp=0;
	GUILayer * layer;

	friend class GUILayer;
	TextStyle *tstyle;

	Text text;
	Texture *iconT;
	Sprite *icon;

	RectangleShape * staticBar;


	float leftBord;
	float rightBord;

	float point;

protected:
	MenuBar(RenderWindow* renderWindow_, float x, float y, float width, float height,
		std::string text, TextStyle *tstyle, GUIStyle *gstyle,
		float leftBorder, float rightBorder, Color staticBarColor, GUILayer* layer);

	//virtual void Draw() override;

public:
	

	void addButton(std::string name , void(*action)());
};


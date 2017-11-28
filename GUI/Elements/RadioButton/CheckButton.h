#pragma once
#include "../../GUI/GUIBox.h"
#include <memory>
#include <iostream>
class CheckButton: public GUIBox
{
public:
	CheckButton( RenderWindow* renderWindow_, float x, float y, float width, float height,  GUIStyle *gstyle);
	~CheckButton();
	void Draw() override;
	void setActive();
	void setDeactive();
	bool contain(Vector2f pos);
private:
	bool active = false;
};


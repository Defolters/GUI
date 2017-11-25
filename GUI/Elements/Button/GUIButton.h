#pragma once
#include "../../GUI/GUIBox.h"
class GUIButton : public GUIBox
{
private:
	friend class GUILayer;
	void(*action)();
	bool clicked;
	bool entered;
protected:
	GUIButton(RenderWindow* renderWindow_, float x, float y, float width, float height, std::string text, TextStyle *tstyle, GUIStyle *gstyle, void(*action)());
	GUIButton(RenderWindow* renderWindow_, Vector2f position_, Vector2f size_, std::string text, TextStyle *tstyle, GUIStyle *gstyle, void(*action)());
	GUIButton(RenderWindow* renderWindow_, Vector2f position_, float width, float height, std::string text, TextStyle *tstyle, GUIStyle *gstyle, void(*action)());
	GUIButton(RenderWindow* renderWindow_, float x, float y, Vector2f size_, std::string text, TextStyle *tstyle, GUIStyle *gstyle, void(*action)());

	void handleEvent(const sf::Event& event) override;
};


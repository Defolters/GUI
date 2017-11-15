#pragma once
#include "../General/Styles.hpp"
#include "../IDisplayable.h"
class GUIElement abstract : public IDisplayable
{
protected:
	GUIElement(RenderWindow* renderWindow_, float x, float y, float width, float height);
	GUIElement(RenderWindow* renderWindow_, Vector2f position_, Vector2f size_);
	GUIElement(RenderWindow* renderWindow_, Vector2f position_, float width, float height);
	GUIElement(RenderWindow* renderWindow_, float x, float y, Vector2f size_);
	void ChangeParam(float x, float y, float width, float height);
	void ChangeParam(Vector2f position_, Vector2f size_);
	void ChangeParam(float x, float y, Vector2f size_);
	void ChangeParam(Vector2f position_, float width, float height);
};
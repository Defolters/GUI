#include "GUIElement.h"

GUIElement::GUIElement(RenderWindow* renderWindow_, float x, float y, float width, float height) : IDisplayable(renderWindow_, x, y, width, height)
{}
GUIElement::GUIElement(RenderWindow* renderWindow_, Vector2f position_, Vector2f size_) : IDisplayable(renderWindow_, position_, size_)
{}
GUIElement::GUIElement(RenderWindow* renderWindow_, Vector2f position_, float width, float height) : IDisplayable(renderWindow_, position_, width, height)
{}
GUIElement::GUIElement(RenderWindow* renderWindow_, float x, float y, Vector2f size_) : IDisplayable(renderWindow_, x, y, size_)
{}

void GUIElement::ChangeParam(float x, float y, float width, float height)
{
	IDisplayable::SetPosition(x, y);
	IDisplayable::SetSize(width, height);
}

void GUIElement::ChangeParam(Vector2f position_, Vector2f size_)
{
	IDisplayable::SetPosition(position_);
	IDisplayable::SetSize(size_);
}
void GUIElement::ChangeParam(float x, float y, Vector2f size_)
{
	IDisplayable::SetPosition(x, y);
	IDisplayable::SetSize(size_);
}
void GUIElement::ChangeParam(Vector2f position_, float width, float height)
{
	IDisplayable::SetPosition(position_);
	IDisplayable::SetSize(width, height);
}

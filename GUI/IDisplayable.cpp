#include "IDisplayable.h"

bool IDisplayable::IsClickedThrough()
{
	return clicksThrough;
}

bool IDisplayable::GetDrawState()
{
	return toDraw;
}

void IDisplayable::SetDrawState(bool toDraw_)
{
	toDraw = toDraw_;
}

void IDisplayable::SetPosition(float x, float y)
{
	position.x = x;
	position.y = y;
}

void IDisplayable::SetPosition(Vector2f position_)
{
	position = position_;
}

void IDisplayable::SetSize(float width, float height)
{
	size.x = width;
	size.y = height;
}

void IDisplayable::SetSize(Vector2f size_)
{
	size = size_;
}

Vector2f IDisplayable::GetSize()
{
	return size;
}

Vector2f IDisplayable::GetPosition()
{
	return position;
}

IDisplayable::IDisplayable(RenderWindow* renderWindow_, float x, float y, float width, float height)
{
	renderWindow = renderWindow_;
	position.x = x;
	position.y = y;
	size.x = width;
	size.y = height;
	toDraw = true;
}

IDisplayable::IDisplayable(RenderWindow* renderWindow_, Vector2f position_, float width, float height)
{
	renderWindow = renderWindow_;
	position = position_;
	size.x = width;
	size.y = height;
	toDraw = true;
}

IDisplayable::IDisplayable(RenderWindow* renderWindow_, float x, float y , Vector2f size_)
{
	renderWindow = renderWindow_;
	position.x = x;
	position.y = y;
	size = size_;
	toDraw = true;
}

IDisplayable::IDisplayable(RenderWindow* renderWindow_, Vector2f position_, Vector2f size_)
{
	renderWindow = renderWindow_;
	position = position_;
	size = size_;
	toDraw = true;
}

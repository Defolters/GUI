#include "IDrawable.h"

void IDrawable::SetPosition(float x, float y)
{
	position.x = x;
	position.y = y;
}

void IDrawable::SetPosition(Vector2f position_)
{
	position = position_;
}

void IDrawable::SetSize(float width, float height)
{
	size.x = width;
	size.y = height;
}

void IDrawable::SetSize(Vector2f size_)
{
	size = size_;
}

Vector2f IDrawable::GetSize()
{
	return size;
}

Vector2f IDrawable::GetPosition()
{
	return position;
}

IDrawable::IDrawable(float x, float y, float width, float height)
{
	position.x = x;
	position.y = y;
	size.x = width;
	size.y = height;
}

IDrawable::IDrawable(Vector2f position_, float width, float height)
{
	position = position_;
	size.x = width;
	size.y = height;
}

IDrawable::IDrawable(float x, float y, Vector2f size_)
{
	position.x = x;
	position.y = y;
	size = size_;
}

IDrawable::IDrawable(Vector2f position_, Vector2f size_)
{
	position = position_;
	size = size_;
}

IDrawable::~IDrawable()
{
}

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

void IDrawable::Draw()
{
	for (auto& element : elements)
		element->Draw();
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

void IDrawable::AddElement(std::shared_ptr<IDrawable> element)
{
	auto position = std::find_if(element->parent->elements.begin(), element->parent->elements.end(),
		[element](std::shared_ptr<IDrawable> const& i)
	{ return i.get() == element.get(); });
	if (position != element->parent->elements.end())
		element->parent->elements.erase(position);
	element->parent = this;
	elements.push_back(element);
}

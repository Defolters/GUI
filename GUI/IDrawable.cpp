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

void IDrawable::SetPosition(Vector2f position_, Vector2f coefficient_)
{
    position.x = position.x * coefficient_.x;
    position.y = position.y * coefficient_.y;
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


void IDrawable::SetValue(Vector2f value_)
{
	value = value_;
}

void IDrawable::SetSize(Vector2f size_, Vector2f coefficient_)
{
    size.x = size.x * coefficient_.x;
    size.y = size.y * coefficient_.y;
}

Vector2f IDrawable::GetSize()
{
	return size;
}

Vector2f IDrawable::GetPosition()
{
	return position;
}

Vector2f IDrawable::GetValue()
{
	return value;
}

int IDrawable::GetID()
{
	return id;
}

std::shared_ptr<IDrawable> IDrawable::GetElement(int id)
{
	auto position = std::find_if(elements.begin(), elements.end(),
		[id](std::shared_ptr<IDrawable> const& element)
	{return id == element->GetID(); });
	if (position != elements.end())
		return *position;
	else
		return std::shared_ptr<IDrawable>(nullptr);
}

void IDrawable::Draw()
{
	for (auto& element : elements)
		element->Draw();
}

void IDrawable::DrawforScr(RenderWindow *swindow) 
{
}

IDrawable::IDrawable()
{
	id = UIDGenerator::Instance().GenerateID();
	position.x = 0;
	position.y = 0;
	size.x = 0;
	size.y = 0;
}

IDrawable::IDrawable(float x, float y, float width, float height)
{
	id = UIDGenerator::Instance().GenerateID();
	position.x = x;
	position.y = y;
	size.x = width;
	size.y = height;
}

IDrawable::IDrawable(Vector2f position_, float width, float height)
{
	id = UIDGenerator::Instance().GenerateID();
	position = position_;
	size.x = width;
	size.y = height;
}

IDrawable::IDrawable(float x, float y, Vector2f size_)
{
	id = UIDGenerator::Instance().GenerateID();
	position.x = x;
	position.y = y;
	size = size_;
}

IDrawable::IDrawable(Vector2f position_, Vector2f size_)
{
	id = UIDGenerator::Instance().GenerateID();
	position = position_;
	size = size_;
}

IDrawable::~IDrawable()
{
}

void IDrawable::handleEvent(const sf::Event & event)
{
	for (auto& element : elements)
		element->handleEvent(event);
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

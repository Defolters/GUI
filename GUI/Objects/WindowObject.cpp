#include "Windowobject.h"

WindowObject::WindowObject(RenderWindow* renderWindow_, Texture * src, Vector2f size_, Vector2f position_) : Object(renderWindow_, src, size_, position_)
{
	sprite.setTexture(*source);
	sprite.setPosition(position_);
	sprite.setScale(size);
}

WindowObject::WindowObject(RenderWindow* renderWindow_, Texture * src, IntRect orig, Vector2f size_, Vector2f position_) : Object(renderWindow_, src, orig, size_, position_)
{
	sprite.setTexture(*source);
	sprite.setPosition(position_);
	sprite.setScale(size);
}

WindowObject::WindowObject(RenderWindow* renderWindow_, Texture * src, IntRect orig, Vector2f size_, Vector2f position_, int frm, float leng) : Object(renderWindow_, src, orig, size_, position_, frm, leng)
{
	sprite.setTexture(*source);
	sprite.setPosition(position_);
	sprite.setScale(size);
}

void WindowObject::SetPosition(int x, int y)
{
	Object::SetPosition(x, y);
	sprite.setPosition(x, y);
}

void WindowObject::SetPosition(Vector2f position_)
{
	Object::SetPosition(position_);
	sprite.setPosition(position_);
}

void WindowObject::SetSize(int width, int height)
{
	Object::SetSize(width, height);
	sprite.setScale(width, height);
}

void WindowObject::SetSize(Vector2f size_)
{
	Object::SetSize(size_);
	sprite.setScale(size_);
}

void WindowObject::Draw()
{
	if (toDraw)
		renderWindow->draw(sprite);
}
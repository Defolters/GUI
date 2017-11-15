#include "Object.h"

Object::Object(RenderWindow* renderWindow_, Texture* src, Vector2f size_, Vector2f position_) : IDisplayable(renderWindow_, position_, size_)
{
	source = src;
	sprite.setTexture(*source);
}

Object::Object(RenderWindow* renderWindow_, Texture* src, IntRect orig, Vector2f size_, Vector2f position_) : IDisplayable(renderWindow_, position_, size_)
{
	source = src;
	sprite.setTexture(*source);
	sprite.setTextureRect(orig);
}

Object::Object(RenderWindow* renderWindow_, Texture* src, IntRect orig, Vector2f size_, Vector2f position_, int frames_, float leng) : IDisplayable(renderWindow_, position_, size_)
{
	source = src;
	sprite.setTexture(*source);
	sprite.setTextureRect(orig);
	cycled = true;
	frames = frames_;
	cycleLength = leng;
}

bool Object::SetRect(IntRect rectS)
{
	if (cycled)
		return false;
	else
	{
		sprite.setTextureRect(rectS);
		return true;
	}
}

bool Object::SetTexture(Texture* tex)
{
	if (cycled)
		return false;
	else
	{
		source = tex;
		sprite.setTexture(*source);
		return true;
	}
}

bool Object::SetCycle(float leng)
{
	IntRect rect = sprite.getTextureRect();
	if (frames > 1 && rect.width != 0 && rect.height != 0)
	{
		cycled = true;
		cycleLength = leng;
		return true;
	}
	else
		return false;
}

bool Object::SetCycle(Texture* tex, IntRect rectS, int frames_, float leng)
{
	frames = frames_;
	cycleLength = leng;
	sprite.setTextureRect(rectS);
	source = tex;
	sprite.setTexture(*source);
	cycled = true;
	return true;
}

IntRect Object::GetTextureRect()
{
	return sprite.getTextureRect();
}

Texture * Object::GetTexture()
{
	return source;
}

int Object::GetFrames()
{
	return frames;
}

float Object::GetCycleLength()
{
	return cycleLength;
}

Object::~Object()
{
}

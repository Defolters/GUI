#pragma once
#include <SFML/Graphics.hpp>
#include "../IDisplayable.h"
using namespace sf;

class Object abstract : public IDisplayable
{
public:
	bool SetRect(IntRect rect);
	bool SetTexture(Texture* tex);
	bool SetCycle(float leng);
	bool SetCycle(Texture* source, IntRect rect, int frames_, float leng);
	IntRect GetTextureRect();
	Texture* GetTexture();
	int GetFrames();
	float GetCycleLength();
	bool cycled = false;
	bool toDraw = true;
protected:
	int frames = 1;
	float cycleLength = 0;
	Texture* source;
	Sprite sprite;
	Object(RenderWindow* renderWindow_, Texture* src, Vector2f size_, Vector2f position_);
	Object(RenderWindow* renderWindow_, Texture* src, IntRect orig, Vector2f size_, Vector2f position_);
	Object(RenderWindow* renderWindow_, Texture* src, IntRect orig, Vector2f size_, Vector2f position_, int frames_, float leng);
	//TODO more constructors
	~Object();
};
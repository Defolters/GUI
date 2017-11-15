#pragma once
#include "Object.h"

class FieldObject : public Object
{
	friend class ObjectField;
public:
	bool invisible;
protected:
	void Draw() override;
	FieldObject(RenderWindow* renderWindow_, Texture* src, Vector2f size_, Vector2f position_);
	FieldObject(RenderWindow* renderWindow_, Texture* src, IntRect orig, Vector2f size_, Vector2f position_);
	FieldObject(RenderWindow* renderWindow_, Texture* src, IntRect orig, Vector2f size_, Vector2f position_, int frames_, float leng);
};
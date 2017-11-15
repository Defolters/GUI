#pragma once
#include "Object.h"

class WindowObject : public Object
{
	friend class WindowTab;
public:
	void SetPosition(int x, int y);
	void SetPosition(Vector2f position_);
	void SetSize(int width, int height);
	void SetSize(Vector2f size_);
private:
	void Draw() override;
	WindowObject(RenderWindow* renderWindow_, Texture* src, Vector2f size_, Vector2f position_);
	WindowObject(RenderWindow* renderWindow_, Texture* src, IntRect orig, Vector2f size_, Vector2f position_);
	WindowObject(RenderWindow* renderWindow_, Texture* src, IntRect orig, Vector2f size_, Vector2f position_, int frm, float leng);
};
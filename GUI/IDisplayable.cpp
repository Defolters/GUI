#include "IDisplayable.h"

bool IDisplayable::GetDrawState()
{
	return toDraw;
}

void IDisplayable::SetDrawState(bool toDraw_)
{
	toDraw = toDraw_;
}

bool IDisplayable::IsClickedThrough()
{
	return clicksThrough;
}

IDisplayable::IDisplayable(RenderWindow* renderWindow_, float x, float y, float width, float height) : IDrawable(x,y,width,height)
{
	renderWindow = renderWindow_;
	toDraw = true;
}

IDisplayable::IDisplayable(RenderWindow* renderWindow_, Vector2f position_, float width, float height) : IDrawable(position_, width, height)
{
	renderWindow = renderWindow_;
	toDraw = true;
}

IDisplayable::IDisplayable(RenderWindow* renderWindow_, float x, float y , Vector2f size_) : IDrawable(x, y, size_)
{
	renderWindow = renderWindow_;
	toDraw = true;
}

IDisplayable::IDisplayable(RenderWindow* renderWindow_, Vector2f position_, Vector2f size_) : IDrawable(position_, size_)
{
	renderWindow = renderWindow_;
	toDraw = true;
}
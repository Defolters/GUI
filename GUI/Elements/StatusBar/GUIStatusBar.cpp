#include "GUIStatusBar.h"

GUIStatusBar::GUIStatusBar(RenderWindow* renderWindow_, float height_, float frameSize_,
	float spacing_, GUIStyle *sBarStyle_, Location location_)
	: IDisplayable(renderWindow_, Vector2f(0, 0), Vector2f(0, height_)), statusBar(new RectangleShape()),
	sBarStyle(sBarStyle_), frameSize(frameSize_), spacing(spacing_), location(location_), width(height_)
{
	statusBar->setFillColor(sBarStyle->color);
	switch (location)
	{
	case Location::DOWNSIDE:
	{
		size.y = height_;
		size.x = renderWindow_->getSize().x;
		SetSize(renderWindow_->getSize().x, height_);
		statusBar->setPosition(0, renderWindow_->getSize().y - size.y);
		statusBar->setSize(Vector2f(size.x, size.y));
		break;
	}
	case Location::UPSIDE:
	{
		size.y = height_;
		size.x = renderWindow_->getSize().x;
		statusBar->setPosition(0, 0);
		statusBar->setSize(Vector2f(size.x, size.y));
		break;
	}
	case Location::RIGHT_SIDE:
	{
		size.x = height_;
		size.y = renderWindow_->getSize().y;
		statusBar->setSize(Vector2f(size.x, size.y));
		statusBar->setPosition(renderWindow_->getSize().x - size.x, 0);
		break;
	}
	case Location::LEFT_SIDE:
	{
		size.x = height_;
		size.y = renderWindow_->getSize().y;
		statusBar->setSize(Vector2f(size.x, size.y));
		statusBar->setPosition(0, 0);
		break;
	}
	}

}

void GUIStatusBar::setLocation(Location location_)
{
	location = location_;
	Recalc();
}

void GUIStatusBar::setSpacing(int spacing_)
{
	spacing = spacing_;
	Recalc();
}

void GUIStatusBar::setFrameSize(int frameSize_)
{
	frameSize = frameSize_;
	Recalc();
}

void GUIStatusBar::setHeight(int height_)
{
	width = height_;
	Recalc();
}

void GUIStatusBar::Draw()
{
	if (childCount != elements.size())
	{
		recalcElements();
	}
	renderWindow->draw(*statusBar);
	IDisplayable::Draw();
}

void GUIStatusBar::handleEvent(const sf::Event & event)
{
	IDrawable::handleEvent(event);
	switch(event.type)
	{
	case Event::Resized:
		Recalc();
		break;
	}
}

void GUIStatusBar::Recalc()
{
	switch (location)
	{
	case Location::DOWNSIDE:
	{
		size.y = width;
		size.x = renderWindow->getSize().x;
		position.x = 0;
		position.y = renderWindow->getSize().y - size.y;
		statusBar->setPosition(position.x, position.y);
		statusBar->setSize(Vector2f(size.x, size.y));
		break;
	}
	case Location::UPSIDE:
	{
		size.y = width;
		size.x = renderWindow->getSize().x;
		statusBar->setPosition(0, 0);
		statusBar->setSize(Vector2f(size.x, size.y));
		break;
	}
	case Location::RIGHT_SIDE:
	{
		size.x = width;
		size.y = renderWindow->getSize().y;
		statusBar->setSize(Vector2f(size.x, size.y));
		statusBar->setPosition(renderWindow->getSize().x - size.x, 0);
		break;
	}
	case Location::LEFT_SIDE:
	{
		size.x = width;
		size.y = renderWindow->getSize().y;
		statusBar->setSize(Vector2f(size.x, size.y));
		statusBar->setPosition(0, 0);
		break;
	}
	}

	recalcElements();

}

void GUIStatusBar::recalcElements()
{
	switch (location)
	{
	case Location::DOWNSIDE:
	{
		currPosition = 0;
		for (auto el = elements.begin(); el != elements.end(); ++el)
		{
			ratio = (*el)->GetSize().x / (*el)->GetSize().y;
			(*el)->SetSize((size.y - frameSize * 2) * ratio, size.y - frameSize * 2);
			currPosition += (*el)->GetSize().x + spacing;
			(*el)->SetPosition(renderWindow->getSize().x - currPosition, renderWindow->getSize().y - (*el)->GetSize().y - frameSize);
		}
		break;
	}
	case Location::UPSIDE:
	{
		currPosition = 0;
		for (auto el = elements.begin(); el != elements.end(); ++el)
		{
			ratio = (*el)->GetSize().x / (*el)->GetSize().y;
			(*el)->SetSize((size.y - frameSize * 2) * ratio, size.y - frameSize * 2);
			currPosition += (*el)->GetSize().x + spacing;
			(*el)->SetPosition(renderWindow->getSize().x - currPosition, frameSize);
		}
		break;
	}
	case Location::RIGHT_SIDE:
	{
		currPosition = spacing;
		for (auto el = elements.begin(); el != elements.end(); ++el)
		{
			ratio = (*el)->GetSize().x / (*el)->GetSize().y;
			(*el)->SetSize(size.x - frameSize * 2, (size.x - frameSize * 2) / ratio);
			(*el)->SetPosition(renderWindow->getSize().x - frameSize - (*el)->GetSize().x, currPosition);
			currPosition += (*el)->GetSize().y + spacing;
		}
		break;
	}
	case Location::LEFT_SIDE:
	{
		currPosition = spacing;
		for (auto el = elements.begin(); el != elements.end(); ++el)
		{
			ratio = (*el)->GetSize().x / (*el)->GetSize().y;
			(*el)->SetSize(size.x - frameSize * 2, (size.x - frameSize * 2) / ratio);
			(*el)->SetPosition(frameSize, currPosition);
			currPosition += (*el)->GetSize().y + spacing;
		}
		break;
	}
	}
	childCount++;
}
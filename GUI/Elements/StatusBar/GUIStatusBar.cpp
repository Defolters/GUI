#include "GUIStatusBar.h"

GUIStatusBar::GUIStatusBar(RenderWindow* renderWindow_, float height_, float frameSize_,
	float spacing_, Texture *background_)
	: IDisplayable(renderWindow_, Vector2f(0, 0), Vector2f(0, height_))
{
	statusBar = new Sprite();
	background = background_;
	frameSize = frameSize_;
	spacing = spacing_;
	height = height_;
	statusBar->setPosition(0, renderWindow_->getSize().y - height);
	width = renderWindow_->getSize().x;
	statusBar->setTexture(*background);
	statusBar->setScale(Vector2f(width, height));
}

void GUIStatusBar::Draw()
{
	Recalc();
	renderWindow->draw(*statusBar);
	IDisplayable::Draw();
}

void GUIStatusBar::handleEvent(const sf::Event & event)
{
	if (event.type == sf::Event::Resized)
	{
		statusBar->setScale(Vector2f(renderWindow->getSize().x, height + frameSize * 2));
		width = renderWindow->getSize().x;
	}
}

void GUIStatusBar::Recalc()
{
	currPosition = 0;
	float ratio;
	for (auto el = elements.begin(); el != elements.end(); ++el)
	{
		ratio = (*el)->GetSize().x / (*el)->GetSize().y;
		(*el)->SetSize(height * ratio, height);
		currPosition += (*el)->GetSize().x + spacing;
		((*el)->SetPosition(renderWindow->getSize().x - currPosition, renderWindow->getSize().y - (*el)->GetSize().y - frameSize));
	}
	statusBar->setScale(Vector2f(width, height + frameSize*2));
	statusBar->setPosition(0, renderWindow->getSize().y - height - frameSize*2);
}
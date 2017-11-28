#include "GUIStatusBar.h"

GUIStatusBar::GUIStatusBar(RenderWindow* renderWindow_, float height_, float frameSize_,
	float spacing_, GUIStyle *sBarStyle_)
	: IDisplayable(renderWindow_, Vector2f(0, 0), Vector2f(0, height_))
{
	statusBar = new Sprite();
	sBarStyle = sBarStyle_;
	frameSize = frameSize_;
	spacing = spacing_;
	height = height_;
	statusBar->setPosition(0, renderWindow_->getSize().y - height);
	width = renderWindow_->getSize().x;
	statusBar->setTexture(sBarStyle->background);
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
		width = renderWindow->getSize().x;
		statusBar->setScale(Vector2f(width, height));
		statusBar->setPosition(0, renderWindow->getSize().y - height);
		for (auto el = elements.begin(); el != elements.end(); ++el)
		{
			ratio = (*el)->GetSize().x / (*el)->GetSize().y;
			(*el)->SetSize((height - frameSize * 2) * ratio, height - frameSize * 2);
			currPosition += (*el)->GetSize().x + spacing;
			((*el)->SetPosition(renderWindow->getSize().x - currPosition, renderWindow->getSize().y - (*el)->GetSize().y - frameSize));
			childCount++;
		}
	}
}

void GUIStatusBar::Recalc()
{
	if (childCount != elements.size())
	{
		currPosition = 0;
		for (auto el = elements.begin(); el != elements.end(); ++el)
		{
			ratio = (*el)->GetSize().x / (*el)->GetSize().y;
			(*el)->SetSize((height - frameSize * 2) * ratio, height - frameSize * 2);
			currPosition += (*el)->GetSize().x + spacing;
			((*el)->SetPosition(renderWindow->getSize().x - currPosition, renderWindow->getSize().y - (*el)->GetSize().y - frameSize));
			childCount++;
		}
	}
}
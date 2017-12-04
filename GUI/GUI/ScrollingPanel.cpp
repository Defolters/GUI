#include "ScrollingPanel.h"

ScrollingPanel::ScrollingPanel(Vector2f maxScrollPanelSize_, RenderWindow &Swindow, Vector2f scrFieldPosition_, Vector2f scrFieldSize_, Color scrFieldColor_, GUIStyle *gst)
	:GUILayer((this->crutch), scrFieldPosition, scrFieldSize)
{
	this->SetSize(scrFieldSize_);
	this->SetPosition(scrFieldPosition_);
	this->SetValue(Vector2f(0, 0));
	viewPosition = Vector2i(0, 0);

	crutch.create(VideoMode(int(maxScrollPanelSize_.x), int(maxScrollPanelSize_.y)), "");
	crutch.setVisible(false);

	window = &Swindow;
	crutchsize = maxScrollPanelSize_;
	scrFieldColor = scrFieldColor_;

	scrField.setPosition(scrFieldPosition_);
}

void ScrollingPanel::SetPosition(Vector2f position_)
{
	IDrawable::SetPosition(position_);
	scrFieldPosition = position_;
}
void ScrollingPanel::SetSize(Vector2f size_)
{
	IDrawable::SetSize(size_);
	scrFieldSize = size_;
}

void ScrollingPanel::DrawPanel()
{
	crutch.clear(scrFieldColor);
	for (std::shared_ptr<IDrawable> bo : elements)
		if(typeid(*bo) != typeid(ScrollBar))
			bo->Draw();
	crutch.display();

	for (std::shared_ptr<IDrawable> bo : elements)
		if (typeid(*bo) == typeid(ScrollBar))
			bo->DrawforScr(window);

	Vector2u windowSize = crutch.getSize();
	Texture texture;
	texture.create(windowSize.x, windowSize.y);
	texture.update(crutch);
	scrImage = texture.copyToImage();
	viewPosition.x = ((this->GetValue().x)/scrFieldSize.x)*crutchsize.x; 
	viewPosition.y = ((this->GetValue().y) / scrFieldSize.y)*crutchsize.y;
	IntRect area(viewPosition.x,viewPosition.y,scrFieldSize.x,scrFieldSize.y);
	scrTexture.loadFromImage(scrImage, area);

	scrField.setTexture(scrTexture);
	window->draw(scrField);
}

void ScrollingPanel::notifysAll(const sf::Event & event) const
{
	Event newevent;
	newevent = event;
	if (event.type == Event::MouseMoved)
	{
		newevent.mouseMove.x = event.mouseMove.x - scrFieldPosition.x+viewPosition.x;
		newevent.mouseMove.y = event.mouseMove.y - scrFieldPosition.y+ viewPosition.y;
	}
	else if ((event.type == Event::MouseButtonPressed) || (event.type == Event::MouseButtonReleased))
	{
		newevent.mouseButton.x = event.mouseButton.x - scrFieldPosition.x+ viewPosition.x;
		newevent.mouseButton.y = event.mouseButton.y - scrFieldPosition.y+ viewPosition.y;
	}
	int i = 0;
	for (auto& element : elements)
	{
		if (i<=1)
			element->handleEvent(event);
		else
		element->handleEvent(newevent);
		i++;
	}
}

void ScrollingPanel::handlesEvent(const sf::Event & event)
{
	notifysAll(event);
}
#include "ScrollingPanel.h"

ScrollingPanel::ScrollingPanel(Vector2f maxScrollPanelSize_, RenderWindow &Swindow, Vector2f scrFieldPosition_, Vector2f scrFieldSize_, Color scrFieldColor_, GUIStyle *gst)
	:GUILayer((this->crutch), scrFieldPosition, scrFieldSize)
{
	this->SetSize(scrFieldSize_);
	this->SetPosition(scrFieldPosition_);
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
	//Recalc();
	crutch.clear(scrFieldColor);
	for (std::shared_ptr<IDrawable> bo : elements)
		if(typeid(*bo) != typeid(ScrollBar))
			bo->Draw();

	crutch.display();
	Vector2u windowSize = crutch.getSize();
	Texture texture;
	texture.create(windowSize.x, windowSize.y);
	texture.update(crutch);
	scrImage = texture.copyToImage();

	IntRect area(viewPosition.x,viewPosition.y,scrFieldSize.x,scrFieldSize.y);
	scrTexture.loadFromImage(scrImage, area);

	scrField.setTexture(scrTexture);
	for (std::shared_ptr<IDrawable> bo : elements)
		if (typeid(*bo) == typeid(ScrollBar))
			bo->DrawforScr(window);
	window->draw(scrField);



}

void ScrollingPanel::Recalc()
{
	int count = 0;
	for (auto bars = elements.begin(); bars != elements.end(); ++bars)
		{
		if (count == 0)
		{ //Для вертикального справа
			(*bars)->SetPosition(float(scrFieldPosition.x + scrFieldSize.x), float(scrFieldPosition.y));
			(*bars)->SetSize(float((*bars)->GetSize().x), float(scrFieldSize.y));
		}
		else if (count == 1)
		{ //Для горизонт снизу
			(*bars)->SetPosition(float(scrFieldPosition.x), float(scrFieldPosition.y + scrFieldSize.y));
			(*bars)->SetSize(float(scrFieldSize.x),float((*bars)->GetSize().y));
		}
		count++;
		}
	std::cout << count << std::endl;
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
	for (auto& element : elements)
		element->handleEvent(newevent);
}

void ScrollingPanel::handlesEvent(const sf::Event & event)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (viewPosition.x !=0)
		(viewPosition.x)-=5;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (viewPosition.y != 0)
			(viewPosition.y)-= 5;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if ((viewPosition.x+ scrFieldSize.x) != crutchsize.x)
			(viewPosition.x) += 5;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if ((viewPosition.y+ scrFieldSize.y) != crutchsize.y)
			(viewPosition.y) += 5;
	}
	notifysAll(event);
}
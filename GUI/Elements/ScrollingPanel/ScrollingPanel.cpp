#include "ScrollingPanel.h"

ScrollingPanel::ScrollingPanel(Vector2f maxScrollPanelSize_, RenderWindow &Swindow, Vector2f scrFieldPosition_, Vector2f scrFieldSize_, Color scrFieldColor_)
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
	// Рисуем элементы ScrollingPanel в невидимом окне
	crutch.clear(scrFieldColor);
	for (std::shared_ptr<IDrawable> bo : elements)
		if(typeid(*bo) != typeid(ScrollBar))
			bo->Draw();
	crutch.display();

	// Рисуем ScrollBar'ы в основном окне
	for (std::shared_ptr<IDrawable> bo : elements)
		if (typeid(*bo) == typeid(ScrollBar))
			bo->DrawforScr(window);

	// Захватываем изображение невидимого окна в scrImage
	Vector2u windowSize = crutch.getSize();
	Texture texture;
	texture.create(windowSize.x, windowSize.y);
	texture.update(crutch);
	scrImage = texture.copyToImage();

	// Загружаем в scrTexture область размера scrFieldSize с позиции viewPosition
	viewPosition.x = ((this->GetValue().x)/ scrFieldSize.x)*crutchsize.x;
	viewPosition.y = ((this->GetValue().y) / scrFieldSize.y)*crutchsize.y;
	IntRect area(viewPosition.x,viewPosition.y,scrFieldSize.x,scrFieldSize.y);
	scrTexture.loadFromImage(scrImage, area);

	// Рисуем ScrollingPanel в основном окне
	scrField.setTexture(scrTexture);
	window->draw(scrField);
}

void ScrollingPanel::notifysAll(const sf::Event & event) const
{
    // Добавляем событие newevent, которое передается для элементов, находящихся
    // на невидимом окне
    Event newevent;
    newevent = event;

    if (event.type == Event::MouseMoved)
    {
        newevent.mouseMove.x = event.mouseMove.x - scrFieldPosition.x + viewPosition.x;
        newevent.mouseMove.y = event.mouseMove.y - scrFieldPosition.y + viewPosition.y;
    }
    else if ((event.type == Event::MouseButtonPressed) || (event.type == Event::MouseButtonReleased))
    {
        newevent.mouseButton.x = event.mouseButton.x - scrFieldPosition.x + viewPosition.x;
        newevent.mouseButton.y = event.mouseButton.y - scrFieldPosition.y + viewPosition.y;
    }

    // Для 2 ScrollBar'ов оставляем событие без изменений, для остальных - newevent
    int i = 0;
    for (auto& element : elements)
    {
        if (i <= 1)
            element->handleEvent(event);
        else
        {

            if (((event.mouseMove.x <= (scrFieldPosition.x + scrFieldSize.x)) && (event.mouseMove.x >= scrFieldPosition.x) &&
                (event.mouseMove.y <= (scrFieldPosition.y + scrFieldSize.y)) && (event.mouseMove.y >= scrFieldPosition.y)) ||
                ((event.mouseButton.x <= (scrFieldPosition.x + scrFieldSize.x)) && (event.mouseButton.x >= scrFieldPosition.x) &&
                (event.mouseButton.y <= (scrFieldPosition.y + scrFieldSize.y)) && (event.mouseButton.y >= scrFieldPosition.y))
                || (event.type == Event::TextEntered))
                element->handleEvent(newevent);
        }
        i++;
    }
}

void ScrollingPanel::handlesEvent(const sf::Event & event)
{
	notifysAll(event);
}
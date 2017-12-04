#include "ScrollBar.h"


ScrollBar::ScrollBar(RenderWindow* renderWindow_, Orientation orientation_,
	GUIStyle *gstyle, float sizeScrollPanel_)
	: GUIBox(renderWindow_, renderWindow_->getSize().x - width, 0.0f, width, height, gstyle),
	orientation(orientation_), isMousePressed(false), sizeScrollPanel(sizeScrollPanel_)
{
	value = 0;
	shift = 0;
	roller.setFillColor(sf::Color::Color(171, 171, 171, 255));
	band.setFillColor(sf::Color::Color(220, 220, 220, 255));
	limiter.setFillColor(sf::Color::Color(120, 120, 120, 255));
}

void ScrollBar::handleEvent(const sf::Event& event) {
	if (orientation == Orientation::VERTICAL) {

		switch (event.type)
		{
		case sf::Event::MouseButtonPressed:
			if (event.mouseButton.button == sf::Mouse::Right) {
				return;
			}
			if (event.mouseButton.button == sf::Mouse::Left) {
				if ((event.mouseButton.x > band.getPosition().x) &&
					(event.mouseButton.x < (band.getPosition().x + band.getSize().x)) &&
					(event.mouseButton.y > band.getPosition().y) &&
					(event.mouseButton.y < (band.getPosition().y + band.getSize().y))) {
					if ((event.mouseButton.y >= roller.getPosition().y) && (event.mouseButton.y <= (roller.getPosition().y+roller.getSize().y))) 
						isMousePressed = true;
					else {
						value = event.mouseButton.y-band.getPosition().y;
						if (value > maxvalue) value = maxvalue;
						parent->SetValue(Vector2f(parent->GetValue().x,value));
					}
				}

			}
			break;
		case sf::Event::MouseButtonReleased:
			if (event.mouseButton.button == sf::Mouse::Right) 
				return;
			if (event.mouseButton.button == sf::Mouse::Left) 
				isMousePressed = false;
			break;
		case sf::Event::MouseMoved:
			if (isMousePressed) {
				if (event.mouseMove.y >= band.getPosition().y)
					{
						value = event.mouseMove.y - band.getPosition().y;
						if (value > maxvalue) value = maxvalue;
						parent->SetValue(Vector2f(parent->GetValue().x, value));
					}
				else
					{
						value = 0;
						parent->SetValue(Vector2f(parent->GetValue().x, value));
					}
				}
			break;
		default:
			break;
		}
	}

	else {
		switch (event.type)
		{
		case sf::Event::MouseButtonPressed:
			if (event.mouseButton.button == sf::Mouse::Right) {
				return;
			}
			if (event.mouseButton.button == sf::Mouse::Left) {
				if ((event.mouseButton.x > band.getPosition().x) &&
					(event.mouseButton.x < (band.getPosition().x + band.getSize().x)) &&
					(event.mouseButton.y > band.getPosition().y) &&
					(event.mouseButton.y < (band.getPosition().y + band.getSize().y))) {
					if ((event.mouseButton.x >= roller.getPosition().x) && (event.mouseButton.x <= (roller.getPosition().x + roller.getSize().x)))
					{
						isMousePressed = true;
					}
					else {
						value = event.mouseButton.x - band.getPosition().x;
						if (value > maxvalue) value = maxvalue;
						parent->SetValue(Vector2f(value, parent->GetValue().y));
					}
				}
			}
			break;
		case sf::Event::MouseButtonReleased:
			if (event.mouseButton.button == sf::Mouse::Right)
				return;
			if (event.mouseButton.button == sf::Mouse::Left)
				isMousePressed = false;
			break;
		case sf::Event::MouseMoved:
			if (isMousePressed) {
				if (event.mouseMove.x >= band.getPosition().x)
				{
					value = event.mouseMove.x - band.getPosition().x;
					if (value > maxvalue) value = maxvalue;
					parent->SetValue(Vector2f(value, parent->GetValue().y));
				}
				else
				{
					value = 0;
					parent->SetValue(Vector2f(value, parent->GetValue().y));
				}
			}
			break;
		default:
			break;
		}
	}
}


void ScrollBar::Draw() {
	Recalc();
	renderWindow->draw(band);
	renderWindow->draw(roller);
	renderWindow->draw(limiter);
}


void ScrollBar::DrawforScr(RenderWindow *swindow) {
	Recalc(swindow);
	swindow->draw(band);
	swindow->draw(roller);
	swindow->draw(limiter);
}

void ScrollBar::Recalc(RenderWindow *swindow)
{
	limiter.setSize(sf::Vector2f(width, width));
	limiter.setPosition(parent->GetPosition().x+parent->GetSize().x, parent->GetPosition().y + parent->GetSize().y);
	if (orientation == Orientation::VERTICAL) {
		height = parent->GetSize().y;
		band.setSize(sf::Vector2f(width, height));
		band.setPosition(parent->GetPosition().x + parent->GetSize().x, parent->GetPosition().y);
		roller.setSize(sf::Vector2f(width, ((parent->GetSize().y / sizeScrollPanel) * band.getSize().y)));
		maxvalue = band.getSize().y - roller.getSize().y;
		roller.setPosition(band.getPosition().x, band.getPosition().y+value); 
	}
	else {
		height = parent->GetSize().x;
		band.setSize(sf::Vector2f(height, width));
		band.setPosition(parent->GetPosition().x, parent->GetPosition().y + parent->GetSize().y);
		roller.setSize(sf::Vector2f(((parent->GetSize().x / sizeScrollPanel) * band.getSize().x), width));
		maxvalue = band.getSize().x - roller.getSize().x;
		roller.setPosition((band.getPosition().x+value), band.getPosition().y); 
	}
}

void ScrollBar::Recalc()
{
	limiter.setSize(sf::Vector2f(width, width));
	limiter.setPosition(parent->GetPosition().x + parent->GetSize().x-width, parent->GetPosition().y + parent->GetSize().y-width);
	if (orientation == Orientation::VERTICAL) {
		height = parent->GetSize().y-width;
		band.setSize(sf::Vector2f(width, height));
		band.setPosition(parent->GetPosition().x + parent->GetSize().x-width, parent->GetPosition().y);
		roller.setSize(sf::Vector2f(width, ((parent->GetSize().y / sizeScrollPanel) * band.getSize().y)));
		roller.setPosition(band.getPosition().x, band.getPosition().y+ roller.getPosition().y);
		shift = roller.getSize().y;
	}
	else {
		height = parent->GetSize().x-width;
		band.setSize(sf::Vector2f(height, width));
		band.setPosition(parent->GetPosition().x, parent->GetPosition().y + parent->GetSize().y-width);
		roller.setSize(sf::Vector2f(((parent->GetSize().x / sizeScrollPanel) * band.getSize().x), width));
		roller.setPosition(band.getPosition().x+roller.getPosition().x, band.getPosition().y);
		shift = roller.getSize().x;
	}
}
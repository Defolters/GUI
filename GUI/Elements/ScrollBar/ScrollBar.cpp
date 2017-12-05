#include "ScrollBar.h"

ScrollBar::ScrollBar(RenderWindow* renderWindow_, Orientation orientation_,
	GUIStyle *gstyle, float sizeScrollPanel_)
	: GUIBox(renderWindow_, renderWindow_->getSize().x - width, 0.0f, width, height, gstyle),
	orientation(orientation_), isMousePressed(false), sizeScrollPanel(sizeScrollPanel_)
{
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
					(event.mouseButton.x < band.getPosition().x + width) &&
					(event.mouseButton.y > band.getPosition().y) &&
					(event.mouseButton.y < band.getPosition().y + band.getSize().y)) {

					if (event.mouseButton.y < roller.getPosition().y) {

						if (roller.getPosition().y - shift < band.getPosition().y) {
							float temp = band.getPosition().y - roller.getPosition().y;
							roller.move(0.0f, temp);
							parent->SetValue(Vector2f(parent->GetValue().x, parent->GetValue().y + temp));
						}
						else {
							roller.move(0.0f, -shift);
							parent->SetValue(Vector2f(parent->GetValue().x, parent->GetValue().y - shift));
						}
					}
					else {
						if (event.mouseButton.y > roller.getPosition().y + roller.getSize().y) {
							if (roller.getPosition().y + roller.getSize().y + shift > band.getPosition().y + band.getSize().y) {
								float temp = band.getPosition().y + band.getSize().y - roller.getPosition().y - roller.getSize().y;
								roller.move(0.0f, temp);
								parent->SetValue(Vector2f(parent->GetValue().x, parent->GetValue().y + temp));
							}
							else {
								roller.move(0.0f, shift);
								parent->SetValue(Vector2f(parent->GetValue().x, parent->GetValue().y + shift));
							}
						}
						else {
							if (!isMousePressed) {
								isMousePressed = true;
								lastPos = event.mouseButton.y;
							}
						}
					}
				}

			}
			break;
		case sf::Event::MouseButtonReleased:
			if (event.mouseButton.button == sf::Mouse::Right) {
				return;
			}
			if (event.mouseButton.button == sf::Mouse::Left) {
				isMousePressed = false;
			}
			break;
		case sf::Event::MouseMoved:
			if (isMousePressed) {
				if (roller.getPosition().y + event.mouseMove.y - lastPos < band.getPosition().y) {
					float temp = band.getPosition().y - roller.getPosition().y;
					roller.move(0.0f, temp);
					lastPos = event.mouseMove.y;
					parent->SetValue(Vector2f(parent->GetValue().x, parent->GetValue().y + temp));
				}
				else {
					if (roller.getPosition().y + event.mouseMove.y - lastPos > band.getPosition().y + band.getSize().y - roller.getSize().y) {
						float temp = band.getPosition().y + band.getSize().y - roller.getPosition().y - roller.getSize().y;
						if ((roller.getPosition().y + roller.getSize().y) == (band.getPosition().y + band.getSize().y))
							temp = 0;
						roller.move(0.0f, temp);
						lastPos = roller.getPosition().y;
						parent->SetValue(Vector2f(parent->GetValue().x, parent->GetValue().y + temp));
					}
					else {
						roller.move(0.0f, event.mouseMove.y - lastPos);
						parent->SetValue(Vector2f(parent->GetValue().x, parent->GetValue().y + event.mouseMove.y - lastPos));
						lastPos = event.mouseMove.y;
					}
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
				if ((event.mouseButton.y > band.getPosition().y) &&
					(event.mouseButton.y < band.getPosition().y + width) &&
					(event.mouseButton.x > band.getPosition().x) &&
					(event.mouseButton.x < band.getPosition().x + band.getSize().x)) {

					if (event.mouseButton.x < roller.getPosition().x) {

						if (roller.getPosition().x - shift < band.getPosition().x) {
							float temp = band.getPosition().x - roller.getPosition().x;
							roller.move(temp, 0.0f);
							parent->SetValue(Vector2f(parent->GetValue().x + temp, parent->GetValue().y));
						}
						else {
							roller.move(-shift, 0.0f);
							parent->SetValue(Vector2f(parent->GetValue().x - shift, parent->GetValue().y));
						}
					}
					else {
						if (event.mouseButton.x > roller.getPosition().x + roller.getSize().x) {
							if (roller.getPosition().x + roller.getSize().x + shift > band.getPosition().x + band.getSize().x) {
								float temp = band.getPosition().x + band.getSize().x - roller.getPosition().x - roller.getSize().x;
								roller.move(temp, 0.0f);
								parent->SetValue(Vector2f(parent->GetValue().x + temp, parent->GetValue().y));
							}
							else {
								roller.move(shift, 0.0f);
								parent->SetValue(Vector2f(parent->GetValue().x + shift, parent->GetValue().y));
							}
						}
						else {
							if (!isMousePressed) {
								isMousePressed = true;
								lastPos = event.mouseButton.x;
							}
						}
					}
				}

			}
			break;
		case sf::Event::MouseButtonReleased:
			if (event.mouseButton.button == sf::Mouse::Right) {
				return;
			}
			if (event.mouseButton.button == sf::Mouse::Left) {
				isMousePressed = false;
			}
			break;
		case sf::Event::MouseMoved:
			if (isMousePressed) {
				if (roller.getPosition().x + event.mouseMove.x - lastPos < band.getPosition().x) {
					float temp = band.getPosition().x - roller.getPosition().x;
					roller.move(temp, 0.0f);
					lastPos = event.mouseMove.x;
					parent->SetValue(Vector2f(parent->GetValue().x + temp, parent->GetValue().y));
				}
				else {
					if (roller.getPosition().x + event.mouseMove.x - lastPos > band.getPosition().x + band.getSize().x - roller.getSize().x) {
						float temp = band.getPosition().x + band.getSize().x - roller.getPosition().x - roller.getSize().x;
						roller.move(temp, 0.0f);
						lastPos = roller.getPosition().x;
						parent->SetValue(Vector2f(parent->GetValue().x + temp, parent->GetValue().y));
					}
					else {
						roller.move(event.mouseMove.x - lastPos, 0.0f);
						parent->SetValue(Vector2f(parent->GetValue().x + event.mouseMove.x - lastPos, parent->GetValue().y));
						lastPos = event.mouseMove.x;
					}
				}
			}
			break;
		default:
			break;
		}
	}
}


void ScrollBar::DrawforScr(RenderWindow *swindow) {
	Recalc();
	swindow->draw(band);
	swindow->draw(roller);
	swindow->draw(limiter);
}

void ScrollBar::Recalc()
{
	limiter.setSize(sf::Vector2f(width, width));
	limiter.setPosition(parent->GetPosition().x + parent->GetSize().x, parent->GetPosition().y + parent->GetSize().y);
	if (orientation == Orientation::VERTICAL) {
		height = parent->GetSize().y;
		band.setSize(sf::Vector2f(width, height));
		band.setPosition(parent->GetPosition().x + parent->GetSize().x, parent->GetPosition().y);
		roller.setSize(sf::Vector2f(width, ((parent->GetSize().y / sizeScrollPanel) * band.getSize().y)));
		if (roller.getPosition().y == 0)
		{
			roller.setPosition(band.getPosition().x, band.getPosition().y);
		}
		else
		{
			roller.setPosition(band.getPosition().x, roller.getPosition().y);
		}
		shift = roller.getSize().y;
	}
	else {
		height = parent->GetSize().x;
		band.setSize(sf::Vector2f(height, width));
		band.setPosition(parent->GetPosition().x, parent->GetPosition().y + parent->GetSize().y);
		roller.setSize(sf::Vector2f(((parent->GetSize().x / sizeScrollPanel) * band.getSize().x), width));
		if (roller.getPosition().x == 0)
		{
			roller.setPosition(band.getPosition().x, band.getPosition().y);
		}
		else
		{
			roller.setPosition(roller.getPosition().x, band.getPosition().y);
		}
		shift = roller.getSize().x;
	}
}
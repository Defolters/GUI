#include "ScrollBar.h"


ScrollBar::ScrollBar(RenderWindow* renderWindow_, Orientation orientation_,
	GUIStyle *gstyle, float sizeScrollPanel_)
	: GUIBox(renderWindow_, renderWindow_->getSize().x - width, 0.0f, width, height, gstyle),
	orientation(orientation_), isMousePressed(false), sizeScrollPanel(sizeScrollPanel_)
{
	Recalc();
	roller.setFillColor(sf::Color::Color(171, 171, 171, 255));
	band.setFillColor(sf::Color::Color(220, 220, 220, 255));
	limiter.setFillColor(sf::Color::Color(120, 120, 120, 255));
}

void null(const float& x, const float& y)
{

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
							roller.move(0.0f, band.getPosition().y - roller.getPosition().y);
							null(0.0, band.getPosition().y - roller.getPosition().y);
						}
						else {
							roller.move(0.0f, -shift);
							null(0.0f, -shift);
						}
					}
					else {
						if (event.mouseButton.y > roller.getPosition().y + roller.getSize().y) {
							if (roller.getPosition().y + roller.getSize().y + shift > band.getPosition().y + band.getSize().y) {
								roller.move(0.0f, band.getPosition().y + band.getSize().y - roller.getPosition().y - roller.getSize().y);
								null(0.0f, band.getPosition().y + band.getSize().y - roller.getPosition().y - roller.getSize().y);
							}
							else {
								roller.move(0.0f, shift);
								null(0.0f, shift);
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
					roller.move(0.0f, band.getPosition().y - roller.getPosition().y);
					lastPos = event.mouseMove.y;
					null(0.0f, band.getPosition().y - lastPos);
				}
				else {
					if (roller.getPosition().y + event.mouseMove.y - lastPos > band.getPosition().y + band.getSize().y - roller.getSize().y) {
						roller.move(0.0f, band.getPosition().y + band.getSize().y - roller.getPosition().y - roller.getSize().y);
						lastPos = roller.getPosition().y;
						null(0.0f, band.getPosition().y + band.getSize().y - roller.getPosition().y - roller.getSize().y);
					}
					else {
						roller.move(0.0f, event.mouseMove.y - lastPos);
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
					(event.mouseButton.y < band.getPosition().y + height) &&
					(event.mouseButton.x > band.getPosition().x) &&
					(event.mouseButton.x < band.getPosition().x + band.getSize().x)) {

					if (event.mouseButton.x < roller.getPosition().x) {

						if (roller.getPosition().x - shift < band.getPosition().x) {
							roller.move(band.getPosition().x - roller.getPosition().x, 0.0f);
							null(band.getPosition().x - roller.getPosition().x, 0.0f);
						}
						else {
							roller.move(-shift, 0.0f);
							null(-shift, 0.0f);
						}
					}
					else {
						if (event.mouseButton.x > roller.getPosition().x + roller.getSize().x) {
							if (roller.getPosition().x + roller.getSize().x + shift > band.getPosition().x + band.getSize().x) {
								roller.move(band.getPosition().x + band.getSize().x - roller.getPosition().x - roller.getSize().x, 0.0f);
								null(band.getPosition().x + band.getSize().x - roller.getPosition().x - roller.getSize().x, 0.0f);
							}
							else {
								roller.move(shift, 0.0f);
								null(shift, 0.0f);
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
					roller.move(band.getPosition().x - roller.getPosition().x, 0.0f);
					lastPos = event.mouseMove.x;
					null(band.getPosition().x - lastPos, 0.0f);
				}
				else {
					if (roller.getPosition().x + event.mouseMove.x - lastPos > band.getPosition().x + band.getSize().x - roller.getSize().x) {
						roller.move(band.getPosition().x + band.getSize().x - roller.getPosition().x - roller.getSize().x, 0.0f);
						lastPos = roller.getPosition().x;
						null(band.getPosition().x + band.getSize().x - roller.getPosition().x - roller.getSize().x, 0.0f);
					}
					else {
						roller.move(event.mouseMove.x - lastPos, 0.0f);
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


void ScrollBar::Draw() {
	Recalc();
	renderWindow->draw(band);
	renderWindow->draw(roller);
	renderWindow->draw(limiter);
}

void ScrollBar::Recalc()
{
	limiter.setSize(sf::Vector2f(width, width));
	limiter.setPosition(renderWindow->getSize().x - limiter.getSize().x, renderWindow->getSize().y - limiter.getSize().y);
	if (orientation == Orientation::VERTICAL) {
		height = renderWindow->getSize().y - limiter.getSize().y;
		band.setSize(sf::Vector2f(width, height));
		band.setPosition(renderWindow->getSize().x - width, 0.0f);
		roller.setSize(sf::Vector2f(width, band.getSize().y / (sizeScrollPanel / renderWindow->getSize().y)));
		roller.setPosition(renderWindow->getSize().x - width, roller.getPosition().y);
		shift = roller.getSize().y;
	}
	else {
		height = renderWindow->getSize().x - limiter.getSize().x;
		band.setSize(sf::Vector2f(height, width));
		band.setPosition(0.0f, renderWindow->getSize().y - width);
		roller.setSize(sf::Vector2f(band.getSize().x / (sizeScrollPanel / renderWindow->getSize().x), width));
		roller.setPosition(roller.getPosition().x, renderWindow->getSize().y - width);
		shift = roller.getSize().x;
	}


}

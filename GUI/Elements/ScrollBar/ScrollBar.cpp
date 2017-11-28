#include "ScrollBar.h"


ScrollBar::ScrollBar(RenderWindow* renderWindow_, Orientation orientation_, std::string text, TextStyle *tstyle, GUIStyle *gstyle)
	: GUIBox(renderWindow_, renderWindow_->getSize().x - width, 0.0, width, height, gstyle),
	orientation(orientation_), isMousePressed(false)
{
    Recalc();
	roller.setFillColor(sf::Color::Green);
	band.setFillColor(sf::Color::Blue);
}

void null(const float& x, const float& y)
{

}

 void ScrollBar::handleEvent(const sf::Event& event) {
	 if (orientation == Orientation::HORIZONTAL) {

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
							 roller.move(0.0, band.getPosition().y - roller.getPosition().y);
							 null(0.0,band.getPosition().y - roller.getPosition().y);
						 }
						 else {
							 roller.move(0.0, -shift);
							 null(0.0, -shift);
						 }
					 }
					 else {
						 if (event.mouseButton.y > roller.getPosition().y + roller.getSize().y) {
							 if (roller.getPosition().y + roller.getSize().y + shift > band.getPosition().y + band.getSize().y) {
								 roller.move(0.0, band.getPosition().y + band.getSize().y - roller.getPosition().y - roller.getSize().y);
								 null(0.0, band.getPosition().y + band.getSize().y - roller.getPosition().y - roller.getSize().y);
							 }
							 else {
								 roller.move(0.0, shift);
								 null(0.0, shift);
							 }
						 }
						 else {
							 if (!isMousePressed) {
								 isMousePressed = true;
								 lastPosY = event.mouseButton.y;
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
				 if (roller.getPosition().y + event.mouseMove.y - lastPosY < band.getPosition().y) {
					 roller.move(0.0, band.getPosition().y - lastPosY);
					 lastPosY = roller.getPosition().y;
					 null(0.0, band.getPosition().y - lastPosY);
				 }
				 else {
					 if (roller.getPosition().y + event.mouseMove.y - lastPosY > band.getPosition().y + band.getSize().y - roller.getSize().y) {
						 roller.move(0.0, band.getPosition().y + band.getSize().y - roller.getPosition().y - roller.getSize().y);
						 lastPosY = roller.getPosition().y;
						 null(0.0, band.getPosition().y + band.getSize().y - roller.getPosition().y - roller.getSize().y);
					 }
					 else {
						 roller.move(0.0, event.mouseMove.y - lastPosY);
						 lastPosY = event.mouseMove.y;
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
							 roller.move(band.getPosition().x - roller.getPosition().x,0.0);
							 null(band.getPosition().x - roller.getPosition().x,0.0);
						 }
						 else {
							 roller.move(-shift,0.0);
							 null(-shift,0.0);
						 }
					 }
					 else {
						 if (event.mouseButton.x > roller.getPosition().x + roller.getSize().x) {
							 if (roller.getPosition().x + roller.getSize().x + shift > band.getPosition().x + band.getSize().x) {
								 roller.move(band.getPosition().x + band.getSize().x - roller.getPosition().x - roller.getSize().x, 0.0);
								 null(band.getPosition().x + band.getSize().x - roller.getPosition().x - roller.getSize().x,0.0);
							 }
							 else {
								 roller.move(shift, 0.0);
								 null(shift,0.0);
							 }
						 }
						 else {
							 if (!isMousePressed) {
								 isMousePressed = true;
								 lastPosY = event.mouseButton.x;
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
				 if (roller.getPosition().x + event.mouseMove.x - lastPosY < band.getPosition().x) {
					 roller.move(band.getPosition().x - lastPosY, 0.0);
					 lastPosY = roller.getPosition().x;
					 null(band.getPosition().x - lastPosY,0.0);
				 }
				 else {
					 if (roller.getPosition().x + event.mouseMove.x - lastPosY > band.getPosition().x + band.getSize().x - roller.getSize().x) {
						 roller.move(band.getPosition().x + band.getSize().x - roller.getPosition().x - roller.getSize().x,0.0);
						 lastPosY = roller.getPosition().x;
						 null(band.getPosition().x + band.getSize().x - roller.getPosition().x - roller.getSize().x,0.0);
					 }
					 else {
						 roller.move(event.mouseMove.x - lastPosY, 0.0);
						 lastPosY = event.mouseMove.x;
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
}

void ScrollBar::Recalc()
{
    if (orientation == Orientation::HORIZONTAL) {
        height = renderWindow->getSize().y;
        band.setSize(sf::Vector2f(width, height));
        roller.setSize(sf::Vector2f(width, 2 * width));
        band.setPosition(renderWindow->getSize().x - width, 0.0);
        roller.setPosition(renderWindow->getSize().x - width, roller.getPosition().y); 
    }
    else {
        height = renderWindow->getSize().x;
        band.setSize(sf::Vector2f(height, width));
        roller.setSize(sf::Vector2f(2 * width, width));
        band.setPosition(0.0, renderWindow->getSize().y - width);
        roller.setPosition(roller.getPosition().x, renderWindow->getSize().y - width);
    }
}

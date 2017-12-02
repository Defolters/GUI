#include "TextArea.h"

TextArea::TextArea(RenderWindow * renderWindow, float x, float y, float width, float height, TextStyle * tstyle, GUIStyle * gstyle): IDisplayable(renderWindow,x,y,width,height),
	font(tstyle->font), fontSize(tstyle->fontSize),fontColor(Color::Red),areaColor(Color::White),areaSize(width,height),areaPosition(x,y)
{

}


void TextArea::GettingText()
{

}

void TextArea::handleEvent(const sf::Event & event)
{
	switch (event.type)
	{
	case sf::Event::MouseButtonPressed:
	{
		if (event.mouseButton.button == Mouse::Button::Left && event.mouseButton.x > areaPosition.x && event.mouseButton.x < areaPosition.x + areaSize.x && event.mouseButton.y > areaPosition.y && event.mouseButton.y < areaPosition.y + areaSize.y)
		{
			button = true;
		}
		else
		{
			button = false;
		}
		break;
	}
	case sf::Event::TextEntered:
	{
		if (button)
		{
			if (event.text.unicode >= 32 && event.text.unicode <= 126)
				inputString += (char)event.text.unicode;
			else if (event.text.unicode == 8 && inputString.getSize() > 0)
				inputString.erase(inputString.getSize() - 1);
			else if (event.text.unicode == 0xD)
				inputString += L"\n";


			
			text.setString(inputString);
			
			if (text.getGlobalBounds().width > areaSize.x)
			{
				
				inputString.insert(inputString.getSize() - 1, "\n");
				text.setString(inputString);
			}
			if (text.getGlobalBounds().height > areaSize.y)
			{
				text.setString(inputString);
				sf::FloatRect rect2 = text.getGlobalBounds();
				area.setPosition(rect2.left, rect2.top - 5);
				area.setSize(sf::Vector2f(rect2.width, rect2.height + 10));
			}
			text.setFont(font);
			text.setCharacterSize(fontSize);
			text.setFillColor(fontColor);
			text.setPosition(400, 300);
			
		}
		break;
	}
	//case sf::Event::MouseMoved:
		

	}
}




	


void TextArea::SetPosition(float x, float y)
{
	areaPosition.x = x;
	areaPosition.x = y;
}

void TextArea::SetPosition(Vector2f position_)
{
}

void TextArea::SetSize(float width, float height)
{
}

void TextArea::SetSize(Vector2f size_)
{
}

bool TextArea::GetDrawState()
{
	return false;
}

void TextArea::SetDrawState(bool)
{
}

bool TextArea::IsClickedThrough()
{
	return false;
}
void TextArea::CreatingArea()
{
	area.setFillColor(areaColor);
	area.setPosition(areaPosition);
	area.setSize(areaSize);
}

void TextArea::Draw()
{
	CreatingArea();
	renderWindow->draw(area);
	renderWindow->draw(text);
}
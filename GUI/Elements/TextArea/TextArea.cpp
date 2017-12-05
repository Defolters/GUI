#include "TextArea.h"

TextArea::TextArea(RenderWindow * renderWindow, float x, float y, float width, float height, TextStyle * tstyle, GUIStyle * gstyle) : IDisplayable(renderWindow, x, y, width, height),
font(tstyle->font), fontSize(tstyle->fontSize), fontColor(Color::Black), areaColor(Color::White), areaSize(width, height), areaPosition(x, y), minX(width), minY(height)
{
}

void TextArea::GettingText()
{

}

void TextArea::handleEvent(const sf::Event & event)
{
	sf::String textString;

	switch (event.type)
	{
	case sf::Event::MouseButtonPressed:
	{
		if (event.mouseButton.button == Mouse::Button::Left && event.mouseButton.x > areaPosition.x && event.mouseButton.x < areaPosition.x + areaSize.x && event.mouseButton.y > areaPosition.y && event.mouseButton.y < areaPosition.y + areaSize.y)
		{
			
			button = true;
			if (numChar == 0)
			{
				text.setFont(font);
				text.setCharacterSize(fontSize);
				text.setFillColor(fontColor);
				text.setPosition(areaPosition);

				textString = text.getString();
				textString.insert(0, "_");
				text.setString(textString);

				cursorLastNum = 0;
				numChar++;
			}
			else
			{
				Vector2f tmpCourse;
				int tmpX_right;
				int tmpX_left;
				int tmpY_top;
				int tmpY_bottom;
				int tmpX_middle;

				for (int i = 0; i < numChar - 1; i++)
				{
					tmpX_right = text.findCharacterPos(i + 1).x;
					tmpX_left = text.findCharacterPos(i).x;
					tmpY_top = text.findCharacterPos(i).y;
					tmpY_bottom = text.findCharacterPos(i).y + fontSize;
					tmpX_middle = tmpX_left + ((tmpX_right - tmpX_left) / 2);

					if (event.mouseButton.y > tmpY_top && event.mouseButton.y < tmpY_bottom && event.mouseButton.x > tmpX_left && event.mouseButton.x < tmpX_right)
					{
						if (event.mouseButton.x > tmpX_middle)
						{
							textString = text.getString();
							if (cursorLastNum != -1)
							{
								textString.erase(cursorLastNum);
							}
							if (i != numChar - 2)
							{
								textString.insert(i + 1, "_");
							}
							else
							{
								textString.insert(numChar-2, "_");
							}
							text.setString(textString);
							numChar++;
							cursorLastNum = i + 1;
							break;
						}
						else
						{
							textString = text.getString();
							if (cursorLastNum != -1)
							{
								textString.erase(cursorLastNum);
							}
							textString.insert(i, "_");
							text.setString(textString);
							numChar++;
							cursorLastNum = i;
							break;
						}
					}
				}
			}
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
				maxX = renderWindow->getSize().x;
				maxY = renderWindow->getSize().y;
				
				if (event.text.unicode>=32 && event.text.unicode<=128)
				{
					
					
					if (areaPosition.y + areaSize.y <= maxY - 100)
					{
						
						inputString = text.getString();
						inputString.insert(cursorLastNum, (char)event.text.unicode);
						
						if (inputString.getSize() != 0)
						{
							
							int tmp = cursorLastNum;
							bool check = false;
							do
							{
								tmp++;
								if ((char)inputString[tmp] == '\n')
									check = true;
							} while ((char)inputString[tmp] != '\n' && tmp < inputString.getSize());
							if (check)
							{
								sf::String tmpString;
								tmpString = "\n";
								tmpString += inputString[tmp - 1];
								inputString.insert(tmp - 1, tmpString);
								inputString.erase(tmp + 1, 2);
							}
						}
						stringForEntering += (char)event.text.unicode;

						numChar++;
						cursorLastNum++;
						
					}

					
				}
				else if (event.text.unicode == 8 && inputString.getSize() > 0)
				{
					if (stringForEntering.getSize() > 0)
					{
						stringForEntering.erase(stringForEntering.getSize() - 1);
					}
					else
					{
						sf::String stringForLastLine;
						stringForLastLine = text.getString();
						int tmpNum = numChar - 1;

						while ((char)stringForLastLine[tmpNum] != '\n' && tmpNum>0)
						{
							stringForEntering += stringForLastLine[tmpNum];
							tmpNum--;
						}

					}

					inputString = text.getString();

					if (cursorLastNum > 0)
					{
						inputString.erase(cursorLastNum - 1);
						cursorLastNum--;
						numChar--;
					}


				}
				
				else if (event.text.unicode == 13)
				{
					if (areaPosition.y + areaSize.y <= maxY - 100)
					{
						
						inputString = text.getString();
						inputString.insert(cursorLastNum, "\n");
						stringForEntering = "";
						numChar++;
						cursorLastNum++;
					}
				}
				text.setString(inputString);
				if (text.getGlobalBounds().height < areaPosition.y + areaSize.y - fontSize	&&  areaSize.y>minY)
				{
					sf::FloatRect rect2 = text.getGlobalBounds();
					areaSize.y = rect2.height - (fontSize - 8);
					area.setSize(areaSize);

				}
				Text textForEntering;

				textForEntering.setCharacterSize(fontSize);

				textForEntering.setFont(font);
				textForEntering.setString(stringForEntering);
				if (textForEntering.getGlobalBounds().width > areaSize.x - 15)
				{
					textString = text.getString();					
					textString.insert(textString.getSize() - 1, "\n");
					stringForEntering = "";
					numChar = numChar + 1;
					cursorLastNum++;
					text.setString(textString);

				}
				if (text.getGlobalBounds().height > areaSize.y - fontSize - 10)
				{
					if (areaPosition.y + areaSize.y < maxY - 100)
					{
						sf::FloatRect rect2 = text.getGlobalBounds();
						areaSize.y = rect2.height + (fontSize - 8);
						area.setSize(areaSize);

					}
					else
					{
						inputString.erase(inputString.getSize() - 1);//остановка печати текста на экране
					}
				}
				

			}
			break;
		}
		
	}
}




void TextArea::SetPosition(float x, float y)
{
	areaPosition.x = x;
	areaPosition.y = y;
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
	area.setOutlineThickness(5);
	area.setOutlineColor(Color::Yellow);
}

void TextArea::Draw()
{
	CreatingArea();
	renderWindow->draw(area);
	renderWindow->draw(text);
}

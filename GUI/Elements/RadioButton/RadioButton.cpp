#include "RadioButton.h"



RadioButton::RadioButton(std::shared_ptr<GUILayer> layer, RenderWindow* renderWindow_, int count, float x, float y, float width, float height, std::vector<std::string> text, TextStyle *tstyle, GUIStyle *gstyle)
:IDisplayable(renderWindow_, x, y, width, 20+50*count)
{
	for (int i = 0; i < count; i++)
	{
		//GUILabel* lab = new GUILabel(renderWindow_, x+60, y+height*i, 200, 50, text[i], tstyle, gstyle);
		//labels.push_back(lab);
		CheckButton* option = new CheckButton(renderWindow_, x, y+height*i, width, height, gstyle);
		options.push_back(option);
		stateArray.push_back(0);
	}
}

RadioButton::~RadioButton()
{
}

void RadioButton::Draw()
{
	for (auto el : options)
	{
		el->Draw();
	}
}


void RadioButton::handleEvent(const sf::Event & event)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		//—мотрит, была ли это Ћ≈¬јя кнопка
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			int i = 0;
			for (auto chBox : options)
			{
				if (chBox->contain(Vector2f(event.mouseButton.x, event.mouseButton.y)))
				{
					int j = 0;
					for (auto chBoxElse : options)
					{
						if (!chBoxElse->contain(Vector2f(event.mouseButton.x, event.mouseButton.y)))
						{
							stateArray[j] = 0;
							chBoxElse->setDeactive();
						}
						j++;
					}
					chBox->setActive();
					stateArray[i] = 1;
				}
				i++;
			}
		}
		for (auto el : stateArray)
		{
			std::cout << el << " ";
		}
		std::cout << std::endl;
	}
}

std::shared_ptr<RadioButton> GUILayer::CreateRadButton(std::shared_ptr<GUILayer> layer, int count, float x, float y, float width, float height, std::vector<std::string> text, TextStyle * tstyle, GUIStyle * gstyle)
{
	std::shared_ptr<RadioButton> radBut(new RadioButton(layer, window, count, x, y, width, height, text, tstyle, gstyle));
	elements.push_back(radBut);
	return radBut;
}


std::vector<bool> RadioButton::getState()
{
	return stateArray;
}
#include "RadioButton.h"


//Конструктор RadButton
RadioButton::RadioButton(std::shared_ptr<GUILayer> layer, RenderWindow* renderWindow_, int count, float x, float y, float width, float height, std::vector<std::string> text, TextStyle *tstyle, GUIStyle *gstyle)
:IDisplayable(renderWindow_, x, y, width, 20+50*count)
{
	butHeight = height;
	butWidth = width;
	for (int i = 0; i < count; i++)
	{
		//создание кнопки
		CheckButton* option = new CheckButton(layer, renderWindow_, x, y+height*i+10*i, width, height, gstyle, text[i], tstyle);
		options.push_back(option);
		//определение стартового состояния
		stateArray.push_back(0);
	}
}

//отрисовка кнопок, лейблы отрисовываются сами
void RadioButton::Draw()
{
	for (auto el : options)
	{
		el->Draw();
	}
}

//обработка события(печатает состояние массива при каждом клике)
void RadioButton::handleEvent(const sf::Event & event)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		//Смотрит, была ли это ЛЕВАЯ кнопка
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
					for (auto el : stateArray)
					{
						std::cout << el << " ";
					}
					std::cout << std::endl;
				}
				i++;
			}
		}

	}
}
//конструктор здесь, ибо возникла проблема с заголовочным файлом




std::vector<bool> RadioButton::getState()
{
	return stateArray;
}

void RadioButton::SetPosition(float x, float y)
{
	IDisplayable::SetPosition(x, y);
	int i = 0;
	for (auto el : options)
	{
		el->SetPosition(x, y+butHeight*i+10*i);
		i++;
	}
}

void RadioButton::SetPosition(Vector2f pos)
{
	IDisplayable::SetPosition(pos);
	int i = 0;
	for (auto el : options)
	{
		el->SetPosition(pos.x, pos.y + butHeight*i + 10 * i);
		i++;
	}
}

void RadioButton::SetPosition(Vector2f pos, Vector2f coefficient)
{
	Vector2f tmp = GetPosition();
	IDisplayable::SetPosition(Vector2f(tmp.x*coefficient.x, tmp.y*coefficient.y));
	int i = 0;
	for (auto el : options)
	{
		el->SetPosition(tmp.x*coefficient.x, tmp.y*coefficient.y + butHeight*i + 10 * i);
		i++;
	}
}
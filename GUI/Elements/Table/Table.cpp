#include "Table.h"
#include <iostream>


Table::Table(GUILayer* fabric_, sf::RenderWindow* renderWindow_, float x, float y, float width, float height, TextStyle *tst, GUIStyle *gst) : IDisplayable(renderWindow_, x, y, width, height)
{
	gstyle = gst;
	tstyle = tst;
	fabric = fabric_;

	init(x, y, width, height);

}

Table::Table(sf::RenderWindow* renderWindow_, Vector2f xy, float width, float height) : IDisplayable(renderWindow_, xy, width, height) 
{
	init(xy.x, xy.y, width, height);
}

Table::Table(sf::RenderWindow* renderWindow_, float x, float y, Vector2f size) : IDisplayable(renderWindow_, x, y, size) 
{
	init(x, y, size.x, size.y);
}

Table::Table(sf::RenderWindow* renderWindow_, Vector2f xy, Vector2f size) : IDisplayable(renderWindow_, xy, size)
{ 
	init(xy.x, xy.y, size.x, size.y);
}




Table::~Table()
{
}

void Table::Draw()
{
	Update(position.x, position.y, size.x, size.y);

	renderWindow->draw(border);
	for (size_t i = 0; i < size.y; i++)
	{
		for (size_t j = 0; j < size.x; j++)
		{
			if (elements[i][j] != NULL)
			{
				elements[i][j]->Draw();
			}
		}
	}
}

void Table::Update(float x, float y, float width, float height)
{
	for (size_t i = 0; i < height; i++)
	{
		for (size_t j = 0; j < width; j++)
		{
			if (elements[i][j] != NULL)
			{
				elements[i][j]->SetSize(fieldSize);
				sf::Vector2f pos(x + j*(fieldSize.x + borderSize), y + i*(fieldSize.y + borderSize));
				elements[i][j]->SetPosition(pos);
			}
		}
	}
	border.setPosition(x-borderSize, y-borderSize);
	border.setSize(sf::Vector2f((width)*(fieldSize.x + borderSize) + borderSize, (height)*(fieldSize.y + borderSize) + borderSize));
}

void Table::SetFieldSize(sf::Vector2f fieldSize_)
{
	if (fieldSize_.x > 0 && fieldSize_.y > 0) {
		fieldSize = fieldSize_;
		tableSize.x = size.x*(fieldSize.x + borderSize);
		tableSize.y = size.y*(fieldSize.y + borderSize);
		Update(position.x, position.y, size.x, size.y);
	}
}
void Table::SetSize(Vector2f size_)
{
	if (size_.x > 0 && size_.y > 0) {
		Vector2f sizeTemp = size;
		std::shared_ptr<IDrawable>** elementsTemp(elements);
		size = size_;
		fieldSize.x = (tableSize.x - borderSize * size.x) / size.x;
		fieldSize.y = (tableSize.y - borderSize * size.y) / size.y;
		elements = new std::shared_ptr<IDrawable> *[size.y];
		for (size_t i = 0; i < size.y; i++)
		{
			elements[i] = new std::shared_ptr<IDrawable>[size.x];
		}

		for (int i = 0; i < sizeTemp.y && i < size.y; i++)
		{
			for (int j = 0; j < sizeTemp.x && j < size.x; j++)
			{
				if (elementsTemp[i][j] != NULL)
					elements[i][j] = elementsTemp[i][j];
			}
		}



		Update(position.x, position.y, size.x, size.y);
	}
}
void Table::SetBorderSize(int borderSize_)
{
	borderSize = borderSize_;
	Update(position.x, position.y, size.x, size.y);
}
int Table::GetBorderSize()
{
	return borderSize;
}

sf::Vector2f Table::GetFieldSize()
{
	return fieldSize;
}

void Table::AddElement(std::shared_ptr<IDrawable> element, int i, int j)
{
	elements[i][j] = element;
	Update(position.x, position.y, size.x, size.y);
}


void Table::AddElement(std::shared_ptr<IDrawable> element)
{
	elements[0][0] = element;
	Update(position.x, position.y, size.x, size.y);
}
#include "TextBox.h"

TextField::TextField(RenderWindow* renderWindow_, float x, float y, float width, float height, std::string text_, TextStyle *tstyle, GUIStyle *gstyle) : GUIBox(renderWindow_, x, y, width, height, gstyle)
{
	text = text_;
	txt.setPosition(this->GetPosition().x + 2, this->GetPosition().y + 2);
	txt.setCharacterSize(this->GetSize().y / 1.5);
	txt.setFont(tstyle->font);
	txt.setFillColor(Color::Black);
	txt.setString(text);
	focus = false;
	currText = text;
	position = 0;
	Recalc();
}

void TextField::ReText(char _tmp)
{
	text.erase(text.size() - 1);

	if (_tmp != 8)
	{
		text += _tmp;
	}
	else
	{
		if (text.size() > 0) {
			text.erase(text.size() - 1);
		}
	}
	text += "|";
	currText = text;
	txt.setString(text);
	
	if (txt.getGlobalBounds().width > field.getSize().x - 10)
	{
		if (_tmp != 8) {
			position++;
			currText = text;
			currText.erase(currText.begin(), currText.begin() + position);
			txt.setString(currText);
		}
		else
		{
			if (position > 0) position--;
			//std::cout << position << std::endl;
			currText = text;
			currText.erase(currText.begin(), currText.begin() + position);
			//std::cout << currText << std::endl;
			txt.setString(currText);
		}
	}
}

bool TextField::Select()
{
	return focus;
}

bool TextField::Select(Vector2i _mouse)
{
	if ((_mouse.x > GetPosition().x && _mouse.x < GetPosition().x + GetSize().x) && (_mouse.y > GetPosition().y && _mouse.y < GetPosition().y + GetSize().y)) 	//���� ����� ������ ��� �������� TextField...
	{
		focus = true;																	   	// ����� true
		text += "|";																// � ����� ������ �������� | (��� �� �������� ��� TextField � ������)
		if (text.size() > 1 && text[text.size() - 1] == 124 && text[text.size() - 2] == 124)
			text.erase(text.size() - 1);
		txt.setString(text);
		currText += "|";
		if (currText.size() > 1 && currText[currText.size() - 1] == 124 && currText[currText.size() - 2] == 124)
			currText.erase(currText.size() - 1);
		txt.setString(currText);
	}
	else {																				//...����� ���� ������� ��������� �� ��� ��������, ��...
		if (text.size() > 0) {																// �������� ���������� �������(����� ��������)
			if (text[text.size() - 1] == 124) {													// ���� ������ | ...
				text.erase(text.size() - 1);														// ... �� ������� ���
			}
			if (currText[currText.size() - 1] == 124) {													// ���� ������ | ...
				currText.erase(currText.size() - 1);														// ... �� ������� ���
			}
			txt.setString(currText);
		}
		focus = false;
	}
	return focus;
}

/*Text TextField::DisplayText()
{
	txt.setString(text);     // ��������� � ��������� ����� ����������� �����
	return txt;
}*/

void TextField::Draw()
{
	renderWindow->draw(field);
	renderWindow->draw(txt);
}

void TextField::Recalc()
{
	Vector2f pos = GetPosition();
	Vector2f sz = GetSize();
	float posX = pos.x;
	float posY = pos.y;
	float width = sz.x;
	float height = sz.y;

	field.setPosition(posX, posY);
	field.setSize(Vector2f(width, height));
	field.setFillColor(Color::White);
	field.setOutlineThickness(2);
	field.setOutlineColor(Color(66, 66, 66));

}

void TextField::handleEvent(const sf::Event& event)
{
	if (event.type == sf::Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			//Vector2i mouse = Mouse::getPosition(*renderWindow); // ��������� ���������� ����
			Vector2i mouse = Vector2i(int(event.mouseButton.x), int(event.mouseButton.y));
			Select(mouse);
			//std::cout << mouse.x <<" "<<mouse.y<< std::endl;
		}
	}
	if (event.type == sf::Event::TextEntered)
	{
		if (Select()) {
			ReText(event.text.unicode);
		}
	}
	//txt.setString(text);
	//(*renderWindow).draw(DisplayText());
}

void TextField::SetPosition(float x, float y)
{
	IDisplayable::SetPosition(x, y);
	txt.setPosition(x + 2, y + 2);
	Recalc();
}

void TextField::SetSize(float width, float height)
{
	IDisplayable::SetSize(width, height);
	txt.setCharacterSize(height / 1.5);
	Recalc();
}

std::string TextField::ReadText()
{
	std::string oldText = text;
	if (oldText[oldText.size() - 1] == 124)
		oldText.erase(oldText.size() - 1);
	return oldText;
}
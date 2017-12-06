#include"../PasswordField/PasswordField.h"
#include<vector>
#include<string>


PasswordField::PasswordField(RenderWindow* renderWindow_, float x, float y, float width, float height, std::string text_, TextStyle *tstyle, GUIStyle *gstyle, std::string correct_) : GUIBox(renderWindow_, x, y, width, height, gstyle)
{
    //PasswordText
    text = text_;
    textIn = text_;
    txt.setPosition(this->GetPosition().x, this->GetPosition().y);
    txt.setFillColor(Color::Black);
    txt.setCharacterSize(this->GetSize().y / 2);
    txt.setFont(tstyle->font);
    txt.setString(text);
    inField = false;
    correct = correct_;

    //ButtonText
    textButt = "WATCH";
    txtButt.setPosition(this->GetPosition().x - 60 + 3, this->GetPosition().y + height / 3 - 2);
    txtButt.setFillColor(Color::Black);
    txtButt.setCharacterSize(this->GetSize().y / 3);
    txtButt.setFont(tstyle->font);
    txtButt.setString(textButt);
    inFieldButt = false;

    //Set information for fields
    Recalc();


}


void PasswordField::Draw()
{
    renderWindow->draw(field);
    renderWindow->draw(txt);
    renderWindow->draw(fieldButt);
    renderWindow->draw(txtButt);
}

//Is mouse in the password field? 
bool PasswordField::Inside(Vector2i mouse)
{
    if ((mouse.x > GetPosition().x && mouse.x < GetPosition().x + GetSize().x) && (mouse.y > GetPosition().y && mouse.y < GetPosition().y + GetSize().y))
    {
        inField = true;
    }
    else {
        inField = false;
    }

    return inField;
}

//Is mouse in the Button field? 
bool PasswordField::InsideButt(Vector2i mouse)
{
    if ((mouse.x + 60 > GetPosition().x && mouse.x + 60 < GetPosition().x + 40) && (mouse.y > GetPosition().y && mouse.y < GetPosition().y + GetSize().y))
    {
        inFieldButt = true;
    }
    else {
        inFieldButt = false;
    }

    return inFieldButt;
}

Text PasswordField::Display()
{
    txt.setString(text);
    return txt;
}

Text PasswordField::DisplayButt()
{
    txtButt.setString(textButt);
    return txtButt;
}


void PasswordField::handleEvent(const sf::Event& event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            Vector2i mouse = Mouse::getPosition(*renderWindow);
            Inside(mouse);
            InsideButt(mouse);
            if (Inside(mouse) && press == false)
            {
                text = "";
                press = true;
            }
            if (Inside(mouse) && !InsideButt(mouse))
                fieldPass = true;
            else
                if (!InsideButt(mouse))
                {
                    text = textIn;
                    press = false;
                }

            if (InsideButt(mouse))
            {
                buttPass = true;
                int i = 0;
                for (int j = 0; j < vect.size(); j++)
                {

                    if (i < text.size())
                    {
                        text[i] = vect[j];
                    }
                    i++;
                }
                txt.setString(text);
            }
            if (!Inside(mouse) && !InsideButt(mouse))
            {
                vect.clear();
            }
        }
    }

    if (event.type == sf::Event::TextEntered)
    {
        Vector2i mouse = Mouse::getPosition(*renderWindow);
        if (fieldPass)
        {

            if (event.text.unicode < 128 && event.text.unicode != 8 && event.text.unicode != 13)
            {
                text += static_cast<char>(event.text.unicode);

                vect.push_back(event.text.unicode);


                if (!buttPass)
                {
                    for (int i = 0; i < text.size(); i++)
                    {
                        text[i] = '*';
                    }
                }
                if (buttPass)
                {
                    int i = 0;
                    for (int j = 0; j < vect.size(); j++)
                    {
                        if (i < text.size())
                        {
                            text[i] = vect[j];
                        }
                        i++;
                    }
                    buttPass = false;
                }
                txt.setString(text);

            }
            else
            {
                if (event.text.unicode == 13)
                {
                    bool right = false;

                    if (vect.size() == correct.size())
                    {
                        for (int i = 0; i < correct.size(); i++)
                        {
                            if (correct[i] == vect[i])
                            {
                                right = true;
                            }
                            else right = false;
                        }
                        if (right)
                        {
                            text = "Right Password!";
                            txt.setString(text);
                            press = false;
                            vect.clear();
                        }
                    }
                    else
                    {
                        text = "False Password!";
                        txt.setString(text);
                        press = false;
                        vect.clear();

                    }
                }
                else
                {
                    if (text.size() > 0 && event.text.unicode == 8)
                    {
                        vect.pop_back();
                        text.erase(text.size() - 1);
                    }
                }
            }
        }
    }
    txt.setString(text);
}


//Set inform�tion for fields(password and button)
void PasswordField::Recalc()
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

    fieldButt.setPosition(posX - 60, posY);
    fieldButt.setSize(Vector2f(40, height));
    fieldButt.setFillColor(Color::White);
}
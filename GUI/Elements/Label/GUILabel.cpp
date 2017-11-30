#include "GUILabel.h"


void GUILabel::FindFitSizeOfFont(Vector2f size_)
{
    /*text.setCharacterSize(static_cast<unsigned int>(size_.y) + 3);
    sf::FloatRect bounds = text.getLocalBounds();

    if (bounds.width > size_.x)
    {
        text.setCharacterSize(static_cast<unsigned int>((size_.y * size_.x) / bounds.width) + 1);
    }*/
    unsigned int first = 0, second = 0;
    bool width = true;
    if (size_.x > size.y)
    {
        first = size_.x;
        second = size_.y;
        width = false;
    }
    else
    {
        first = size_.y;
        second = size_.x;
    }
    text.setCharacterSize(static_cast<unsigned int>(first));
    sf::FloatRect bounds = text.getLocalBounds();

    if ((bounds.width > second) && (width == true))
    {
        text.setCharacterSize(static_cast<unsigned int>((first * second) / bounds.width));
    }
    else if ((bounds.height > second) && (width == false))
    {
        text.setCharacterSize(static_cast<unsigned int>((first * second) / bounds.height));
    }
}

GUILabel::GUILabel(RenderWindow* renderWindow_, float x, float y, float width,
    float height, std::string text_, TextStyle *Ctstyle, GUIStyle *Cgstyle) :
    GUIBox(renderWindow_, x, y, width, height, Cgstyle),
    tstyle(Ctstyle), iconT(nullptr), icon(nullptr) // отличие такого присваивания
{
    text.setString(text_);
    text.setFont(tstyle->font);
    text.setFillColor(tstyle->color);

    rect = new RectangleShape(Vector2f(width, height));
    rect->setFillColor(Color::Transparent);
    rect->setOutlineColor(Color::Red);
    rect->setOutlineThickness(1);
    rect->setPosition(x, y);

    Recalc();
}

GUILabel::GUILabel(RenderWindow* renderWindow_, Vector2f position_, Vector2f size_,
    std::string text_, TextStyle *Ctstyle, GUIStyle *Cgstyle) :
    GUIBox(renderWindow_, position_, size_, Cgstyle),
    tstyle(Ctstyle), iconT(nullptr), icon(nullptr)
{
    text.setString(text_);
    text.setFont(tstyle->font);
    text.setFillColor(tstyle->color);

    rect = new RectangleShape(size_);
    rect->setFillColor(Color::Transparent);
    rect->setOutlineColor(Color::Red);
    rect->setOutlineThickness(1);
    rect->setPosition(position_);

    Recalc();
}

GUILabel::GUILabel(RenderWindow * renderWindow_, float x, float y, float width,
    float height, std::string text_, TextStyle * Ctstyle, Texture * icon_, GUIStyle *Cgstyle) :
    GUIBox(renderWindow_, x, y, width, height, Cgstyle),
    tstyle(Ctstyle), iconT(icon_)
{
    text.setString(text_);
    text.setFont(tstyle->font);
    text.setFillColor(tstyle->color);
    icon = new Sprite(*iconT);
    rect = new RectangleShape(Vector2f(width, height));
    rect->setFillColor(Color::Transparent);
    rect->setOutlineColor(Color::Red);
    rect->setOutlineThickness(1);
    rect->setPosition(x, y);
    Recalc();
}

GUILabel::GUILabel(RenderWindow * renderWindow_, Vector2f position_, Vector2f size_,
    std::string text_, TextStyle * Ctstyle, Texture * icon_, GUIStyle *Cgstyle) :
    GUIBox(renderWindow_, position_, size_, Cgstyle),
    tstyle(Ctstyle), iconT(icon_)
{
    text.setString(text_);
    text.setFont(tstyle->font);
    text.setFillColor(tstyle->color);
    icon = new Sprite(*iconT);
    rect = new RectangleShape(size_);
    rect->setFillColor(Color::Transparent);
    rect->setOutlineColor(Color::Red);
    rect->setOutlineThickness(1);
    rect->setPosition(position_);
    Recalc();
}

void GUILabel::Draw()
{
    IDrawable::Draw(); 
    Recalc();

    if (text.getString() != "")
    {
        renderWindow->draw(text);
    }
    if (icon != nullptr)
    {
        renderWindow->draw(*icon);
    }
    if (rect != nullptr)
    {
        renderWindow->draw(*rect);
    }
}

void GUILabel::Recalc()
{
    //text.setOrigin(10,10);
    

    Vector2f pos = GetPosition();
    Vector2f sz = GUIBox::GetSize();
    float posX = pos.x;
    float posY = pos.y;
    float width = sz.x;
    float height = sz.y;

    float iconX = 0;
    float iconY = 0;
    FloatRect textRect = text.getLocalBounds();
    float textX = textRect.left + textRect.width / 2.0f;
    float textY = textRect.top + textRect.height / 2.0f;

    text.setOrigin(textX, textY); // center
    /*
    text.setCharacterSize(static_cast<unsigned int>(size_.y));
    sf::FloatRect bounds = text.getLocalBounds();

    if (bounds.width > size_.x)
    {
        text.setCharacterSize(static_cast<unsigned int>((size_.y * size_.x) / bounds.width));
    }
    */

    if (isDependsOnSize)
    {
        FindFitSizeOfFont(GetSize());
        std::cout << text.getCharacterSize() << std::endl;
    }
    else
    {
        text.setCharacterSize(15);
    }
    //text.setOrigin(0, 0);
    //FloatRect textRect = text.getLocalBounds();

    /*if (icon != nullptr)
    {
        icon->setPosition(posX, posY);
        //(icon->setOrigin;)
        icon->setScale(0.5, 0.5);
        iconX = icon->getGlobalBounds().width + textRect.width / 2.0f;
        iconY = icon->getGlobalBounds().height / 2.0f;
        text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        //text.setPosition(Vector2f(posX + icon->getGlobalBounds().width, posY + (height / 2.0f)));
    }*/

    text.setPosition(Vector2f(posX + iconX + size.x/2, posY + iconY + size.y/2)); // зависит от alignment

    //icon->getGlobalBounds().width;
    /*
    if (tstyle->align == 'c')
    {
    FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    text.setPosition(Vector2f(posX + (width / 2.0f), posY + (height / 2.0f)));
    }
    if (tstyle->align == 'l')
    text.setPosition(Vector2f(posX + 1, posY + 1));
    */
}
/*
void GUILabel::SetSize(float width, float height)
{
    text.setCharacterSize(static_cast<unsigned int>(height));
    sf::FloatRect bounds = text.getLocalBounds();

    if (bounds.width > width)
    {
        text.setCharacterSize(static_cast<unsigned int>((height * width) / bounds.width));
    }
    bounds = text.getLocalBounds();
}

void GUILabel::SetSize(Vector2f size_)
{
    text.setCharacterSize(static_cast<unsigned int>(size_.y));
    sf::FloatRect bounds = text.getLocalBounds();

    if (bounds.width > size_.x)
    {
        text.setCharacterSize(static_cast<unsigned int>((size_.y * size_.x) / bounds.width));
    }
}
*/
void GUILabel::SetSizeOfText(unsigned int size)
{
}

unsigned int GUILabel::GetSizeOfText() const
{
    return 0;
}


void GUILabel::SetIcon(Texture * iconT)
{
    this->iconT = iconT;
    if (icon != nullptr)
    {
        delete icon;
    }
    icon = new Sprite(*iconT);
}

Texture * GUILabel::GetIcon() const
{
    return nullptr;
}

void GUILabel::SetText(char * text)
{
    this->text.setString(text);
}

char * GUILabel::GetText() const
{
    return nullptr;
}

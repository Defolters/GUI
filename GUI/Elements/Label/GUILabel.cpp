#include "GUILabel.h"

GUILabel::GUILabel(RenderWindow* renderWindow_, float x, float y, float width,
    float height, std::string text_, TextStyle *Ctstyle, GUIStyle *Cgstyle) :
    GUIBox(renderWindow_, x, y, width, height, Cgstyle)
{
    tstyle = Ctstyle;
    text.setString(text_);
    text.setFont(tstyle->font);
    SetSize(width, height);
    text.setFillColor(tstyle->color);
    iconT = nullptr;
    icon = nullptr;
    Recalc();
}

GUILabel::GUILabel(RenderWindow* renderWindow_, Vector2f position_, Vector2f size_,
    std::string text_, TextStyle *Ctstyle, GUIStyle *Cgstyle) :
    GUIBox(renderWindow_, position_, size_, Cgstyle)
{
    tstyle = Ctstyle;
    text.setString(text_);
    text.setFont(tstyle->font);
    SetSize(size_);
    text.setFillColor(tstyle->color);
    iconT = nullptr;
    icon = nullptr;
    Recalc();
}

GUILabel::GUILabel(RenderWindow * renderWindow_, float x, float y, float width,
    float height, std::string text_, TextStyle * Ctstyle, Texture * icon_, GUIStyle *Cgstyle) :
    GUIBox(renderWindow_, x, y, width, height, Cgstyle)

{
    tstyle = Ctstyle;
    text.setString(text_);
    text.setFont(tstyle->font);
    SetSize(width, height);
    text.setFillColor(tstyle->color);
    iconT = icon_;
    icon = new Sprite(*iconT);
    Recalc();
}

GUILabel::GUILabel(RenderWindow * renderWindow_, Vector2f position_, Vector2f size_,
    std::string text_, TextStyle * Ctstyle, Texture * icon_, GUIStyle *Cgstyle) :
    GUIBox(renderWindow_, position_, size_, Cgstyle)

{
    tstyle = Ctstyle;
    text.setString(text_);
    text.setFont(tstyle->font);
    SetSize(size_);
    text.setFillColor(tstyle->color);
    iconT = icon_;
    icon = new Sprite(*iconT);
    Recalc();
}

void GUILabel::Draw()
{
    IDrawable::Draw(); //если бы это строчка была раскоменчена, то Label рисовал бы дочерние элементы
    Recalc();
    if (text.getString() != "")
    {
        renderWindow->draw(text);
    }
    if (icon != nullptr)
    {
        renderWindow->draw(*icon);
    }
}

void GUILabel::Recalc()
{
    Vector2f pos = GetPosition();
    Vector2f sz = GetSize();
    float posX = pos.x;
    float posY = pos.y;
    float width = sz.x;
    float height = sz.y;

    float iconX = 0;
    float iconY = 0;


    FloatRect textRect = text.getLocalBounds();

    if (icon != nullptr)
    {
        icon->setPosition(posX, posY);
        icon->setScale(1, 1);
        iconX = icon->getGlobalBounds().width + textRect.width / 2.0f;
        iconY = icon->getGlobalBounds().height / 2.0f;
        text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        //text.setPosition(Vector2f(posX + icon->getGlobalBounds().width, posY + (height / 2.0f)));
    }

    text.setPosition(Vector2f(posX + iconX, posY + iconY));

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

void GUILabel::handleEvent(const sf::Event & event)
{
}

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

unsigned int GUILabel::getSize()
{
    return text.getCharacterSize();
}

void GUILabel::setIcon(Texture * iconT)
{
    this->iconT = iconT;
    icon = new Sprite(*iconT);
}

void GUILabel::SetText(char * text)
{
    this->text.setString(text);
}

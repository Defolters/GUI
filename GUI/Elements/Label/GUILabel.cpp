#include "GUILabel.h"


void GUILabel::FindFitSizeOfFont(const Vector2f& size_)
{
    text.setCharacterSize(static_cast<unsigned int>(size_.y) + 3);
    sf::FloatRect bounds = text.getLocalBounds();

    if (bounds.width > size_.x)
    {
        text.setCharacterSize(static_cast<unsigned int>((size_.y * size_.x) / bounds.width) + 1);
    }
}

void GUILabel::FindFitScaleOfImage(const Vector2f& size_)
{
    while (icon->getGlobalBounds().width > size_.x)
    {
        icon->scale(0.9, 0.9);
    }
    while (icon->getGlobalBounds().height > size_.y)
    {
        icon->scale(0.9, 0.9);
    }
}

GUILabel::GUILabel(RenderWindow* renderWindow_, float x, float y, float width,
    float height, std::string text_, TextStyle *Ctstyle, GUIStyle *Cgstyle) :
    GUIBox(renderWindow_, x, y, width, height, Cgstyle),
    tstyle(Ctstyle), iconT(nullptr), icon(nullptr), isDependsOnSize(true) // отличие такого присваивания
{
    text.setString(text_);
    text.setFont(tstyle->font);
    text.setFillColor(tstyle->color);
    text.setCharacterSize(tstyle->fontSize);
    rect = new RectangleShape(Vector2f(width, height));
    rect->setFillColor(Color::Transparent);
    rect->setOutlineColor(Color::Red);
    rect->setOutlineThickness(1);
    rect->setPosition(x, y);
}

GUILabel::GUILabel(RenderWindow* renderWindow_, Vector2f position_, Vector2f size_,
    std::string text_, TextStyle *Ctstyle, GUIStyle *Cgstyle) :
    GUIBox(renderWindow_, position_, size_, Cgstyle),
    tstyle(Ctstyle), iconT(nullptr), icon(nullptr), isDependsOnSize(true)
{
    text.setString(text_);
    text.setFont(tstyle->font);
    text.setFillColor(tstyle->color);
    text.setCharacterSize(tstyle->fontSize);
    rect = new RectangleShape(size_);
    rect->setFillColor(Color::Transparent);
    rect->setOutlineColor(Color::Red);
    rect->setOutlineThickness(1);
    rect->setPosition(position_);
}

GUILabel::GUILabel(RenderWindow* renderWindow_, float x, float y, float width,
    float height, std::string text_, TextStyle* Ctstyle, Texture* icon_, GUIStyle* Cgstyle) :
    GUIBox(renderWindow_, x, y, width, height, Cgstyle),
    tstyle(Ctstyle), iconT(icon_), isDependsOnSize(true)
{
    text.setString(text_);
    text.setFont(tstyle->font);
    text.setFillColor(tstyle->color);
    text.setCharacterSize(tstyle->fontSize);
    icon = new Sprite(*iconT);
    rect = new RectangleShape(Vector2f(width, height));
    rect->setFillColor(Color::Transparent);
    rect->setOutlineColor(Color::Red);
    rect->setOutlineThickness(1);
    rect->setPosition(x, y);
}

GUILabel::GUILabel(RenderWindow* renderWindow_, Vector2f position_, Vector2f size_,
    std::string text_, TextStyle* Ctstyle, Texture* icon_, GUIStyle* Cgstyle) :
    GUIBox(renderWindow_, position_, size_, Cgstyle),
    tstyle(Ctstyle), iconT(icon_), isDependsOnSize(true)
{
    text.setString(text_);
    text.setFont(tstyle->font);
    text.setFillColor(tstyle->color);
    text.setCharacterSize(tstyle->fontSize);
    icon = new Sprite(*iconT);
    rect = new RectangleShape(size_);
    rect->setFillColor(Color::Transparent);
    rect->setOutlineColor(Color::Red);
    rect->setOutlineThickness(1);
    rect->setPosition(position_);
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
    if ((rect != nullptr) && ((text.getString() == "") || (icon == nullptr)))
    {
        renderWindow->draw(*rect);
    }
}

void GUILabel::Recalc()
{
    rect->setSize(GetSize());
    Vector2f positionOfBox = GetPosition(); // позиция нашего объекта
    Vector2f sizeOfBox = GUIBox::GetSize(); // размер нашего объекта
    float width = sizeOfBox.x;
    float height = sizeOfBox.y;

    text.setFillColor(Color::Green);
    FloatRect textRect = text.getLocalBounds();
    float textX = textRect.left + textRect.width / 2.0f;
    float textY = textRect.top + textRect.height / 2.0f;

    if (icon != nullptr)
    {
        textRect = icon->getLocalBounds();
        float textX = textRect.left + textRect.width / 2.0f;
        float textY = textRect.top + textRect.height / 2.0f;
    }

    Vector2f position;
    Vector2f origin;

    if (horizontalAlignment == Alignment::LEFT)
    {
        origin.x = textRect.left;
        position.x = positionOfBox.x;
    }
    else if (horizontalAlignment == Alignment::RIGHT)
    {
        origin.x = textRect.left + textRect.width;
        position.x = positionOfBox.x + size.x;
    }
    else
    {
        origin.x = textRect.left + textRect.width / 2.0f;
        position.x = positionOfBox.x + size.x / 2;
    }


    if (verticalAlignment == Alignment::TOP)
    {
        origin.y = textRect.top;
        position.y = positionOfBox.y;
    }
    else if (verticalAlignment == Alignment::BOTTOM)
    {
        origin.y = textRect.top + textRect.height;
        position.y = positionOfBox.y + size.y;
    }
    else
    {
        origin.y = textRect.top + textRect.height / 2.0f;
        position.y = positionOfBox.y + size.y / 2;
    }

    if (text.getString() != "" && icon != nullptr)
    {
        icon->setOrigin(origin);
        icon->setPosition(position);

        if (textToIconAlignment == Alignment::LEFT)
        {
            text.setOrigin(text.getLocalBounds().left + text.getLocalBounds().width, (text.getLocalBounds().top + text.getLocalBounds().height) / 2);
            text.setPosition(icon->getGlobalBounds().left - GapBetweenIconText, icon->getGlobalBounds().top + icon->getGlobalBounds().height / 2);
        }
        else if (textToIconAlignment == Alignment::RIGHT)
        {
            text.setOrigin(text.getLocalBounds().left, (text.getLocalBounds().top + text.getLocalBounds().height) / 2);
            text.setPosition(icon->getGlobalBounds().left + icon->getGlobalBounds().width + GapBetweenIconText, icon->getGlobalBounds().top + icon->getGlobalBounds().height / 2);
        }
        else if (textToIconAlignment == Alignment::TOP)
        {
            text.setOrigin((text.getLocalBounds().left + text.getLocalBounds().width) / 2, text.getLocalBounds().top + text.getLocalBounds().height);
            text.setPosition(icon->getGlobalBounds().left + icon->getGlobalBounds().width / 2, icon->getGlobalBounds().top - GapBetweenIconText);
        }
        else if (textToIconAlignment == Alignment::BOTTOM)
        {
            text.setOrigin((text.getLocalBounds().left + text.getLocalBounds().width) / 2, text.getLocalBounds().top);
            text.setPosition(icon->getGlobalBounds().left + icon->getGlobalBounds().width / 2, icon->getGlobalBounds().top + icon->getGlobalBounds().height + GapBetweenIconText);
        }
        else if (textToIconAlignment == Alignment::CENTER)
        {
            text.setOrigin(text.getLocalBounds().left + text.getLocalBounds().width / 2, text.getLocalBounds().top + text.getLocalBounds().height / 2);
            text.setPosition(icon->getGlobalBounds().left + icon->getGlobalBounds().width / 2, icon->getGlobalBounds().top + icon->getGlobalBounds().height / 2);
        }
    }
    else if (icon != nullptr)
    {
        icon->setOrigin(origin);
        icon->setPosition(position);
    }
    else
    {
        text.setOrigin(origin);
        text.setPosition(position);
    }

    if (isDependsOnSize && ((text.getString() == "") || (icon == nullptr)))
    {
        if (text.getString() != "")
        {
            FindFitSizeOfFont(GetSize());
        }
        if (icon != nullptr)
        {
            icon->setScale(1, 1);
            FindFitScaleOfImage(GetSize());
        }
    }
}

void GUILabel::SetSizeOfText(const unsigned int size)
{
    text.setCharacterSize(size);
}

unsigned int GUILabel::GetSizeOfText() const
{
    return text.getCharacterSize();
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

Texture* GUILabel::GetIcon() const
{
    return iconT;
}

void GUILabel::SetText(char* text)
{
    this->text.setString(text);
}

String GUILabel::GetText() const
{
    return text.getString();
}

void GUILabel::SetHorizontalAlignment(const Alignment aligment)
{
    horizontalAlignment = aligment;
}

void GUILabel::SetVerticalAlignment(const Alignment aligment)
{
    verticalAlignment = aligment;
}

Alignment GUILabel::GetHorizontalAlignment()
{
    return horizontalAlignment;
}

Alignment GUILabel::GetVerticalAlignment()
{
    return verticalAlignment;
}

void GUILabel::SetTextToIconAlignment(const Alignment aligment)
{
    textToIconAlignment = aligment;
}

Alignment GUILabel::GetTextToIconAlignment()
{
    return textToIconAlignment;
}

void GUILabel::SetGapBetweenIconText(unsigned int gap)
{
    GapBetweenIconText = gap;
}

unsigned int GUILabel::GetGapBetweenIconText()
{
    return GapBetweenIconText;
}

void GUILabel::SetDependsOnSize(bool state)
{
    isDependsOnSize = state;
}

bool GUILabel::GetDependsOnSize()
{
    return isDependsOnSize;
}

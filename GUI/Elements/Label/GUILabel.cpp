#include "GUILabel.h"

GUILabel::GUILabel(RenderWindow* renderWindow_, float x, float y, float width, 
    float height, std::string text_, TextStyle *Ctstyle, GUIStyle *Cgstyle) : 
    GUIBox(renderWindow_, x, y, width, height, text_, Ctstyle, Cgstyle) 
{
    gstyle = Cgstyle;
    tstyle = Ctstyle;
    text.setString(text_);
    text.setFont(tstyle->font);
    text.setCharacterSize(tstyle->fontSize);
    text.setFillColor(tstyle->color);
    iconT = nullptr;
    icon = nullptr;
    Recalc();
    // вопро
    //action = Caction;
    //clicked = false;
}

GUILabel::GUILabel(RenderWindow* renderWindow_, Vector2f position_, Vector2f size_,
    std::string text_, TextStyle *Ctstyle, GUIStyle *Cgstyle) :
    GUIBox(renderWindow_, position_, size_, text_, Ctstyle, Cgstyle)
{
    gstyle = Cgstyle;
    tstyle = Ctstyle;
    text.setString(text_);
    text.setFont(tstyle->font);
    text.setCharacterSize(tstyle->fontSize);
    text.setFillColor(tstyle->color);
    iconT = nullptr;
    icon = nullptr;
    Recalc();
    // вопро
    //action = Caction;
    //clicked = false;
}

/*
GUILabel::GUILabel(RenderWindow * renderWindow_, float x, float y, float width, float height, Texture * icon_, std::string text_, TextStyle *Ctstyle, GUIStyle *Cgstyle) :
    GUIBox(renderWindow_, x, y, width, height, text_, Ctstyle, Cgstyle)
{
    gstyle = Cgstyle;
    tstyle = Ctstyle;
    text.setString(text_);
    text.setFont(tstyle->font);
    text.setCharacterSize(tstyle->fontSize);
    text.setFillColor(tstyle->color);
    Recalc();
}

GUILabel::GUILabel(RenderWindow * renderWindow_, Vector2f position_, Vector2f size_, Texture * icon_, std::string text_, TextStyle *Ctstyle, GUIStyle *Cgstyle)
{
}*/

GUILabel::GUILabel(RenderWindow * renderWindow_, float x, float y, float width, float height, std::string text_, TextStyle * Ctstyle, Texture * icon_, GUIStyle *Cgstyle):
    GUIBox(renderWindow_, x, y, width, height, text_, Ctstyle, Cgstyle)

{
    gstyle = Cgstyle;
    tstyle = Ctstyle;
    text.setString(text_);
    text.setFont(tstyle->font);
    text.setCharacterSize(tstyle->fontSize);
    text.setFillColor(tstyle->color);
    iconT = icon_;
    icon = new Sprite(*iconT);
    Recalc();
}

GUILabel::GUILabel(RenderWindow * renderWindow_, Vector2f position_, Vector2f size_, std::string text_, TextStyle * Ctstyle, Texture * icon_, GUIStyle *Cgstyle):
    GUIBox(renderWindow_, position_, size_, text_, Ctstyle, Cgstyle)

{
    gstyle = Cgstyle;
    tstyle = Ctstyle;
    text.setString(text_);
    text.setFont(tstyle->font);
    text.setCharacterSize(tstyle->fontSize);
    text.setFillColor(tstyle->color);
    iconT = icon_;
    icon = new Sprite(*iconT);
    Recalc();
}

void GUILabel::Draw()
{
    /*renderWindow->draw(sprite);
    renderWindow->draw(frames[0]);
    renderWindow->draw(frames[1]);
    renderWindow->draw(frames[2]);
    renderWindow->draw(frames[3]);/**/
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
    //
    if (icon != nullptr)
    {
        icon->setPosition(posX, posY);
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
    sprite.setTexture(gstyle->mainTex);
    sprite.setPosition(posX, posY);
    sprite.setTextureRect(IntRect(0, 0, width, height));
    for (int i = 0; i < 4; i++)
        frames[i].setTexture(gstyle->frame);
    frames[0].setTextureRect(IntRect(0, 0, gstyle->frameWid, width));
    frames[1].setTextureRect(IntRect(0, 0, gstyle->frameWid, width));
    frames[2].setTextureRect(IntRect(0, 0, gstyle->frameWid, height));
    frames[3].setTextureRect(IntRect(0, 0, gstyle->frameWid, height));
    frames[0].setPosition(posX, posY + gstyle->frameWid);
    frames[1].setPosition(posX, posY + height);
    frames[0].setRotation(-90);
    frames[1].setRotation(-90);
    frames[2].setPosition(posX, posY);
    frames[3].setPosition(posX + width - gstyle->frameWid, posY);

}

#include "../../GUI/GUILayer.h"
#include "MenuBar.h"




void MenuBar::addButton(std::string name, void(*action)())

{
    //пример создания стиля gui
    static GUIStyle gst;
    gst.mainTex.loadFromFile("resources/03.png");
    gst.pressTex.loadFromFile("resources/04.png");
    gst.overTex.loadFromFile("resources/05.png");

    gst.frameWid = 3;

    //пример создания стиля текста
    static TextStyle tst;
    tst.font.loadFromFile("resources/Robotic.ttf");
    tst.color.r = tst.color.g = tst.color.b = 255;
    tst.fontSize = 30;
    tst.align = 'c';

    std::shared_ptr<GUIButton> box;

    box = layer->CreateButton(buttonPosHelp, 5, buttonSizeHelp, 40, name, &tst, &gst, action);
    buttonVect.push_back(box);
    AddElement(box);

    ///resizing test

    ///
    buttonPosHelp = buttonPosHelp + buttonSizeHelp;
}
void MenuBar::Draw()
{
    GUIBox::Draw();
    IDrawable::Draw();
}

void MenuBar::SetSize(Vector2f size_)
{
    GUIBox::SetSize(size_);
    buttonVect[0]->SetSize(size_);
    buttonVect[1]->SetSize(size_);
    buttonVect[2]->SetSize(size_);
    buttonVect[3]->SetSize(size_);


}
void MenuBar::SetSize(Vector2f size_, Vector2f coefficient_)
{

}
void MenuBar::SetPosition(Vector2f position_)
{
    Vector2f posButton;
    GUIBox::SetPosition(position_);
    int step = 0;
    for (int i = 0; i < 4; i++)
    {
        buttonVect[i]->SetPosition(position_.x + step, position_.y + 5);
        step += buttonSizeHelp;
    }
    staticBar->setPosition(position_.x, position_.y);
}
void MenuBar::SetPosition(Vector2f position_, Vector2f coefficient_)
{

}
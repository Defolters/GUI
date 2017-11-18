#pragma once
#include "../../GUI/GUIBox.h"
class GUILabel : public GUIBox
{
private:
    friend class GUILayer;
    GUIStyle *gstyle;
    TextStyle *tstyle;
    Sprite sprite;
    Sprite frames[4];
    Text text;
    Texture *iconT;
    Sprite *icon;
protected:

    // один текст
    GUILabel(RenderWindow* renderWindow_, float x, float y, float width, float height, std::string text, TextStyle *tstyle, GUIStyle *gstyle);
    GUILabel(RenderWindow* renderWindow_, Vector2f position_, Vector2f size_, std::string text, TextStyle *tstyle, GUIStyle *gstyle);
    //одна картинка
    /*GUILabel(RenderWindow* renderWindow_, float x, float y, float width, float height, Texture *icon_, std::string text_, TextStyle *tstyle, GUIStyle *gstyle);
    GUILabel(RenderWindow* renderWindow_, Vector2f position_, Vector2f size_, Texture *icon_, std::string text_, TextStyle *tstyle, GUIStyle *gstyle);*/
    //картинка + текст (положение?)
    GUILabel(RenderWindow* renderWindow_, float x, float y, float width, float height, std::string text, TextStyle *tstyle, Texture *icon_, GUIStyle *gstyle);
    GUILabel(RenderWindow* renderWindow_, Vector2f position_, Vector2f size_, std::string text, TextStyle *tstyle, Texture *icon_, GUIStyle *gstyle);
    
    virtual void Draw() override;
    virtual void Recalc() override;
};


#pragma once
#include "../../GUI/GUIBox.h"
class GUILabel : public GUIBox
{
private:
    friend class GUILayer;
    TextStyle *tstyle; /*!< стиль текста */
    Text text; /*!< текст */ 
    Texture *iconT; /*!< текстура иконки */ 
    Sprite *icon; /*!< иконка, которую можно нарисовать */ 

protected:
    //! Конструктор
    /*!
    Создает текстовый label
    */
    GUILabel(RenderWindow* renderWindow_, float x, float y, float width, float height, std::string text, TextStyle *tstyle, GUIStyle *gstyle);

    //! Конструктор
    /*!
    Создает текстовый label
    */
    GUILabel(RenderWindow* renderWindow_, Vector2f position_, Vector2f size_, std::string text, TextStyle *tstyle, GUIStyle *gstyle);

    //! Конструктор
    /*!
    Создает label, состоящий из одной иконки, если текст задан пустой строкой.
    Если текст задан, то создает label, содержащий иконку и текст
    \param renderWindow_ окно, в которое рисуем
    */
    GUILabel(RenderWindow* renderWindow_, float x, float y, float width, float height, std::string text, TextStyle *tstyle, Texture *icon_, GUIStyle *gstyle);
    
    //! Конструктор
    /*!
    Создает label, состоящий из одной иконки, если текст задан пустой строкой.
    Если текст задан, то создает label, содержащий иконку и текст
    \param renderWindow_ окно, в которое рисуем
    */
    GUILabel(RenderWindow* renderWindow_, Vector2f position_, Vector2f size_, std::string text, TextStyle *tstyle, Texture *icon_, GUIStyle *gstyle);
    
    void setIcon(Texture* iconT);
    virtual void SetText(char *text) override;

    //! Переопределяем функцию Draw
    virtual void Draw() override;

    //! Переопределяем функцию Recalc
    virtual void Recalc() override;
};


#pragma once
#include "../../GUI/GUIBox.h"
enum class Alignment {
    LEFT,
    CENTER,
    RIGHT,
    TOP,
    BOTTOM
};
// в скобочках в конструкторе
class GUILabel : public GUIBox
{
private:
    friend class GUILayer;

    Text text; /*!< текст */
    Texture *iconT; /*!< текстура иконки */
    Sprite *icon; /*!< иконка, которую можно нарисовать */
    TextStyle *tstyle; /*!< стиль текста */
    Alignment horizontalAlignment = Alignment::CENTER; /*!< горизонтальное выравнивание */
    Alignment verticalAlignment = Alignment::CENTER; /*!< вертикальное выравнивание */
    int iconTextGap; /*!< расстояние между иконкой и текстом */
    bool isDependsOnSize = true;
    RectangleShape *rect = nullptr;

    void FindFitSizeOfFont(Vector2f size_);

protected:

    // конструкторы икон, икон + выравнивание, строка, строка+икон+выравн, строка +выравн, пустой
    /*
    JLabel(Icon)
    // конструктор для одной иконки, tstyle нужен, чтобы потом, если вы захотите, смогли установить текст.
    GUILabel(RenderWindow* renderWindow_, float x, float y, float width, float height, Texture *icon_, TextStyle *tstyle, GUIStyle *gstyle);
    JLabel(Icon, int)
    // конструктор + alignment
    GUILabel(RenderWindow* renderWindow_, float x, float y, float width, float height, Texture *icon_, TextStyle *tstyle, GUIStyle *gstyle, Alignment alig);
    JLabel(String)
    // простой конструктор для текста
    GUILabel(RenderWindow* renderWindow_, float x, float y, float width, float height, std::string text, TextStyle *tstyle, GUIStyle *gstyle);
    JLabel(String, Icon, int)
    // конструктор icon, text, alignment
    GUILabel(RenderWindow* renderWindow_, float x, float y, float width, float height, std::string text, TextStyle *tstyle, GUIStyle *gstyle);
    JLabel(String, int)
    JLabel()
    Creates a JLabel instance, initializing it to have the specified text/image/alignment. The int argument specifies the horizontal alignment of the label's contents within its drawing area. The horizontal alignment must be one of the following constants defined in the SwingConstants interface (which JLabel implements): LEFT, CENTER, RIGHT, LEADING, or TRAILING. For ease of localization, we strongly recommend using LEADING and TRAILING, rather than LEFT and RIGHT.
    */

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

    //! Конструктор ДОБАВИТЬ В LAYER ДОБАВИТЬ ОДНУ ИКОНКУ, НО ЧТО, ЕСЛИ ПОНАДОБИТСЯ ДОБАВИТЬ ТЕКСТ?
    /*!
    Создает label, состоящий из одной иконки, если текст задан пустой строкой.
    Если текст задан, то создает label, содержащий иконку и текст
    \param renderWindow_ окно, в которое рисуем
    */
    //GUILabel(RenderWindow* renderWindow_, float x, float y, float width, float height, std::string text, TextStyle *tstyle, Texture *icon_, GUIStyle *gstyle);

    //! Конструктор
    /*!
    Создает label, состоящий из одной иконки, если текст задан пустой строкой.
    Если текст задан, то создает label, содержащий иконку и текст
    \param renderWindow_ окно, в которое рисуем
    */
    //GUILabel(RenderWindow* renderWindow_, Vector2f position_, Vector2f size_, std::string text, TextStyle *tstyle, Texture *icon_, GUIStyle *gstyle);


    //! Переопределяем функцию Draw
    virtual void Draw() override;

    //! Переопределяем функцию Recalc
    virtual void Recalc() override;

public:
    //virtual void SetSize(float width, float height) override;
    //virtual void SetSize(Vector2f size_) override;
    //float GetSize(); этот метод уже есть в базовом

    //! Sets or gets the size of text displayed by the label.
    void SetSizeOfText(unsigned int size);
    unsigned int GetSizeOfText() const;


    //! Sets or gets the image displayed by the label.
    void SetIcon(Texture* iconT);
    Texture* GetIcon() const;

    //! Sets or gets the text displayed by the label.
    virtual void SetText(char *text);
    char* GetText() const;

    /*
    void setHorizontalAlignment(int)
    void setVerticalAlignment(int)
    int getHorizontalAlignment()
    int getVerticalAlignment()
    Sets or gets the area on the label where its contents should be placed. 
    The SwingConstants interface defines five possible values for horizontal alignment: LEFT, CENTER (the default for image-only labels), 
    RIGHT, LEADING (the default for text-only labels), TRAILING. For vertical alignment: TOP, CENTER (the default), and BOTTOM.
    */

    //! Конструктор
    /*!
    Создает label, состоящий из одной иконки, если текст задан пустой строкой.
    Если текст задан, то создает label, содержащий иконку и текст
    \param renderWindow_ окно, в которое рисуем
    */
    void SetHorizontalAlignment(Alignment);
    void SetVerticalAlignment(Alignment);
    Alignment GetHorizontalAlignment();
    Alignment GetVerticalAlignment();
    /*
    void setHorizontalTextPosition(int)
    void setVerticalTextPosition(int)
    int getHorizontalTextPosition()
    int getVerticalTextPosition()
    Sets or gets the location where the label's text will be placed, relative to the label's image. 
    The SwingConstants interface defines five possible values for horizontal position: LEADING, LEFT, CENTER, RIGHT, and TRAILING (the default). 
    For vertical position: TOP, CENTER (the default), and BOTTOM.
    */
    void SetHorizontalTextPosition(Alignment);
    void SetVerticalTextPosition(Alignment);
    Alignment GetHorizontalTextPosition();
    Alignment GetVerticalTextPosition();

    //! Sets or gets the number of pixels between the label's text and its image.
    void SetIconTextGap(int);
    int GetIconTextGap();
};


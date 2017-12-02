#pragma once
#include "../../GUI/GUIBox.h"
enum class Alignment {
    LEFT,
    CENTER,
    RIGHT,
    TOP,
    BOTTOM
};

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
    Alignment textToIconAlignment = Alignment::CENTER; /*!< положение текста по отношению к иконке */
    unsigned int GapBetweenIconText = 0; /*!< расстояние между иконкой и текстом */
    bool isDependsOnSize; /*!< автоматический подгон размера шрифта под размер (области label) */
    RectangleShape *rect = nullptr;

    /*!
    \brief Функция, которая подгоняет размер шрифта под размер элемента 
    \param size_ размер элемента
    */
    void FindFitSizeOfFont(Vector2f size_);
    /*!
    \brief Функция, которая подгоняет размер иконки под размер элемента
    \param size_ размер элемента
    */
    void FindFitScaleOfImage(Vector2f size_);

    /*!
    * \brief This signal is emitted once every time a part of the route is found.
    * \param n Indicates the number of the route parts found.
    */
protected:
    // нужен ли gstyle? текстуру хранить там?
    // конструкторы икон, икон + выравнивание, строка, строка+икон+выравн, строка +выравн, пустой
    /*
    JLabel(Icon)
    // конструктор для одной иконки, tstyle нужен, чтобы потом, если вы захотите, смогли установить текст.
    GUILabel(RenderWindow* renderWindow_, float x, float y, float width, float height, Texture *icon_, TextStyle *tstyle, GUIStyle *gstyle, bool isDependsOnSize_);
    GUILabel(RenderWindow* renderWindow_, float x, float y, float width, float height, Texture *icon_, TextStyle *tstyle_, GUIStyle *gstyle_);
    GUILabel(RenderWindow* renderWindow_, Vector2f position_, Vector2f size_, Texture *icon_, TextStyle *tstyle_, GUIStyle *gstyle_);

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
    //! Конструктор c is dependsOnsize
    /*!
    Создает текстовый label
    */
    //GUILabel(RenderWindow* renderWindow_, float x, float y, float width, float height, std::string text, bool isDependsOnSize_, TextStyle *tstyle, GUIStyle *gstyle);

    //! Конструктор
    /*!
    Создает текстовый label
    */
    //GUILabel(RenderWindow* renderWindow_, Vector2f position_, Vector2f size_, std::string text, bool isDependsOnSize_, TextStyle *tstyle, GUIStyle *gstyle);

    // СТАНДАРТНЫЕ КОНСТРУКТОРЫ ДЛЯ СТАРОЙ ВЕРСИИ
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



    //! Переопределяем функцию Draw
    virtual void Draw() override;

    //! Переопределяем функцию Recalc
    virtual void Recalc() override;

public:
    //virtual void SetSize(float width, float height) override;
    //virtual void SetSize(Vector2f size_) override;
    //float GetSize(); этот метод уже есть в базовом

    //! Устанавливает размер текста
    void SetSizeOfText(unsigned int size);
    //! Возвращает размер текста
    unsigned int GetSizeOfText() const;


    //! Устанавливает иконку
    void SetIcon(Texture* iconT);
    //! Возвращает иконку
    Texture* GetIcon() const;

    //! Устанавливает текст
    virtual void SetText(char *text);
    //! Возвращает текст
    char* GetText() const;


    /*!
    Sets or gets the area on the label where its contents should be placed. 
    The SwingConstants interface defines five possible values for horizontal alignment: LEFT, CENTER (the default for image-only labels), 
    RIGHT, LEADING (the default for text-only labels), TRAILING. For vertical alignment: TOP, CENTER (the default), and BOTTOM.
    \param renderWindow_ окно, в которое рисуем
    */
    //! Устанавливает или возвращает горизонтальное и вертикальное положение элемента
    void SetHorizontalAlignment(Alignment aligment);
    void SetVerticalAlignment(Alignment aligment);
    Alignment GetHorizontalAlignment();
    Alignment GetVerticalAlignment();
    
    /*
    Sets or gets the location where the label's text will be placed, relative to the label's image. 
    The SwingConstants interface defines five possible values for horizontal position: LEADING, LEFT, CENTER, RIGHT, and TRAILING (the default). 
    For vertical position: TOP, CENTER (the default), and BOTTOM.
    */
    void SetTextToIconAlignment(Alignment aligment);
    Alignment GetTextToIconAlignment();

    //! Устанавливает или возвращает количество пикселей между текстом и иконкой
    void SetGapBetweenIconText(unsigned int gap);
    unsigned int GetGapBetweenIconText();

    //! Устанавливает зависимость шрифта и иконки от размера элемента
    void SetDependsOnSize(bool state);
    bool GetDependsOnSize();
};

/*
если текст + иконка, то он не меняет размер в зависимости от размера бокса.
*/
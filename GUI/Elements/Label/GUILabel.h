#ifndef LABEL_H
#define LABEL_H
#include "../../GUI/GUIBox.h"

//! Состояния выравнивания
enum Alignment {
    LEFT,
    CENTER,
    RIGHT,
    TOP,
    BOTTOM
};

/*!
\brief Класс, реализующий Label

Label может быть просто текстом, просто иконкой или текстом с иконкой. 
В дополнение элемент может быть выравнен, а для текста с иконкой можно выбрать положение текста по отношению к иконке.
*/
class GUILabel : public GUIBox
{
private:
    friend class GUILayer;

    Text text; //!< текст
    Texture *iconT; //!< текстура иконки
    Sprite *icon; //!< иконка, которую можно нарисовать
    TextStyle *tstyle; //!< стиль текста
    Alignment horizontalAlignment; //!< горизонтальное выравнивание
    Alignment verticalAlignment; //!< вертикальное выравнивание
    Alignment textToIconAlignment; //!< положение текста по отношению к иконке
    unsigned int GapBetweenIconText; //!< расстояние между иконкой и текстом
    bool isDependsOnSize; //!< автоматический подгон размера шрифта под размер элемента

    /*!
    \brief Функция, которая подгоняет размер шрифта под размер элемента 
    \param size_ размер элемента
    */
    void FindFitSizeOfFont(const Vector2f& size_);

    /*!
    \brief Функция, которая подгоняет размер иконки под размер элемента
    \param size_ размер элемента
    */
    void FindFitScaleOfImage(const Vector2f& size_);
protected:
    /*!
    \brief Конструктор класса

    \param renderWindow Окно, в котором будет расположен label
    \param position Расположение label
    \param size Размер label
    \param text Строка текста
    \param tstyle Стиль текста
    \param gstyle Стиль для Box

    Конструктор класса, который создает один текст
    */
    GUILabel(RenderWindow* renderWindow, Vector2f position, Vector2f size, 
        std::string text, TextStyle *tstyle, GUIStyle *gstyle);

    /*!
    \brief Конструктор класса

    \param renderWindow Окно, в котором будет расположен label
    \param position Расположение label
    \param size Размер label
    \param tstyle Стиль текста
    \param icon Текстура иконки
    \param gstyle Стиль для Box

    Конструктор класса, который создает одну иконку
    */
    GUILabel(RenderWindow* renderWindow, Vector2f position, Vector2f size, 
        TextStyle *tstyle, Texture *icon, GUIStyle *gstyle);

    /*!
    \brief Конструктор класса

    \param renderWindow Окно, в котором будет расположен label
    \param position Расположение label
    \param size Размер label
    \param text Строка текста
    \param tstyle Стиль текста
    \param icon Текстура иконки
    \param gstyle Стиль для Box

    Конструктор класса, который создает текст и иконку
    */
    GUILabel(RenderWindow* renderWindow, Vector2f position, Vector2f size, 
        std::string text, TextStyle *tstyle, Texture *icon, GUIStyle *gstyle);

    //! Переопределяем функцию Draw
    void Draw() override;

    //! Переопределяем функцию Recalc
    void Recalc() override;

public:
    /*!
    \brief Устанавливает размер текста
    \param size размер текста целое беззнаковое число
    */
    void SetSizeOfText(const unsigned int size);

    //! Возвращает размер текста
    unsigned int GetSizeOfText() const;

    /*!
    \brief Устанавливает иконку
    \param iconT текстура иконки
    */
    void SetIcon(Texture* iconT);
    
    /*!
    \brief Возвращает иконку
    \return Указатель на текстуру
    */
    Texture* GetIcon() const;

    /*!
    \brief Устанавливает текст
    \param text текст
    */
    virtual void SetText(char* text);
  
    /*!
    \brief Возвращает текст
    \return Текст типа sf::String
    */
    String GetText() const;

    /*!
    \brief Устанавливает положение горизонтального выравнивания элемента
    \param aligment позиция, которая может быть: LEFT, CENTER, RIGHT
    */
    void SetHorizontalAlignment(const Alignment aligment);

    /*!
    \brief Устанавливает положение вертикального выравнивания элемента
    \param aligment позиция, которая может быть: CENTER, TOP, BOTTOM
    */
    void SetVerticalAlignment(const Alignment aligment);

    //! Возвращает положение горизонтального выравнивания элемента
    Alignment GetHorizontalAlignment();

    //! Возвращает положение вертикального выравнивания элемента
    Alignment GetVerticalAlignment();
    
    /*!
    \brief Устанавливает положение текста по отношению к иконке
    \param aligment позиция, которая может быть: LEFT, CENTER, RIGHT, TOP, BOTTOM
    */
    void SetTextToIconAlignment(const Alignment aligment);

    //! Возвращает положение текста по отношению к иконке
    Alignment GetTextToIconAlignment();

    /*!
    \brief Устанавливает количество пикселей между текстом и иконкой
    \param gap количество пикселей между текстом и иконкой
    */
    void SetGapBetweenIconText(unsigned int gap);

    //! Возвращает количество пикселей между текстом и иконкой
    unsigned int GetGapBetweenIconText();

    /*!
    \brief Устанавливает состояние зависимости текста или иконки от размера
    \param state состояние зависимости текста или иконки от размера
    */
    void SetDependsOnSize(bool state);

    //! Возвращает состояние зависимости текста или иконки от размера
    bool GetDependsOnSize();
};
#endif // !LABEL_H

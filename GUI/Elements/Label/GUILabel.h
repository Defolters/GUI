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
\brief Класс реализующий Label
Может состоять из текста, иконки и быть выравнен. 
*/
class GUILabel : public GUIBox
{
private:
    friend class GUILayer;

    Text text; //!< текст
    Texture *iconT; //!< текстура иконки
    Sprite *icon; //!< иконка, которую можно нарисовать
    TextStyle *tstyle; //!< стиль текста
    Alignment horizontalAlignment = Alignment::CENTER; //!< горизонтальное выравнивание
    Alignment verticalAlignment = Alignment::CENTER; //!< вертикальное выравнивание
    Alignment textToIconAlignment = Alignment::CENTER; //!< положение текста по отношению к иконке
    unsigned int GapBetweenIconText = 0; //!< расстояние между иконкой и текстом
    bool isDependsOnSize; //!< автоматический подгон размера шрифта под размер (области label)
    RectangleShape *rect = nullptr; //!< прямоугольник для демонстрации alignment

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
    * \brief Class constructor.
    * \param parent Settings Dialog parent widget.
    *
    * Initializes Settings Dialog and creates its layout based on target OS.
    */
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

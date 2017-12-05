#pragma once
#include "../../GUI/GUIBox.h"
#include "../Label/GUILabel.h"
/*!
\brief Реализующий ProgressBar класс
Показывает статус выполнения какого-либо процесса
*/
class GUIProgressBar : public GUIBox
{
private:
    friend class GUILayer;
    TextStyle *tstyle; //!< стиль текста
    Text text; //!< текст 

    RectangleShape * staticBar; //!< статическая часть бара 
    RectangleShape * dynamicBar; //!< динамическая часть бара 
    std::shared_ptr<GUILabel> label; //!< текстовая метка
    std::shared_ptr<GUILayer> layer; //!< текущий слой, на котором расположен PrBar 

    float minValue; //!< минимальное значение 
    float maxValue; //!< максимальное значение 

    float point; //!< сотая часть всего бара 
    float value; //!< текущее значение бара
protected:
    /*!
    \brief Конструктор класса
    \param renderWindow Окно, в котором будет расположен label
    \param position Расположение label
    \param x Расположение бара по оси x
    \param y Расположение бара по оси y
    \param text Строка текста
    \param tstyle Стиль текста
    \param gstyle Стиль для Box
    \param minValue Минимальное значение для бара
    \param maxValue Максимальное значение для бара
    \param staticBarColor Цвет для статичной части бара
    \param dynamicBarColor Цвет для динамичной части бара
    Конструктор класса, который создает бар вместе c текстом для label
    */
    GUIProgressBar(RenderWindow* renderWindow_, std::shared_ptr<GUILayer> _layer, float x, float y, float width, float height,
        std::string text, TextStyle *tstyle, GUIStyle *gstyle,
        float minValue, float maxValue, Color staticBarColor, Color dynamicBarColor);

    /*!
    \brief Конструктор класса
    \param renderWindow Окно, в котором будет расположен label
    \param position Расположение label
    \param x Расположение бара по оси x
    \param y Расположение бара по оси y
    \param tstyle Стиль текста
    \param gstyle Стиль для Box
    \param minValue Минимальное значение для бара
    \param maxValue Максимальное значение для бара
    \param staticBarColor Цвет для статичной части бара
    \param dynamicBarColor Цвет для динамичной части бара
    Конструктор класса, который создает бар без текста для label
    */
    GUIProgressBar(RenderWindow* renderWindow_, std::shared_ptr<GUILayer> _layer, float x, float y, float width, float height,
        TextStyle *tstyle, GUIStyle *gstyle,
        float minValue, float maxValue, Color staticBarColor, Color dynamicBarColor);

    //! Переопределение функции Draw
    virtual void Draw() override;

    //! Переопределение функции Recalc
    virtual void Recalc() override;
public:
    /*!
    \brief Увеличение бара на одну сотую часть при одном обращении к методу.
    */
    void increase();

    /*!
    \brief Установка текущего значения бара
    \param _value Текущее значение бара
    */
    void setValue(float _value);

    /*!
    \brief Установка текущего текста для Label
    \param _value Текст
    */
    void setText(const std::string & _text);

    /*!
    \brief Изменение позиции бара
    \param x Смещение по оси x
    \param y Смещение по оси y
    */
    virtual void SetPosition(float x, float y) override;

    /*!
    \brief Изменение позиции бара
    \param position_ Вектор смещения
    */
    virtual void SetPosition(Vector2f position_) override;

    /*!
    \brief Изменение позиции бара
    \param position_ Вектор смещения
    \param coefficient_ Коэффициент смещения
    */
    virtual void SetPosition(Vector2f position_, Vector2f coefficient_) override;

    /*!
    \brief Изменение размеров бара
    \param width Ширина
    \param height Высота
    */
    virtual void SetSize(float width, float height) override;

    /*!
    \brief Изменение размеров бара
    \param size_ Вектор размера
    */
    virtual void SetSize(Vector2f size_) override;

    /*!
    \brief Информация об окончании заполнения. Возвращает максимальное значение.
    */
    float End();
};
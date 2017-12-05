#ifndef SCROLLBAR_H
#define SCROLLBAR_H

#include "../../../GUI/GUI/GUIBox.h"
//! Ориентация
enum class Orientation {
    HORIZONTAL,
    VERTICAL
};


/*!
\brief Класс реализующий ScrollBar
Может создавать вертикальный и горизонтальный скроллбары
*/
class ScrollBar : public GUIBox
{
public:
    //! Конструктор
    /*!
    Создает ScrollBar
    \param renderWindow_ окно, в которое рисуем
    \param orientation_ ориентация
    \param sizeScrollPanel_ размер скролл панели
    */
    ScrollBar(RenderWindow* renderWindow_, Orientation orientation_,
        GUIStyle *gstyle, float sizeScrollPanel_);
    //! Деструктор
    ~ScrollBar() = default;

    /*!
    \brief Переопределяем функцию DrawforScr
    \param event ивент
    */
    virtual void handleEvent(const sf::Event& event) override;

    /*!
    \brief Переопределяем функцию DrawforScr
    \param swindow окно
    */
    virtual void DrawforScr(RenderWindow *swindow) override;

    //! Переопределяем функцию Recalc
    virtual void Recalc();

private:
    bool isMousePressed; //!< проверка на "нажатость" левой кнопки мыши
    float lastPos; //!< предыдущая позиция роллика
    Orientation orientation; //!< ориентация
    sf::RectangleShape band; //!< полоса прокрутки
    sf::RectangleShape roller; //!< ролик 
    sf::RectangleShape limiter; //!< ограничитель, чтобы полосы не перекрывали друг друга
    const float width = 18.0f; //!< ширина полосы
    float height; //!< высота полосы
    float shift; //!< смещение, равное размеру ролика
    float sizeScrollPanel; //!< размер скролл панели
};

#endif // !SCROLLBAR_H
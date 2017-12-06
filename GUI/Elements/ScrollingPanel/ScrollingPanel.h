#pragma once
#include "../../GUI/GUILayer.h"
#include <typeinfo>

/*!
\brief Класс, реализующий ScrollingPanel

ScrollingPanel отвечает за прокрутку элементов в определенной области
*/
class ScrollingPanel : public GUILayer
{
private:
    RenderWindow crutch; //!< невидимое окно, на котором рисуются элементы панели
    RenderWindow* window; //!< ссылка на основное окно, на котором рисуется ScrollingPanel и ScrollBar'ы

    Image scrImage; //!< хранит изображение всего невидимого окна crutch
    Sprite scrField; //!< спрайт панели
    Texture scrTexture; //!< текстура спрайта панели

    Vector2f scrFieldPosition; //!< позиция панели относительно основного окна
    Vector2f scrFieldSize; //!< размер панели
    Vector2f crutchsize; //!< размер невидимого окна crutch

    Color scrFieldColor; //!< цвет фона для элементов ScrollingPanel
public:
    /*!
    \brief Конструктор класса

    \param maxScrollPanelSize Размер невидимого окна crutch
    \param &Swindow Ссылка на основное окно
    \param scrFieldPosition Позиция панели относительно основного окна
    \param scrFieldSize Размер панели
    \param scrFieldColor Цвет фона для элементов ScrollingPanel

    Конструктор класса, который создает ScrollingPanel
    */
    ScrollingPanel(Vector2f maxScrollPanelSize, RenderWindow &Swindow, Vector2f scrFieldPosition,
        Vector2f scrFieldSize, Color scrFieldColor);

    Vector2i viewPosition; //!< позиция "камеры" относительно невидимого окна	

                           /*!
                           \brief Устанавливает новую позицию для панели
                           \param position Vector2f с новыми координатами левого верхнего угла поля панели
                           */
    virtual void SetPosition(Vector2f position_) override;
    /*!
    \brief Устанавливает новый размер для панели
    \param position Vector2f с новыми размерами панели
    */
    virtual void SetSize(Vector2f size_) override;

    /*!
    \brief Рисует ScrollingPanel и все её элементы
    */
    virtual void DrawPanel();

    /*!
    \brief Оповещает элементы ScrollingPanel о событии
    \param event обрабатываемое событие
    */
    void notifysAll(const sf::Event& event) const;
    /*!
    \brief обработчик событий
    \param event обрабатываемое событие
    */
    void handlesEvent(const sf::Event& event);
};

#pragma once
#include <map>
#include "../GUI/GUILayer.h"
#include "../Elements/ScrollingPanel/ScrollingPanel.h"

enum WindowTabState
{
	opened = 0,
	closed = 1
};
/*!
\brief Окно

*/
class WindowTab : ObservableGUI
{
private:
	std::vector<std::shared_ptr<GUILayer>> GUILayers; //!< вектор слоев
	std::vector<std::shared_ptr<ScrollingPanel>> ScrollPanels;//!> вектор рисуемых перематывающихся панелей
	RenderWindow window; //!< окно


    /*!
    \brief Функция, которая изменяет размер компонентов, если окно растянули
    \param event_ Содержит в себе новый размер окна
    */
    void Resizing(const Event& event_);
public:
    WindowTabState state;
	/*!
	\brief Создание слоя

	\param position Расположение layer
	\param size Размер layer

	Создание слоя на этом окне
	*/
	std::shared_ptr<GUILayer> CreateGUILayer(Vector2f position_, Vector2f size_);
	std::shared_ptr<ScrollingPanel> CreateScrollPanel(Vector2f maxScrollPanelSize, Vector2f scrFieldPosition, Vector2f scrFieldSize, Color scrFieldColor);
	void Redraw();//единственная функция которую надо вызывать для отрисовки, не трогаем ее
	/*!
	\brief Конструктор класса

	\param mode видео-режим окна
	\param name имя окна

	Создание окна
	*/
	WindowTab(VideoMode mode, char* name);

	//TODO
	void removeElement(IDrawable* observer) override;
	//! перегрузка метода оповещения слушателей о событии
	void notifyAll(const sf::Event& event) const override;
	~WindowTab();
};

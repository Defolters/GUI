#pragma once
#include "../../GUI/GUILayer.h"
#include <typeinfo>

class ScrollingPanel : public GUILayer
{
private:
	RenderWindow crutch; // Невидимое окно на котором рисуется элементы панели
	RenderWindow* window; //Основное окно на котором рисуется ScrollingPanel и ScrollBar'ы

	Image scrImage; // Хранит изображение всего невидимого окна (crutch)
	Sprite scrField; // Спрайт ScrollingPanel
	Texture scrTexture; // Текстура спрайта ScrollingPanel

	Vector2f scrFieldPosition; // Позиция ScrollingPanel
	Vector2f scrFieldSize; // Размер ScrollingPanel
	Vector2f crutchsize; // Размер невидимого окна

	Color scrFieldColor; // Цвет фона для элементов ScrollingPanel
public:
	ScrollingPanel(Vector2f maxScrollPanelSize, RenderWindow &Swindow, Vector2f scrFieldPosition, 
				   Vector2f scrFieldSize, Color scrFieldColor);

	Vector2i viewPosition; // Позиция "камеры" относительно невидимого окна	

	virtual void SetPosition(Vector2f position_) override;
	virtual void SetSize(Vector2f size_) override;

	virtual void DrawPanel(); 

	void notifysAll(const sf::Event& event) const;
	void handlesEvent(const sf::Event& event);
};

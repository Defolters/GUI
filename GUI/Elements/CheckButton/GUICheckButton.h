#pragma once
#include "../Button/GUIButton.h"
/*!
\brief Класс, реализующий зажимающуюся кнопку

Кнопка, фиксирующая свое состояние при нажатии
*/
class GUICheckButton : public GUIButton
{
public:
	/*!
	\brief Конструктор класса

	\param renderWindow Окно, в котором будет расположен label
	\param x х-координата
	\param y у-координата
	\param width ширина
	\param height высота
	\param text Строка текста
	\param tstyle Стиль текста
	\param gstyle Стиль для Box
	\param action функция вызываемая при нажатии

	*/
	GUICheckButton(GUILayer* layer_, RenderWindow* renderWindow_, float x, float y, float width, float height, std::string text, TextStyle *tstyle, GUIStyle *gstyle, void(*action)());
	~GUICheckButton();
	//! узнать состояние кнопки
	bool GetState();
	//! перегрузка обработчика событий
	void handleEvent(const sf::Event& event) override;
};


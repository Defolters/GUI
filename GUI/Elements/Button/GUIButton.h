#pragma once
#include "../../GUI/GUIBox.h"
/*!
\brief Класс, реализующий кнопку

Кнопка, вызывающая функцию привязанную к ней при нажатии
*/
class GUIButton : public GUIBox
{
	friend class GUILayer;
protected:
	void(*action)();//!< функция, вызываемая при нажатии
	bool clicked;//!< функция, вызываемая при нажатии
	bool entered;//!< функция, вызываемая при нажатии
	GUILayer* layer;//!< функция, вызываемая при нажатии
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
	GUIButton(GUILayer* layer_, RenderWindow* renderWindow_, float x, float y, float width, float height, std::string text, TextStyle *tstyle, GUIStyle *gstyle, void(*action)());
	/*!
	\brief Конструктор класса

	\param renderWindow Окно, в котором будет расположен label
	\param position Расположение label
	\param size Размер label
	\param text Строка текста
	\param tstyle Стиль текста
	\param gstyle Стиль для Box
	\param action функция вызываемая при нажатии

	*/
	GUIButton(GUILayer* layer_, RenderWindow* renderWindow_, Vector2f position_, Vector2f size_, std::string text, TextStyle *tstyle, GUIStyle *gstyle, void(*action)());
	/*!
	\brief Конструктор класса

	\param renderWindow Окно, в котором будет расположен label
	\param position Расположение label
	\param width ширина
	\param height высота
	\param text Строка текста
	\param tstyle Стиль текста
	\param gstyle Стиль для Box
	\param action функция вызываемая при нажатии

	*/
	GUIButton(GUILayer* layer_, RenderWindow* renderWindow_, Vector2f position_, float width, float height, std::string text, TextStyle *tstyle, GUIStyle *gstyle, void(*action)());
	/*!
	\brief Конструктор класса

	\param renderWindow Окно, в котором будет расположен label
	\param x х-координата
	\param y у-координата
	\param size Размер label
	\param text Строка текста
	\param tstyle Стиль текста
	\param gstyle Стиль для Box
	\param action функция вызываемая при нажатии

	*/
	GUIButton(GUILayer* layer_, RenderWindow* renderWindow_, float x, float y, Vector2f size_, std::string text, TextStyle *tstyle, GUIStyle *gstyle, void(*action)());

	//! Переопределение обработчика событий
	void handleEvent(const sf::Event& event) override;
	//! Переопределение метода отрисовки
	void Draw() override;
};

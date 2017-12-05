#pragma once
#include "../../GUI/GUIBox.h"
#include "../Label/GUILabel.h"
#include <memory>
#include <iostream>


/*!
\brief Служебный класс

Реализует 1 элемент radioButton
*/
class CheckButton: public GUIBox
{
public:
	/*!
	\brief Конструктор служебного класса 

	\param layer Слой, необходим для создания текстов
	\param renderWindow_ Окно, в котором будет расположена кнпока
	\param x Координата X левого верхнего угла кнопки
	\param y Координата Y левого верхнего угла кнопки
	\param width Ширина текстуры кнопки
	\param height Высота текстуры кнопки
	\param gstyle Стиль кнопки
	\param text Строка текста для кнопки
	\param tstyle Стиль текста

	Конструктор служебного класса, который создает checkButton использующиеся в radioButton
	*/
	CheckButton(std::shared_ptr<GUILayer> layer, RenderWindow* renderWindow_, float x, float y,
				float width, float height,  GUIStyle *gstyle, 
				std::string text, TextStyle* tstyle);
	//! Переопределение метода Draw
	void Draw() override;
	//! Метод, устанавливающий кнопку в активное состояние
	void setActive();
	//! Метод, устанавливающий кнопку в неактивное состояние
	void setDeactive();
	/*!
	\brief Служебный метод для обработки событий
	\param pos Вектор, содержащий позицию левого клика
	\return True или False
	*/
	bool contain(Vector2f pos);
	/*!
	\brief Метод устанавливает новую позицию для одной кнопки
	\param x новая координата X левого верхнего угла поля radioButton
	\param y новая координата Y левого верхнего угла поля radioButton
	*/
	void SetPosition(float x, float y) override;
    /*!
    \brief Метод устанавливает новую позицию для одной кнопки
    \param position вектор с координатами X и Y левого верхнего угла поля radioButton
    */
    void SetPosition(Vector2f position) override;
private:
	bool active = false;//!< изначальное состояние кнопки
	std::shared_ptr<GUILabel> lab;//!< Текст для кнопки
};


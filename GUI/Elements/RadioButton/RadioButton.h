#pragma once
#include "../../GUI/GUIBox.h"
#include <vector>
#include <memory>  
#include "CheckButton.h"
#include "../../Observable.h"
class CheckButton;

/*!
\brief Класс, реализующий radio button

Кнопки создаются ветикально с небольшим промежутком и текстом слева. 
*/
class RadioButton: public  IDisplayable
{
public:
	/*!
	\brief Конструктор класса

	\param layer слой, на котором будут расположены кнопки
	\param renderWindow_ Окно, в котором будет расположен radioButton
	\param count Количество кнопок в группе
	\param x Координата X левого верхнего угла поля radioButton
	\param y Координата Y левого верхнего угла поля radioButton
	\param width Ширина текстуры кнопки
	\param height Высота текстуры кнопки
	\param text Вектор строк, 1 кнопка - 1 элемент
	\param tstyle Стиль текста
	\param gstyle Стиль кнопки

	Конструктор класса, который создает radioButton
	*/
	RadioButton(std::shared_ptr<GUILayer> layer, RenderWindow* renderWindow_,
		int count, float x, float y, float width, float height,
		std::vector<std::string> text, TextStyle *tstyle, GUIStyle *gstyle);
	/*!
	\brief Возвращает bool вектор состояний
	\return Вектор типа bool
	*/
	std::vector<bool> getState();
	/*!
	\brief Устанавливает новую позицию для всех кнопок
	\param x новая координата X левого верхнего угла поля radioButton
	\param y новая координата Y левого верхнего угла поля radioButton
	*/
	void SetPosition(float x, float y);
	/*!
	\brief Устанавливает новую позицию
	\param position Vector2f с новыми координатами левого верхнего угла поля radioButton
	*/
	void SetPosition(Vector2f position);

    /*!
    \brief Устанавливает новую позицию
    \param position Vector2f с новыми координатами левого верхнего угла поля radioButton
    \param coefficient Коэффициент, на который изменился размер окна
    */
	void SetPosition(Vector2f pos, Vector2f coefficient);
protected:
	//! Переопределяем функцию Draw
	void Draw() override;
	//! Переопределение метода handleEvent
	void handleEvent(const sf::Event & event) override;
private:
	std::vector<CheckButton*> options;//!< Вектор кнопок
	std::vector<bool> stateArray;//!< Вектор состояний
	int butHeight;//!< Высота кнопки
	int butWidth;//!< Ширина кнопки
};
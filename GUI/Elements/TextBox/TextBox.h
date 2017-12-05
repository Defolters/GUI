#pragma once
#include "../../GUI/GUIBox.h"

/*!
\brief Класс, реализующий TextField

Textfield позволяет вводить и удалять текст
*/
class TextField : public GUIBox
{
private:
	friend class GUILayer;
	std::string text; //!<вводимый текст
	Text txt;         //!<выводимый текст
	RectangleShape field;//!<текстовое поле
	std::string currText; //!<текст, находящийся в поле видимости
	int position;//!<позиция последнего символа
protected:
	/*!
	\brief Конструктор класса

	\param renderWindow Окно, в котором будет расположен TextField
	\param x координата по горизонтали
	\param y координата по вертикали
	\param width ширина
	\param height высота
	\param text Строка текста
	\param tstyle Стиль текста
	\param gstyle Стиль для Box

	*/
	TextField(RenderWindow* renderWindow_, float x, float y, float width, float height, std::string text, TextStyle *tstyle, GUIStyle *gstyle);
	bool focus;//!<хранит значение, задействован TextField или нет
public:
	//! Переопределяем функцию Draw
	virtual void Draw() override;
	//! Переопределяем функцию Recalc
	virtual void Recalc() override;
	/*!
	Принимает и обрабатывает события
	/param event Событие
	*/
	void handleEvent(const sf::Event& event) override;
	/*!
	Настраивает позицию TextField
	/param x координата по горизонтали
	/param y координата по вертикали
	*/
	void SetPosition(float x, float y) override;
	/*!
	Настраивает размер TextField
	/param width ширина
	/param height высота
	*/
	void SetSize(float width, float height) override;
	//Text DisplayText();
	//!формирует текст в  TextField
	void ReText(char);
	//!проверка фокуса
	bool Select();
	//!проверка фокуса
	bool Select(Vector2i);
	std::string ReadText();

};

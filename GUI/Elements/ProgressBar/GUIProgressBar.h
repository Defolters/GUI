#pragma once
#include "../../GUI/GUIBox.h"
#include "../Label/GUILabel.h"
class GUIProgressBar : public GUIBox
{
private:
	friend class GUILayer;
	TextStyle *tstyle; /*!< стиль текста */
	Text text; /*!< текст */

	RectangleShape * staticBar; /*!< статическая часть бара */
	RectangleShape * dynamicBar; /*!< динамическая часть бара */
	std::shared_ptr<GUILabel> label; /*!< текстовая метка*/
	std::shared_ptr<GUILayer> layer; /*!< текущий слой, на котором расположен PrBar */

	float minValue; /*!< минимальное значение */
	float maxValue; /*!< максимальное значение */

	float point; /*!< сотая часть всего бара */
	float value; /*!< текущее значение бара */
protected:
	//! Конструктор
	/*!
	Создает ProgressBar
	*/
	GUIProgressBar(RenderWindow* renderWindow_, std::shared_ptr<GUILayer> _layer, float x, float y, float width, float height,
		std::string text, TextStyle *tstyle, GUIStyle *gstyle,
		float minValue, float maxValue, Color staticBarColor, Color dynamicBarColor);

	//! Переопределение функции Draw
	virtual void Draw() override;

	//! Переопределение функции Recalc
	virtual void Recalc() override;
public:
	//! Увеличение бара на одну сотую часть при одном обращении к методу.
	void increase();
	//! Установка текущего значения бара
	void setValue(float _value);
	//! Установка текущего текста для Label
	void setText(const std::string & _text);
	//! Изменение позиции бара
	virtual void SetPosition(float x, float y) override;
	//! Изменение позиции бара
	virtual void SetPosition(Vector2f position_) override;
	//! Изменение размера бара
	virtual void SetSize(float width, float height) override;
	//! Изменение размера бара
	virtual void SetSize(Vector2f size_) override;
};


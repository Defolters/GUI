#pragma once
#include "../../General/Styles.hpp"
#include "../../IDisplayable.h"

class GUISlider : public IDisplayable
{
private:
	//спрайты для ползунка, передней и задней полосок
	Sprite handler_sprite;
	Sprite front_line_sprite;
	Sprite back_line_sprite;
	Texture handler_texture;
	Texture front_line_texture;
	Texture back_line_texture;
	//управляемое слайдером значение
	float value;
	//диапазон значений
	float value_range_from;
	float value_range_to;
	//локальная позиция ползунка относительно всего слайдера
	float local_handler_pos_x;
	float local_handler_pos_y;
	// позиция спрайта ползунка по вертикали в процентах от высоты линии 
	// (нужно, если у линии, например, есть тень снизу - тогда середина линии не совпадет с серединой текстуры)
	float vertical_handler_pos;
	//позиция и размер слайдера в пикселях
	int line_position_x;
	int line_position_y;
	int line_size_x;
	int line_size_y;
	int handler_size_x;
	int handler_size_y;
	//метод, который вызывается, пока пользователь перетаскивает ползунок
	void onHandlerMove();
	void(*action_on_move)(float slider_value);
	bool isMoving; //истина, пока нажата мышь
	float delta; //расстояние от центра ползунка до курсора в момент нажатия
	//стили
	GUIStyle* guistyle;

	friend class GUILayer;
	GUILayer* layer;
protected:
	//конструкторы (с методом, вызываемом при передвижении слайдера, и без него)
	GUISlider(GUILayer* layer, RenderWindow* renderWindow_, float line_position_x_, float line_position_y_,
		float line_width_, float line_height_, float handler_width_, float handler_height_, GUIStyle* gst,
		float value_range_from_, float value_range_to_, float value_, void(*action_on_move)(float slider_value));
	GUISlider(GUILayer* layer, RenderWindow* renderWindow_, float line_position_x_, float line_position_y_,
		float line_width_, float line_height_, float handler_width_, float handler_height_, GUIStyle* gst,
		float value_range_from_, float value_range_to_, float value_);
public:
	virtual void handleEvent(const sf::Event& event) override;

	float GetValue(); ///<возвращает управляемое значение
	void SetValue(float value_); ///<задает управляемое значение

	Vector2f GetValueRange(); ///<возвращает диапазон изменения управляемого значения
	void SetValueRange(Vector2f range_); ///<задает диапазон изменения управляемого значения
	void SetValueRange(float range_from_, float range_to_); ///<задает диапазон изменения управляемого значения
	
	//те же функции что и в IDisplayable, здесь изменяют только размер полосок, размер ползунка меняется отдельно
	virtual void Draw() override; ///<вызывается для отрисовки слайдера в окне
	virtual void SetPosition(float x_, float y_) override; ///<задает позицию в пикселях
	virtual void SetPosition(Vector2f position_) override; ///<задает позицию в пикселях
	virtual void SetSize(float width_, float height_) override; ///<задает размер в пикселях
	virtual void SetSize(Vector2f size_) override; ///<задает размер в пикселях
	Vector2f GetPosition();
	Vector2f GetSize();

	void SetHandlerSize(float width_, float height_); ///<задает размер ползунка
	// позиция спрайта ползунка по вертикали в процентах от высоты текстуры линии
	/**
	\brief возвращает позицию ползунка по вертикали

	Может случиться, что ползунок не должен находиться посередине линии, тогда, меняя это значение
	(проценты от высоты линии), пользователь может задать, на какой высоте будет находиться ползунок.
	*/
	float GetVerticalHandlerPosition();
	/**
	\brief задает позицию ползунка по вертикали

	Может случиться, что ползунок не должен находиться посередине линии, тогда, меняя это значение
	(проценты от высоты линии), пользователь может задать, на какой высоте будет находиться ползунок.
	*/
	void SetVerticalHandlerPosition(float persentage_of_line_height_);
	
	void SetTextures(); ///<задает текстуры всем элементам слайдера (подтягивает их из GUIStyle)
	void SetGUIStyle(GUIStyle* gst); ///<задает стили (GUIStyle)
	
	//нужно вызывать после любых изменений размера или позиции составных частей слайдера
	//void Recalc();
};
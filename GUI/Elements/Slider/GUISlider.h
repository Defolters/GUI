#pragma once
#include "../../General/Styles.hpp"
#include "../../IDisplayable.h"

class Slider : public IDisplayable
{
private:
	//спрайты дл€ ползунка, передней и задней полосок
	Sprite handler_sprite;
	Sprite front_line_sprite;
	Sprite back_line_sprite;
	Texture handler_texture;
	Texture front_line_texture;
	Texture back_line_texture;
	//управл€емое слайдером значение
	float value;
	//локальна€ позици€ ползунка относительно всего слайдера
	float local_handler_pos_x;
	float local_handler_pos_y;
	// позици€ спрайта ползунка по вертикали в процентах от высоты линии 
	// (нужно, если у линии, например, есть тень снизу - тогда середина линии не совпадет с серединой текстуры)
	float vertical_handler_pos;
	//позици€ и размер слайдера в пиксел€х
	int line_position_x;
	int line_position_y;
	int line_size_x;
	int line_size_y;
	int handler_size_x;
	int handler_size_y;
	//диапазон значений
	float value_range_from;
	float value_range_to;
	//метод, который вызываетс€, пока пользователь перетаскивает ползунок
	void onHandlerMove();
	void(*action_on_move)(float slider_value);
	bool isMoving; //истина, пока нажата мышь
	float delta; //рассто€ние от центра ползунка до курсора в момент нажати€
	GUIStyle* guistyle;
public:
	//конструкторы (с методом, вызываемом при передвижении слайдера, и без него)
	Slider(RenderWindow* renderWindow_, float line_position_x_, float line_position_y_,
		float line_width_, float line_height_, float handler_width_, float handler_height_, GUIStyle* gst,
		float value_range_from_, float value_range_to_, float value_, void(*action_on_move)(float slider_value));
	Slider(RenderWindow* renderWindow_, float line_position_x_, float line_position_y_,
		float line_width_, float line_height_, float handler_width_, float handler_height_, GUIStyle* gst,
		float value_range_from_, float value_range_to_, float value_);
	//принимает событи€
	virtual void handleEvent(const sf::Event& event) override;
	//геттеры и сеттеры дл€ управл€емого значени€ (очевидно измен€ют также и положение ползунка)
	float GetValue();
	void SetValue(float value_);
	//диапазон значений
	Vector2f GetValueRange();
	void SetValueRange(Vector2f range_);
	void SetValueRange(float range_from_, float range_to_);
	//те же функции что и в IDisplayable, здесь измен€ют только размер полосок, размер ползунка мен€етс€ отдельно
	virtual void Draw() override;
	virtual void SetPosition(float x_, float y_) override;
	virtual void SetPosition(Vector2f position_) override;
	virtual void SetSize(float width_, float height_) override;
	virtual void SetSize(Vector2f size_) override;
	//сеттеры ползунка
	void SetHandlerSize(float width_, float height_);
	// позици€ спрайта ползунка по вертикали в процентах от высоты текстуры линии
	float GetVerticalHandlerPosition();
	void SetVerticalHandlerPosition(float persentage_of_line_height_);
	void SetTextures();
	void SetGUIStyle(GUIStyle* gst);
	//нужно вызывать после любых изменений размера или позиции составных частей слайдера
	//void Recalc();
};
#include "GUISlider.h"
#include <iostream>


void Slider::Draw()
{
	if (isMoving)
		onHandlerMove();

	renderWindow->draw(back_line_sprite);
	renderWindow->draw(front_line_sprite);
	renderWindow->draw(handler_sprite);
}

void Slider::SetPosition(float x_, float y_)
{
	back_line_sprite.setPosition(x_, y_);
	front_line_sprite.setPosition(x_, y_);
	line_position_x = x_;
	line_position_y = y_;
	SetVerticalHandlerPosition(vertical_handler_pos);
	SetValue(value);
}

void Slider::SetPosition(Vector2f position_)
{
	back_line_sprite.setPosition(position_.x, position_.y);
	front_line_sprite.setPosition(position_.x, position_.y);
	SetValue(value);
	line_position_x = position_.x;
	line_position_y = position_.y;
}

void Slider::SetSize(float width_, float height_)
{
	back_line_sprite.setScale(width_ / back_line_texture.getSize().x, height_ / back_line_texture.getSize().y);
	front_line_sprite.setScale(width_ / front_line_texture.getSize().x, height_ / front_line_texture.getSize().y);
	line_size_x = width_;
	line_size_y = height_;
	//TODO пересчитываем положение ползунка

}

void Slider::SetSize(Vector2f size_)
{
	back_line_sprite.setScale(size_.x / back_line_texture.getSize().x, size_.y / back_line_texture.getSize().y);
	front_line_sprite.setScale(size_.x / front_line_texture.getSize().x, size_.y / front_line_texture.getSize().y);
	line_size_x = size_.x;
	line_size_y = size_.y;
}

void Slider::SetHandlerSize(float width_, float height_)
{
	handler_sprite.setScale(width_ / handler_texture.getSize().x, height_ / handler_texture.getSize().y);
	handler_size_x = width_;
	handler_size_y = height_;
}

float Slider::GetVerticalHandlerPosition()
{
	return vertical_handler_pos;
}

void Slider::SetVerticalHandlerPosition(float persentage_of_line_height_)
{
	vertical_handler_pos = persentage_of_line_height_;
	float new_pos_y = line_position_y + line_size_y * persentage_of_line_height_ / 100;
	handler_sprite.setPosition(handler_sprite.getPosition().x, new_pos_y);
}

/*
void Slider::SetTextures(std::string back_line_file_name_, std::string front_line_file_name_, std::string handler_file_name_)
{
	back_line_texture.loadFromFile(back_line_file_name_);
	front_line_texture.loadFromFile(front_line_file_name_);
	handler_texture.loadFromFile(handler_file_name_);

	back_line_sprite.setTexture(back_line_texture);
	front_line_sprite.setTexture(front_line_texture);
	handler_sprite.setTexture(handler_texture);

	SetSize(line_size_x, line_size_y);

	SetHandlerSize(handler_size_x, handler_size_y);
	handler_sprite.setOrigin(handler_size_x, handler_size_y);
	SetVerticalHandlerPosition(vertical_handler_pos);

	SetValue(value);
}*/

void Slider::SetTextures()
 {
	back_line_texture = guistyle->sliderBackTex;
	front_line_texture = guistyle->sliderFrontTex;
	handler_texture = guistyle->sliderHandlerTex;
	
		back_line_sprite.setTexture(back_line_texture);
	front_line_sprite.setTexture(front_line_texture);
	handler_sprite.setTexture(handler_texture);
	
		SetSize(line_size_x, line_size_y);
	
		SetHandlerSize(handler_size_x, handler_size_y);
	handler_sprite.setOrigin(handler_size_x, handler_size_y);
	SetVerticalHandlerPosition(vertical_handler_pos);
	
		SetValue(value);
}

void Slider::SetGUIStyle(GUIStyle* gst)
 {
	guistyle = gst;
	SetTextures();
	}

void Slider::onHandlerMove()
{
	int mouse_pos_x = Mouse::getPosition().x - renderWindow->getPosition().x - 11;

	if (mouse_pos_x + delta > line_position_x + line_size_x)
	{
		handler_sprite.setPosition(line_position_x + line_size_x, handler_sprite.getPosition().y);
		value = value_range_to;
		float front_line_scale_x = back_line_sprite.getScale().x;
		front_line_sprite.setScale(front_line_scale_x * 1, back_line_sprite.getScale().y);
	}
	else if (mouse_pos_x + delta < line_position_x)
	{
		handler_sprite.setPosition(line_position_x, handler_sprite.getPosition().y);
		value = value_range_from;
		float front_line_scale_x = back_line_sprite.getScale().x;
		front_line_sprite.setScale(front_line_scale_x * 0, back_line_sprite.getScale().y);
	}
	else
	{
		handler_sprite.setPosition(mouse_pos_x + delta, handler_sprite.getPosition().y);
		float percent = (mouse_pos_x + delta - line_position_x) / (line_size_x);
		value = value_range_from + (value_range_to - value_range_from) * percent;
		float front_line_scale_x = back_line_sprite.getScale().x;
		front_line_sprite.setScale(front_line_scale_x * percent, back_line_sprite.getScale().y);
	}
	action_on_move(value);
}

Slider::Slider(RenderWindow * renderWindow_, float line_position_x_, float line_position_y_,
	float line_width_, float line_height_, float handler_width_, float handler_height_, GUIStyle* gst,
	float value_range_from_, float value_range_to_, float value_, void (*action_on_move)(float slider_value))
	: IDisplayable(renderWindow_, line_position_x_, line_position_y_, line_width_, line_height_)
{
	renderWindow = renderWindow_;
	guistyle = gst;

	value = value_;
	value_range_from = value_range_from_;
	value_range_to = value_range_to_;

	SetPosition(line_position_x_, line_position_y_);
	SetSize(line_width_, line_height_);

	//размер
	SetHandlerSize(handler_width_, handler_height_);
	SetVerticalHandlerPosition(50);

	//задаем значение
	if (value_ > value_range_to || value_ < value_range_from)
		SetValue(value_range_from);
	else
		SetValue(value_);

	handler_texture.setSmooth(true);
	back_line_texture.setSmooth(true);
	front_line_texture.setSmooth(true);
	SetTextures();

	isMoving = false;

	this->action_on_move = action_on_move;
}

Slider::Slider(RenderWindow * renderWindow_, float line_position_x_, float line_position_y_,
	float line_width_, float line_height_, float handler_width_, float handler_height_, GUIStyle* gst,
	float value_range_from_, float value_range_to_, float value_)
	: IDisplayable(renderWindow_, line_position_x_, line_position_y_, line_width_, line_height_)
{
	renderWindow = renderWindow_;
	guistyle = gst;

	value = value_;
	value_range_from = value_range_from_;
	value_range_to = value_range_to_;

	SetPosition(line_position_x_, line_position_y_);
	SetSize(line_width_, line_height_);

	//размер
	SetHandlerSize(handler_width_, handler_height_);
	SetVerticalHandlerPosition(50);

	//задаем значение
	if (value_ > value_range_to || value_ < value_range_from)
		SetValue(value_range_from);
	else
		SetValue(value_);

	handler_texture.setSmooth(true);
	back_line_texture.setSmooth(true);
	front_line_texture.setSmooth(true);

	isMoving = false;
	SetTextures();
}

void Slider::handleEvent(const sf::Event & event)
{
	if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Button::Left)
	{
		if (event.mouseButton.x > handler_sprite.getPosition().x - handler_size_x / 2.0 &&
			event.mouseButton.x < handler_sprite.getPosition().x + handler_size_x / 2.0 &&
			event.mouseButton.y > handler_sprite.getPosition().y - handler_size_y / 2.0 &&
			event.mouseButton.y < handler_sprite.getPosition().y + handler_size_y / 2.0)
		{
			isMoving = true;
			delta = handler_sprite.getPosition().x - event.mouseButton.x;
		}
		else if (event.mouseButton.x > back_line_sprite.getPosition().x &&
				event.mouseButton.x < back_line_sprite.getPosition().x + line_size_x &&
				event.mouseButton.y > back_line_sprite.getPosition().y &&
				event.mouseButton.y < back_line_sprite.getPosition().y + line_size_y)
		{
			delta = 0;
			isMoving = true;
		}
	}
	else if (event.type == Event::MouseButtonReleased && event.mouseButton.button == Mouse::Button::Left)
	{
		isMoving = false;
	}
	else if (event.type == Event::Resized)
	{
		line_size_x = back_line_sprite.getScale().x * back_line_texture.getSize().x;
		line_size_y = back_line_sprite.getScale().y * back_line_texture.getSize().y;
		line_position_x = back_line_sprite.getPosition().x;
		line_position_y = back_line_sprite.getPosition().y;
	}
}

float Slider::GetValue()
{
	return value;
}

void Slider::SetValue(float value_)
{
	if (value_ > value_range_to || value_ < value_range_from)
	{
		value_ = value_range_from;
	}
	value = value_;
	float percent = (value - value_range_from) / (value_range_to - value_range_from);
	handler_sprite.setPosition(line_position_x + line_size_x * percent, line_position_y);
	SetVerticalHandlerPosition(vertical_handler_pos);
	float front_line_scale_x = back_line_sprite.getScale().x;
	front_line_sprite.setScale(front_line_scale_x * percent, back_line_sprite.getScale().y);
}

Vector2f Slider::GetValueRange()
{
	return Vector2f(value_range_from, value_range_to);
}

void Slider::SetValueRange(Vector2f range_)
{
	value_range_from = range_.x;
	value_range_to = range_.y;
	SetValue(value);
}

void Slider::SetValueRange(float range_from_, float range_to_)
{
	value_range_from = range_from_;
	value_range_to = range_to_;
	SetValue(value);
}


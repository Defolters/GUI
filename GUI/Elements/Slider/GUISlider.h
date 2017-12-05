#pragma once
#include "../../General/Styles.hpp"
#include "../../IDisplayable.h"

class GUISlider : public IDisplayable
{
private:
	//������� ��� ��������, �������� � ������ �������
	Sprite handler_sprite;
	Sprite front_line_sprite;
	Sprite back_line_sprite;
	Texture handler_texture;
	Texture front_line_texture;
	Texture back_line_texture;
	//����������� ��������� ��������
	float value;
	//�������� ��������
	float value_range_from;
	float value_range_to;
	//��������� ������� �������� ������������ ����� ��������
	float local_handler_pos_x;
	float local_handler_pos_y;
	// ������� ������� �������� �� ��������� � ��������� �� ������ ����� 
	// (�����, ���� � �����, ��������, ���� ���� ����� - ����� �������� ����� �� �������� � ��������� ��������)
	float vertical_handler_pos;
	//������� � ������ �������� � ��������
	int line_position_x;
	int line_position_y;
	int line_size_x;
	int line_size_y;
	int handler_size_x;
	int handler_size_y;
	//�����, ������� ����������, ���� ������������ ������������� ��������
	void onHandlerMove();
	void(*action_on_move)(float slider_value);
	bool isMoving; //������, ���� ������ ����
	float delta; //���������� �� ������ �������� �� ������� � ������ �������
	//�����
	GUIStyle* guistyle;

	friend class GUILayer;
	GUILayer* layer;
protected:
	//������������ (� �������, ���������� ��� ������������ ��������, � ��� ����)
	GUISlider(GUILayer* layer, RenderWindow* renderWindow_, float line_position_x_, float line_position_y_,
		float line_width_, float line_height_, float handler_width_, float handler_height_, GUIStyle* gst,
		float value_range_from_, float value_range_to_, float value_, void(*action_on_move)(float slider_value));
	GUISlider(GUILayer* layer, RenderWindow* renderWindow_, float line_position_x_, float line_position_y_,
		float line_width_, float line_height_, float handler_width_, float handler_height_, GUIStyle* gst,
		float value_range_from_, float value_range_to_, float value_);
public:
	virtual void handleEvent(const sf::Event& event) override;

	float GetValue(); ///<���������� ����������� ��������
	void SetValue(float value_); ///<������ ����������� ��������

	Vector2f GetValueRange(); ///<���������� �������� ��������� ������������ ��������
	void SetValueRange(Vector2f range_); ///<������ �������� ��������� ������������ ��������
	void SetValueRange(float range_from_, float range_to_); ///<������ �������� ��������� ������������ ��������
	
	//�� �� ������� ��� � � IDisplayable, ����� �������� ������ ������ �������, ������ �������� �������� ��������
	virtual void Draw() override; ///<���������� ��� ��������� �������� � ����
	virtual void SetPosition(float x_, float y_) override; ///<������ ������� � ��������
	virtual void SetPosition(Vector2f position_) override; ///<������ ������� � ��������
	virtual void SetSize(float width_, float height_) override; ///<������ ������ � ��������
	virtual void SetSize(Vector2f size_) override; ///<������ ������ � ��������
	Vector2f GetPosition();
	Vector2f GetSize();

	void SetHandlerSize(float width_, float height_); ///<������ ������ ��������
	// ������� ������� �������� �� ��������� � ��������� �� ������ �������� �����
	/**
	\brief ���������� ������� �������� �� ���������

	����� ���������, ��� �������� �� ������ ���������� ���������� �����, �����, ����� ��� ��������
	(�������� �� ������ �����), ������������ ����� ������, �� ����� ������ ����� ���������� ��������.
	*/
	float GetVerticalHandlerPosition();
	/**
	\brief ������ ������� �������� �� ���������

	����� ���������, ��� �������� �� ������ ���������� ���������� �����, �����, ����� ��� ��������
	(�������� �� ������ �����), ������������ ����� ������, �� ����� ������ ����� ���������� ��������.
	*/
	void SetVerticalHandlerPosition(float persentage_of_line_height_);
	
	void SetTextures(); ///<������ �������� ���� ��������� �������� (����������� �� �� GUIStyle)
	void SetGUIStyle(GUIStyle* gst); ///<������ ����� (GUIStyle)
	
	//����� �������� ����� ����� ��������� ������� ��� ������� ��������� ������ ��������
	//void Recalc();
};
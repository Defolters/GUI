#pragma once
#include "../../GUI/GUIBox.h"
#include "../Label/GUILabel.h"
#include <memory>
#include <iostream>


/*!
\brief ��������� ����

��������� 1 ������� radioButton
*/
class CheckButton: public GUIBox
{
public:
	/*!
	\brief ����������� ���������� ������ 

	\param layer ����, ��������� ��� �������� �������
	\param renderWindow_ ����, � ������� ����� ����������� ������
	\param x ���������� X ������ �������� ���� ������
	\param y ���������� Y ������ �������� ���� ������
	\param width ������ �������� ������
	\param height ������ �������� ������
	\param gstyle ����� ������
	\param text ������ ������ ��� ������
	\param tstyle ����� ������

	����������� ���������� ������, ������� ������� checkButton �������������� � radioButton
	*/
	CheckButton(std::shared_ptr<GUILayer> layer, RenderWindow* renderWindow_, float x, float y,
				float width, float height,  GUIStyle *gstyle, 
				std::string text, TextStyle* tstyle);
	//! ��������������� ������ Draw
	void Draw() override;
	//! �����, ��������������� ������ � �������� ���������
	void setActive();
	//! �����, ��������������� ������ � ���������� ���������
	void setDeactive();
	/*!
	\brief ��������� ����� ��� ��������� �������
	\param pos ������, ���������� ������� ������ �����
	\return True ��� False
	*/
	bool contain(Vector2f pos);
	/*!
	\brief ����� ������������� ����� ������� ��� ����� ������
	\param x ����� ���������� X ������ �������� ���� ���� radioButton
	\param y ����� ���������� Y ������ �������� ���� ���� radioButton
	*/
	void SetPosition(float x, float y) override;
    /*!
    \brief ����� ������������� ����� ������� ��� ����� ������
    \param position ������ � ������������ X � Y ������ �������� ���� ���� radioButton
    */
    void SetPosition(Vector2f position) override;
private:
	bool active = false;//!< ����������� ��������� ������
	std::shared_ptr<GUILabel> lab;//!< ����� ��� ������
};


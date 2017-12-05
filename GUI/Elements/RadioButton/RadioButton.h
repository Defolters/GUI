#pragma once
#include "../../GUI/GUIBox.h"
#include <vector>
#include <memory>  
#include "CheckButton.h"
#include "../../Observable.h"
class CheckButton;

/*!
\brief �����, ����������� radio button

������ ��������� ���������� � ��������� ����������� � ������� �����. 
*/
class RadioButton: public  IDisplayable
{
public:
	/*!
	\brief ����������� ������

	\param layer ����, �� ������� ����� ����������� ������
	\param renderWindow_ ����, � ������� ����� ���������� radioButton
	\param count ���������� ������ � ������
	\param x ���������� X ������ �������� ���� ���� radioButton
	\param y ���������� Y ������ �������� ���� ���� radioButton
	\param width ������ �������� ������
	\param height ������ �������� ������
	\param text ������ �����, 1 ������ - 1 �������
	\param tstyle ����� ������
	\param gstyle ����� ������

	����������� ������, ������� ������� radioButton
	*/
	RadioButton(std::shared_ptr<GUILayer> layer, RenderWindow* renderWindow_,
		int count, float x, float y, float width, float height,
		std::vector<std::string> text, TextStyle *tstyle, GUIStyle *gstyle);
	/*!
	\brief ���������� bool ������ ���������
	\return ������ ���� bool
	*/
	std::vector<bool> getState();
	/*!
	\brief ������������� ����� ������� ��� ���� ������
	\param x ����� ���������� X ������ �������� ���� ���� radioButton
	\param y ����� ���������� Y ������ �������� ���� ���� radioButton
	*/
	void SetPosition(float x, float y);
	/*!
	\brief ������������� ����� �������
	\param position Vector2f � ������ ������������ ������ �������� ���� ���� radioButton
	*/
	void SetPosition(Vector2f position);

	void SetPosition(Vector2f pos, Vector2f coefficient);
protected:
	//! �������������� ������� Draw
	void Draw() override;
	//! ��������������� ������ handleEvent
	void handleEvent(const sf::Event & event) override;
private:
	std::vector<CheckButton*> options;//!< ������ ������
	std::vector<bool> stateArray;//!< ������ ���������
	int butHeight;//!< ������ ������
	int butWidth;//!< ������ ������
};
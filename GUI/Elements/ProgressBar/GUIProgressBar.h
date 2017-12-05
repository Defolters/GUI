#pragma once
#include "../../GUI/GUIBox.h"
#include "../Label/GUILabel.h"
class GUIProgressBar : public GUIBox
{
private:
	friend class GUILayer;
	TextStyle *tstyle; /*!< ����� ������ */
	Text text; /*!< ����� */

	RectangleShape * staticBar; /*!< ����������� ����� ���� */
	RectangleShape * dynamicBar; /*!< ������������ ����� ���� */
	std::shared_ptr<GUILabel> label; /*!< ��������� �����*/
	std::shared_ptr<GUILayer> layer; /*!< ������� ����, �� ������� ���������� PrBar */

	float minValue; /*!< ����������� �������� */
	float maxValue; /*!< ������������ �������� */

	float point; /*!< ����� ����� ����� ���� */
	float value; /*!< ������� �������� ���� */
protected:
	//! �����������
	/*!
	������� ProgressBar
	*/
	GUIProgressBar(RenderWindow* renderWindow_, std::shared_ptr<GUILayer> _layer, float x, float y, float width, float height,
		std::string text, TextStyle *tstyle, GUIStyle *gstyle,
		float minValue, float maxValue, Color staticBarColor, Color dynamicBarColor);

	//! ��������������� ������� Draw
	virtual void Draw() override;

	//! ��������������� ������� Recalc
	virtual void Recalc() override;
public:
	//! ���������� ���� �� ���� ����� ����� ��� ����� ��������� � ������.
	void increase();
	//! ��������� �������� �������� ����
	void setValue(float _value);
	//! ��������� �������� ������ ��� Label
	void setText(const std::string & _text);
	//! ��������� ������� ����
	virtual void SetPosition(float x, float y) override;
	//! ��������� ������� ����
	virtual void SetPosition(Vector2f position_) override;
	//! ��������� ������� ����
	virtual void SetSize(float width, float height) override;
	//! ��������� ������� ����
	virtual void SetSize(Vector2f size_) override;
};


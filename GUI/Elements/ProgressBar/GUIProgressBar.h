#pragma once
#include "../../GUI/GUIBox.h"
#include "../Label/GUILabel.h"
/*!
\brief ����������� ProgressBar �����

���������� ������ ���������� ������-���� ��������
*/
class GUIProgressBar : public GUIBox
{
private:
	friend class GUILayer;
	TextStyle *tstyle; //!< ����� ������
	Text text; //!< ����� 

	RectangleShape * staticBar; //!< ����������� ����� ���� 
	RectangleShape * dynamicBar; //!< ������������ ����� ���� 
	std::shared_ptr<GUILabel> label; //!< ��������� �����
	std::shared_ptr<GUILayer> layer; //!< ������� ����, �� ������� ���������� PrBar 

	float minValue; //!< ����������� �������� 
	float maxValue; //!< ������������ �������� 

	float point; //!< ����� ����� ����� ���� 
	float value; //!< ������� �������� ����
protected:
	/*!
	\brief ����������� ������

	\param renderWindow ����, � ������� ����� ���������� label
	\param position ������������ label
	\param x ������������ ���� �� ��� x
	\param y ������������ ���� �� ��� y
	\param text ������ ������
	\param tstyle ����� ������
	\param gstyle ����� ��� Box
	\param minValue ����������� �������� ��� ����
	\param maxValue ������������ �������� ��� ����
	\param staticBarColor ���� ��� ��������� ����� ����
	\param dynamicBarColor ���� ��� ���������� ����� ����

	����������� ������, ������� ������� ��� ������ c ������� ��� label
	*/
	GUIProgressBar(RenderWindow* renderWindow_, std::shared_ptr<GUILayer> _layer, float x, float y, float width, float height,
		std::string text, TextStyle *tstyle, GUIStyle *gstyle,
		float minValue, float maxValue, Color staticBarColor, Color dynamicBarColor);

	/*!
	\brief ����������� ������

	\param renderWindow ����, � ������� ����� ���������� label
	\param position ������������ label
	\param x ������������ ���� �� ��� x
	\param y ������������ ���� �� ��� y
	\param tstyle ����� ������
	\param gstyle ����� ��� Box
	\param minValue ����������� �������� ��� ����
	\param maxValue ������������ �������� ��� ����
	\param staticBarColor ���� ��� ��������� ����� ����
	\param dynamicBarColor ���� ��� ���������� ����� ����

	����������� ������, ������� ������� ��� ��� ������ ��� label
	*/
	GUIProgressBar(RenderWindow* renderWindow_, std::shared_ptr<GUILayer> _layer, float x, float y, float width, float height,
		TextStyle *tstyle, GUIStyle *gstyle,
		float minValue, float maxValue, Color staticBarColor, Color dynamicBarColor);

	//! ��������������� ������� Draw
	virtual void Draw() override;

	//! ��������������� ������� Recalc
	virtual void Recalc() override;
public:
	/*!
	\brief ���������� ���� �� ���� ����� ����� ��� ����� ��������� � ������.
	*/
	void increase();

	/*!
	\brief ��������� �������� �������� ����
	\param _value ������� �������� ����
	*/
	void setValue(float _value);

	/*!
	\brief ��������� �������� ������ ��� Label
	\param _value �����
	*/
	void setText(const std::string & _text);

	/*!
	\brief ��������� ������� ����
	\param x �������� �� ��� x
	\param y �������� �� ��� y
	*/
	virtual void SetPosition(float x, float y) override;

	/*!
	\brief ��������� ������� ����
	\param position_ ������ ��������
	*/
	virtual void SetPosition(Vector2f position_) override;

	/*!
	\brief ��������� ������� ����
	\param position_ ������ ��������
	\param coefficient_ ����������� ��������
	*/
	virtual void SetPosition(Vector2f position_, Vector2f coefficient_) override;

	/*!
	\brief ��������� �������� ����
	\param width ������
	\param height ������
	*/
	virtual void SetSize(float width, float height) override;

	/*!
	\brief ��������� �������� ����
	\param size_ ������ �������
	*/
	virtual void SetSize(Vector2f size_) override;

	/*!
	\brief ���������� �� ��������� ����������. ���������� ������������ ��������.
	*/
	float End();
};


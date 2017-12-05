#pragma once
#include "../../GUI/GUIBox.h"
///	������������ ������ ���� � ����
enum class Location {
	DOWNSIDE, UPSIDE,
	RIGHT_SIDE, LEFT_SIDE
};

/*!
/brief �����, ����������� ������ ���
��� ���������� �������� ���������, �������� �� ������� � ������� ����
*/
class GUIStatusBar : public IDisplayable
{
private:
	friend class GUILayer;

	RectangleShape *statusBar;	///< ������ ���
	Texture *background;	///< �������� ����
	GUIStyle *sBarStyle;	///< ����� ����������
	Location location;	///< ������������ ���� � ����
	float width;	///< ������� ������ ����
	bool isMoved = false;
	float currPosition = 0;	///< ������� X ������� ��� ������� ���������� ��������
	float frameSize = 10;	///< ������� �������� ������ � ����� �� ���� ������ ���� �� ���������
	float spacing;	///< ������ ����� ������������ ����������
	float ratio;	///< ����������� ������� ����������� �������
	int childCount = 0;	   ///< ���������� �������� ���������
protected:
	/// �������������� ������� Draw()
	virtual void Draw() override;
	/*!
	��������� � ������������ �������
	/param event �������
	*/
	virtual void handleEvent(const sf::Event &event) override;
	/*!
	������������� ��������� ������ ���� � ��������� �� ���
	*/
	virtual void Recalc();
	/// ������������� ������� �������� ���������
	virtual void recalcElements();
public:
	/// �����������
	GUIStatusBar(RenderWindow* renderWindow_, float height_, float frameSize_,
		float spacing_, GUIStyle *sBarStyle_, Location location_);
	/*!
	������������� ������� ������ ���� ������������ ����
	/param location_ �������
	*/
	void setLocation(Location location_);
};
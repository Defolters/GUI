#pragma once
#include "../../GUI/GUIBox.h"
class GUIStatusBar : public IDisplayable
{
private:
	friend class GUILayer;
	Sprite *statusBar;
	Texture *background;
	GUIStyle *sBarStyle;
	/*! 
	������ ������ ����
	*/
	float width;
	/*!
	������ ������ ����
	*/
	float height;
	/*!
	������� X ������� ��� ������� ���������� ��������
	*/
	float currPosition = 0;
	/*!
	������� �������� ������ � ����� �� ���� ������ ���� �� ���������
	*/
	float frameSize = 10;
	/*!
	������ ����� ������������ ����������
	*/
	float spacing;
	/*!
	����������� ������� ����������� �������
	*/
	float ratio;
	/*!
	���-�� �������� ��������
	*/
	int childCount = 0;
protected:
	void Draw() override;
	void handleEvent(const sf::Event &event) override;
	void Recalc();
public:
	GUIStatusBar(RenderWindow* renderWindow_, float height_, float frameSize_,
		float spacing_, GUIStyle *sBarStyle_);
};
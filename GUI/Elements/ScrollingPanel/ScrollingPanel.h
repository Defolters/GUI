#pragma once
#include "../../GUI/GUILayer.h"
#include <typeinfo>

class ScrollingPanel : public GUILayer
{
private:
	RenderWindow crutch; // ��������� ���� �� ������� �������� �������� ������
	RenderWindow* window; //�������� ���� �� ������� �������� ScrollingPanel � ScrollBar'�

	Image scrImage; // ������ ����������� ����� ���������� ���� (crutch)
	Sprite scrField; // ������ ScrollingPanel
	Texture scrTexture; // �������� ������� ScrollingPanel

	Vector2f scrFieldPosition; // ������� ScrollingPanel
	Vector2f scrFieldSize; // ������ ScrollingPanel
	Vector2f crutchsize; // ������ ���������� ����

	Color scrFieldColor; // ���� ���� ��� ��������� ScrollingPanel
public:
	ScrollingPanel(Vector2f maxScrollPanelSize, RenderWindow &Swindow, Vector2f scrFieldPosition, 
				   Vector2f scrFieldSize, Color scrFieldColor, GUIStyle *gst);

	Vector2i viewPosition; // ������� "������" ������������ ���������� ����	

	virtual void SetPosition(Vector2f position_) override;
	virtual void SetSize(Vector2f size_) override;

	virtual void DrawPanel(); 

	void notifysAll(const sf::Event& event) const;
	void handlesEvent(const sf::Event& event);
};

#pragma once
#include <map>
#include "../GUI/GUILayer.h"
enum WindowTabState
{
	opened = 0,
	closed = 1
};
//������ ������� ��� ������������� ��� �������� ���� ���, ���������� �� ��� �� ��� ������� �� handler.cpp (������ ����� ctrl-c)
class WindowTab : ObservableGUI
{
private:
	std::vector<std::shared_ptr<GUILayer>> GUILayers;
	RenderWindow window;
public:
	//������������, �� �������� �� ���� ����, ������ ����������� ��� ��������� �������
	//���� ��� ������ ��� ��������� ����������� (0,0) � (����������, ����������)
	//��������� ���� ��������� ��� ����� ���� �� �������� :)
	std::shared_ptr<GUILayer> CreateGUILayer(Vector2f position_, Vector2f size_);
	void Redraw();//������������ ������� ������� ���� �������� ��� ���������, �� ������� ��
	WindowTab(VideoMode mode, char* name);
	WindowTabState state;
	//TODO
	//����������, �� ����� ����!
	void removeElement(IDrawable* observer) override;
	void notifyAll(const sf::Event& event) const override;
	~WindowTab();
};


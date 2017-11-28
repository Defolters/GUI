#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
//����� ��� ������ - �����, ������ � ����
struct TextStyle {
	Font font;
	int fontSize;
	Color color;
	char align;//������������ ���������� �����. ���� == 'c', �� ����� ��������� �� ������, ���� 'l' - �� ������ ����
};

//����� ��� ������ - �����, ������ � ����
struct GUIStyle {
	Texture mainTex, pressTex, overTex;
	Texture frame;//����� (� �������� ������� ������ ����������)
	int frameWid;//������ ����� � ��������
	Texture sliderBackTex, sliderFrontTex, sliderHandlerTex;//�������� ��� ��������
	Texture background;
};
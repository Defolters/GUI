#pragma once
#include "IDrawable.h"

//������� ����� ������� ���������
class IDisplayable abstract : public IDrawable
{
private:
	//�������� �� �� ����� ������� ���������� ��� ���
	bool toDraw;
public:
	//��������� �������� toDraw
	virtual bool GetDrawState();
	//��������� ��������� toDraw
	virtual void SetDrawState(bool);
	//�������� �� �� �������������� �� ������� ������, ����� ��� event
	virtual bool IsClickedThrough();//���� �� ������ �� ����
	//virtual sf::Vector2i GetScreenSize() = 0;//TODO
	//TODO events
protected:
	bool clicksThrough;
	//��������� �� ���� � ������� ���� ��������
	RenderWindow* renderWindow;
	IDisplayable(RenderWindow*, float, float, float, float);
	IDisplayable(RenderWindow*, Vector2f, float, float);
	IDisplayable(RenderWindow*, float, float, Vector2f);
	IDisplayable(RenderWindow*, Vector2f, Vector2f);
};


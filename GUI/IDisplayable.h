#pragma once
#include "IDrawable.h"
//������� ����� ������� ���������
class IDisplayable abstract : public IDrawable
{
private:
	//std::vector<std::shared_ptr<IDrawable>> elements;
	//�������� �� �� ����� ������� ���������� ��� ���
	bool toDraw;
public:
	//��������� �������� toDraw
	virtual bool GetDrawState();
	//��������� ��������� toDraw
	virtual void SetDrawState(bool);
	virtual bool IsClickedThrough();//���� �� ������ �� ����
	//virtual sf::Vector2f GetScreenSize() = 0;//TODO

protected:
	bool clicksThrough;
	//��������� �� ���� � ������� ���� ��������
	RenderWindow* renderWindow;
	IDisplayable(RenderWindow*, float, float, float, float);
	IDisplayable(RenderWindow*, Vector2f, float, float);
	IDisplayable(RenderWindow*, float, float, Vector2f);
	IDisplayable(RenderWindow*, Vector2f, Vector2f);
};


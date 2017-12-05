#pragma once
#include "../../GUI/GUIBox.h"

class TextField : public GUIBox
{
private:
	friend class GUILayer;
	std::string text; //�������� �����
	Text txt;         //��������� �����
	RectangleShape field;
	std::string currText; //�����, ����������� � ���� ���������
	int position;
protected:
	TextField(RenderWindow* renderWindow_, float x, float y, float width, float height, std::string text, TextStyle *tstyle, GUIStyle *gstyle);
	bool focus;
public:
	virtual void Draw() override;
	virtual void Recalc() override;
	void handleEvent(const sf::Event& event) override;
	void SetPosition(float x, float y) override;
	void SetSize(float width, float height) override;
	//Text DisplayText();
	void ReText(char);     //��������� ����� �  TextField
	bool Select();
	bool Select(Vector2i); //�������� ������
	std::string ReadText();

};

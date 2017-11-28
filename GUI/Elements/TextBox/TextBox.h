#pragma once
#include "../../GUI/GUIBox.h"

class TextField : public GUIBox
{
private:
	friend class GUILayer;
	std::string text; //�������� �����
	Text txt;         //��������� �����
	RectangleShape field;
protected:
	TextField(RenderWindow* renderWindow_, float x, float y, float width, float height, std::string text, TextStyle *tstyle, GUIStyle *gstyle);
	bool focus;
public:
	virtual void Draw() override;
	virtual void Recalc() override;
	void handleEvent(const sf::Event& event) override;

	Text DisplayText();
	void ReText(char);     //��������� ����� �  TextField
	bool Select();
	bool Select(Vector2i); //�������� ������

};

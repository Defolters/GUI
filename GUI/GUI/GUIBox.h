#pragma once
#include "GUIElement.h"

class GUIBox : public GUIElement
{
private:
	GUIStyle *gstyle;
	Sprite sprite;
	Sprite frames[4];
	TextStyle *tstyle;
	Text text;
	friend class GUILayer;
protected:
	GUIBox(RenderWindow* renderWindow_, float x, float y, float width, float height, std::string text, TextStyle *tstyle, GUIStyle *gstyle);
	GUIBox(RenderWindow* renderWindow_, Vector2f position_, Vector2f size_, std::string text, TextStyle *tstyle, GUIStyle *gstyle);
	GUIBox(RenderWindow* renderWindow_, float x, float y, Vector2f size_, std::string text, TextStyle *tstyle, GUIStyle *gstyle);
	GUIBox(RenderWindow* renderWindow_, Vector2f position_, float width, float height, std::string text, TextStyle *tstyle, GUIStyle *gstyle);
public:
	void Draw() override;
	void SetPosition(float x, float y) override;
	void SetPosition(Vector2f position_) override;
	void SetSize(float width, float height) override;
	void SetSize(Vector2f size_) override;
	virtual void SetText(char *text);
	virtual void SetGStyle(GUIStyle *gstyle);
	virtual void SetTStyle(TextStyle *tstyle);
	virtual void Recalc();
};

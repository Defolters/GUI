#ifndef TEXTAREA_H
#define TEXTAREA_H

#include "../../../GUI/IDisplayable.h"
#include "../../General/Styles.hpp"
class TextArea : public IDisplayable
{
public:
	TextArea(RenderWindow * window, float x, float y, float width, float height, TextStyle * tstyle,GUIStyle* gstyle);
	/*virtual void SetPosition(float x, float y) override;
	virtual void SetPosition(Vector2f position_) override;
	virtual void SetSize(float width, float height) override;
	virtual void SetSize(Vector2f size_) override;*/
	virtual void Draw() override;
	virtual void handleEvent(const sf::Event& event) override;
	virtual void SetPosition(float x, float y) override;
	virtual void SetPosition(Vector2f position_) override;
	virtual void SetSize(float width, float height) override;
	virtual void SetSize(Vector2f size_) override;
	virtual bool GetDrawState();
	virtual void SetDrawState(bool);
	virtual bool IsClickedThrough();

	void CreatingArea();
	void TextArea::GettingText();
private:
	Font font;
	Text text;
	String inputString;
	int fontSize;
	Color fontColor;
	Color areaColor;
	RectangleShape area;
	Vector2f areaSize;
	Vector2f areaPosition;
	bool button;
};

#endif
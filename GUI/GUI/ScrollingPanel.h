#pragma once
#include "GUILayer.h"
#include <typeinfo>

class ScrollingPanel : public GUILayer
{
public:
	ScrollingPanel(Vector2f maxScrollPanelSize, RenderWindow &Swindow, Vector2f scrFieldPosition, Vector2f scrFieldSize, Color scrFieldColor, GUIStyle *gst);

	Vector2i viewPosition;

	//RenderTexture scrTexture;
	Texture scrTexture;
	Image scrImage;

	Sprite scrField;
	Vector2f scrFieldPosition;
	Vector2f scrFieldSize;
	Vector2f crutchsize;

	Color scrFieldColor;

	RenderWindow* window;
	RenderWindow crutch;

	virtual void SetPosition(Vector2f position_) override;
	virtual void SetSize(Vector2f size_) override;
	virtual void DrawPanel();
	virtual void Recalc();
	void notifysAll(const sf::Event& event) const;
	void handlesEvent(const sf::Event& event);
};

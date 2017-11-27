#ifndef SCROLLBAR_H
#define SCROLLBAR_H

#include "../../../GUI/GUI/GUIBox.h"

enum class Orientation  {
	HORIZONTAL,
	VERTICAL
};

class ScrollBar : public GUIBox
{
public:
	ScrollBar(RenderWindow* renderWindow_, Orientation orientation_, std::string text, TextStyle *tstyle, GUIStyle *gstyle);
	~ScrollBar() = default;

	virtual void handleEvent(const sf::Event& event) override;

	virtual void Draw() override;

    virtual void Recalc() override;


private:
	bool isMousePressed;
	float lastPosY;
	Orientation orientation;
	sf::RectangleShape band;
	sf::RectangleShape roller;
	const float width = 12.0;
	float height;
	const float shift = width*2;
};

#endif

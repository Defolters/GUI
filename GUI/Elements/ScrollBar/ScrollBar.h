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
	ScrollBar(RenderWindow* renderWindow_, Orientation orientation_, 
		GUIStyle *gstyle, float sizeScrollPanel_);
	~ScrollBar() = default;

	virtual void handleEvent(const sf::Event& event) override;

	virtual void Draw() override;

	virtual void Recalc() override;


private:
	bool isMousePressed;
	float lastPos;
	Orientation orientation;
	sf::RectangleShape band;
	sf::RectangleShape roller;
	sf::RectangleShape limiter;
	const float width = 18.0f;
	float height;
	float shift;
	float sizeScrollPanel;
};

#endif

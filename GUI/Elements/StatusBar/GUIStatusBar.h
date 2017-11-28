#pragma once
#include "../../GUI/GUIBox.h"
class GUIStatusBar : public IDisplayable
{
private:
	friend class GUILayer;
	Sprite *statusBar;
	Texture *background;
	//размеры статус бара
	float width;
	float height;
	//текущая X позиция для вставки следующего элемента
	float currPosition = 0;
	//размеры отступов сверху и снизу от края статус бара до элементов
	float frameSize = 10;
	//отступ между добавленными элементами
	float spacing;
protected:
	void Draw() override;
	void handleEvent(const sf::Event &event) override;
	void Recalc();
public:
	GUIStatusBar(RenderWindow* renderWindow_, float height_, float frameSize_,
		float spacing_, Texture *background_);
};
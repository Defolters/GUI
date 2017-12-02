#pragma once
#include "../../GUI/GUIBox.h"

enum class Location {
	DOWNSIDE, UPSIDE,
	RIGHT_SIDE, LEFT_SIDE
};

class GUIStatusBar : public IDisplayable
{
private:
	friend class GUILayer;
	RectangleShape *statusBar;
	Texture *background;
	GUIStyle *sBarStyle;
	Location location;
	float width;
	/*!
	текущая X позиция для вставки следующего элемента
	*/
	float currPosition = 0;
	/*!
	размеры отступов сверху и снизу от края статус бара до элементов
	*/
	float frameSize = 10;
	/*!
	отступ между добавленными элементами
	*/
	float spacing;
	/*!
	Соотношение размера добвляемого объекта
	*/
	float ratio;
	/*!
	Кол-во дочерних объектов
	*/
	int childCount = 0;
protected:
	virtual void Draw() override;
	virtual void handleEvent(const sf::Event &event) override;
	virtual void Recalc();
	/*!
	вызывается для перерасчета позиций дочерних эдлементов
	*/
	virtual void recalcElements();
public:
	GUIStatusBar(RenderWindow* renderWindow_, float height_, float frameSize_,
		float spacing_, GUIStyle *sBarStyle_, Location location_);
	void setLocation(Location location_);
};
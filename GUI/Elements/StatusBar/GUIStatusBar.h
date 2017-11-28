#pragma once
#include "../../GUI/GUIBox.h"
class GUIStatusBar : public IDisplayable
{
private:
	friend class GUILayer;
	Sprite *statusBar;
	Texture *background;
	GUIStyle *sBarStyle;
	/*! 
	Ширина статус бара
	*/
	float width;
	/*!
	Высота статус бара
	*/
	float height;
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
	void Draw() override;
	void handleEvent(const sf::Event &event) override;
	void Recalc();
public:
	GUIStatusBar(RenderWindow* renderWindow_, float height_, float frameSize_,
		float spacing_, GUIStyle *sBarStyle_);
};
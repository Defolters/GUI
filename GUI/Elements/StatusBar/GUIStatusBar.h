#pragma once
#include "../../GUI/GUIBox.h"
///	Расположение статус бара в окне
enum class Location {
	DOWNSIDE, UPSIDE,
	RIGHT_SIDE, LEFT_SIDE
};

/*!
/brief Класс, реализующий статус бар
При добавлении дочерних элементов, помещает их начиная с правого края
*/
class GUIStatusBar : public IDisplayable
{
private:
	friend class GUILayer;

	RectangleShape *statusBar;	///< Статус бар
	Texture *background;	///< Текстура фона
	GUIStyle *sBarStyle;	///< Стиль интерфейса
	Location location;	///< Расположение бара в окне
	float width;	///< Толщина статус бара
	float currPosition = 0;	///< Текущая X позиция для вставки следующего элемента
	float frameSize;	///< Размеры отступов сверху и снизу от края статус бара до элементов
	float spacing;	///< Отступ между добавленными элементами
	float ratio;	///< Соотношение размера добвляемого объекта
	int childCount = 0;	   ///< Количество дочерних элементов
protected:
	//! Переопределяем функцию Draw()
	virtual void Draw() override;
	/*!
	Принимает и обрабатывает события
	/param event Событие
	*/
	virtual void handleEvent(const sf::Event &event) override;
	/*!
	Пересчитывает положение статус бара и элементов на нем
	*/
	virtual void Recalc();
	//! Пересчитывает позиции дочерних элементов
	virtual void recalcElements();
public:
	/*!
	/brief Конструктор класса
	/param renderWindow_ Окно, в котором будет раположен статус бар
	/param height_ Высота статус бара
	/param frameSize_ Размер рамок между верхним или нижним краем и края статус бара
	/param spacing_ Отступы между добавленными элементами
	/param sBarStyle Стиль gui
	/param locatinon_ Расположение статус бара относительно окна
	*/
	GUIStatusBar(RenderWindow* renderWindow_, float height_, float frameSize_,
		float spacing_, GUIStyle *sBarStyle_, Location location_);
	/*!
	Устанавливает позицию статус бара относительно окна
	/param location_ Позиция
	*/
	void setLocation(Location location_);
	/*!
	Устанавливает отступ между соседними элементы
	/param spacing_ отступ
	*/
	void setSpacing(int spacing_);
	/*!
	Устанавливает отступ между краями статус бара и элементами
	/param frameSize_ отступ
	*/
	void setFrameSize(int frameSize_);
	/*!
	Устанавливает высоту статус бара
	/param height_ высота
	*/
	void setHeight(int height_);
};
#pragma once
#include "../../GUI/GUIBox.h"
#include <vector>
#include <string.h>
#include "../../Observable.h"

class MenuBar : public GUIBox  ///< class MenuBar
{
private:
	std::vector<std::shared_ptr <GUIBox> > buttonVect; ///< вектор, содержащий все кнопки

	int buttonPosHelp=0; ///< определяет смещение кнопки относительно предыдущей
	int buttonSizeHelp = 195; ///< размер кнопки
	GUILayer * layer;
	friend class GUILayer;
	TextStyle *tstyle;///< стиль текста
	Text text; ///< текст
	RectangleShape * staticBar;///< подложка под кнопки
	float ratio;	///< Соотношение размера добвляемого объекта
protected:
	/// Конструктор
	MenuBar(RenderWindow* renderWindow_, float x, float y, float width, float height,
		std::string text, TextStyle *tstyle, GUIStyle *gstyle,
		float leftBorder, float rightBorder, Color staticBarColor, GUILayer* layer); 
	virtual void Draw() override;
public:
	void addButton(std::string name , void(*action)());///< метод создания новой кнопки на меню баре

	virtual void SetPosition(Vector2f position_) override;
	void SetPosition(Vector2f position_, Vector2f coefficient_) override;
	virtual void SetSize(Vector2f size_) override;
	void SetSize(Vector2f size_, Vector2f coefficient_) override;


	
};


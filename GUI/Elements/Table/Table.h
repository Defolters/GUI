#pragma once


#include"../../IDisplayable.h"
#include"../../General/Styles.hpp"
#include"../../Elements/Button/GUIButton.h"
#include"../../Elements/TextBox/TextBox.h"
class GUILayer;

class Table : public IDisplayable
{
public:
	~Table();

	//void setDesign(Design design_);
	void SetFieldSize(Vector2f fieldSize_); ///< Задание размера ячейки
	void SetSize(Vector2f size_); ///< Задание количества ячеек
	void SetBorderSize(int borderSize_); ///< Толщина разделителя
	int GetBorderSize(); ///< Геттер разделителя
	void Draw() override; ///< Отрисовка
	void Update(float x, float y, float width, float height); ///< Перерасчет
	void handleEvent(const sf::Event& event) override; ///< Обработчик событий
	void AddElement(std::shared_ptr<IDrawable> element); ///< Добавление элемента
	void AddElement(std::shared_ptr<IDrawable> element, int i, int j); ///< Добавление элемента

	//Design getDesign();
	Vector2f GetFieldSize(); ///< Геттер

private:
	GUIStyle *gstyle;
	TextStyle *tstyle;
	GUILayer *fabric;
	friend class GUILayer;
	Table(GUILayer* fabric_, RenderWindow* renderWindow, float x, float y, float width, float height, TextStyle *tstyle, GUIStyle *gstyle);
	Table(RenderWindow* renderWindow, Vector2f xy, float width, float height);
	Table(RenderWindow* renderWindow, float x, float y, Vector2f size);
	Table(RenderWindow* renderWindow, Vector2f xy, Vector2f size);

	void init(float x, float y, float width, float height); ///< Инициализация


	//Design design;
	//Node ** fields; TODO
	std::shared_ptr<IDrawable> **elements; ///< Массив дочерних элементов
	RectangleShape border; ///< Разделитель
	Vector2f tableSize; ///< Размер
	Vector2f fieldSize; ///< Размер
	int borderSize; ///< Толщина рамки

};

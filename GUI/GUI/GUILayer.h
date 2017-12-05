#pragma once
#include <vector>
#include <string>
#include "../General/Headers.h"
#include "GUIBox.h"
#include "../Observable.h"
//по сути Layout, класс группирующий элементы интерфейса 
//как например отдельные зоны для кода, отладки и файлов в visual studio

class GUILayer : public IDrawable, ObservableGUI
{
private:
	//указатель на окно на котором находится это слой
	RenderWindow* window;
	void notifyAll(const sf::Event& event) const override;

	friend class WindowTab;
	friend class ScrollingPanel;
	//отныне слои создаеются через WindowTab->CreateGUILayer(args);
	//констуркутор, не парьтесь на этот счет, просто передавайте ему положение размеры
	//пока что вторые два аргумента передавайте (0,0) и (ширинаОкна, высотаОкна)
	//обрезание поля видимости все равно пока не работает :)
	GUILayer(RenderWindow &Swindow, Vector2f, Vector2f);
	//это метод отрисоывавает все содержимое векторов с элементами, ТРОГАТЬ ЕГО НЕ НАДО
	void Draw() override;
public:
	//КЛЮЧЕВОЙ МОМЕНТ!
	//во избежание проблем с созданием указателей пользуемся shared_ptr<НазваниеЭлемент> (гуглите, на самом деле простоая вещь, синтаксиси похож на простые указатели)
	//для сохранения инкапсуляции:
	//СОЗДАВАЙТЕ ТАКИЕ МЕТОДЫ (хотя бы 1) ДЛЯ СВОИХ ЭЛЕМЕНТОВ
	//он должен создавать элемент, сохранять его в векторе (описаны выше) и возвращать shared_ptr на него (как это используется смотрите в handler.cpp)
	std::shared_ptr<GUIBox> CreateBox(float x, float y, float width, float height, GUIStyle *gstyle);
	std::shared_ptr<GUIBox> CreateBox(Vector2f position_, Vector2f size_, GUIStyle *gstyle);
	std::shared_ptr<GUIBox> CreateBox(Vector2f position_, float width, float height, GUIStyle *gstyle);
	std::shared_ptr<GUIBox> CreateBox(float x, float y, Vector2f size_, GUIStyle *gstyle);

	std::shared_ptr<GUIButton> CreateButton(float x, float y, float width, float height, std::string text, TextStyle *tstyle, GUIStyle *gstyle, void(*action)());
	std::shared_ptr<GUIButton> CreateButton(Vector2f position_, Vector2f size_, std::string text, TextStyle *tstyle, GUIStyle *gstyle, void(*action)());
	std::shared_ptr<GUIButton> CreateButton(Vector2f position_, float width, float height, std::string text, TextStyle *tstyle, GUIStyle *gstyle, void(*action)());
	std::shared_ptr<GUIButton> CreateButton(float x, float y, Vector2f size_, std::string text, TextStyle *tstyle, GUIStyle *gstyle, void(*action)());
	
    std::shared_ptr<GUILabel> CreateLabel(float x, float y, float width, float height, std::string text, TextStyle *tstyle, GUIStyle *gstyle);
    std::shared_ptr<GUILabel> CreateLabel(Vector2f position_, Vector2f size_, std::string text, TextStyle *tstyle, GUIStyle *gstyle);
    std::shared_ptr<GUILabel> CreateLabel(float x, float y, float width, float height, std::string text, TextStyle *tstyle, Texture *texture, GUIStyle *gstyle);
    std::shared_ptr<GUILabel> CreateLabel(Vector2f position_, Vector2f size_, std::string text, TextStyle *tstyle, Texture *texture, GUIStyle *gstyle);
    std::shared_ptr<GUILabel> CreateLabel(float x, float y, float width, float height, TextStyle * tstyle, Texture * texture, GUIStyle *gstyle);
    std::shared_ptr<GUILabel> CreateLabel(Vector2f position_, Vector2f size_, TextStyle * tstyle, Texture * texture, GUIStyle *gstyle);

	std::shared_ptr<GUIProgressBar> CreateProgressBar(std::shared_ptr<GUILayer> _layer, float x, float y, float width, float height,
		std::string text, TextStyle *tstyle, GUIStyle *gstyle,
		float minValue, float maxValue, Color staticBarColor, Color dynamicBarColor);

    std::shared_ptr<MenuBar> CreateMenuBar(float x, float y, float width, float height, std::string text, TextStyle *tstyle,
        GUIStyle *gstyle,
        float leftBorder, float rightBorder, Color staticBarColor);


	std::shared_ptr<ComboBox> CreateComboBox(float x, float y, float width, float height, std::string text, TextStyle *tstyle,
		GUIStyle *gstyle,
		float leftBorder, float rightBorder, Color staticBarColor);



	std::shared_ptr<ScrollBar> CreateScrollBar(float x, float y, float width, float height, GUIStyle *gstyle, Orientation orientation, float sizeScrollPanel_);
	
	std::shared_ptr<GUIStatusBar> CreateStatusBar(float height_, float frameSize_, float spacing_, GUIStyle *sBarStyle_, Location location_);

	std::shared_ptr<GUISlider> CreateSlider(float line_position_x, float line_position_y, float line_width_, float line_height_, float handler_width_, float handler_height_, GUIStyle* gst, float value_range_from_, float value_range_to_, float value_);
	std::shared_ptr<GUISlider> CreateSlider(float line_position_x, float line_position_y, float line_width_, float line_height_, float handler_width_, float handler_height_, GUIStyle* gst, float value_range_from_, float value_range_to_, float value_, void(*action_on_move)(float slider_value));

	std::shared_ptr<TextField> CreateTextField(float x, float y, float width, float height, std::string text, TextStyle *tstyle, GUIStyle *gstyle);
	
	std::shared_ptr<TextArea> CreateTextArea(float x, float y, float width, float height, TextStyle * tstyle, GUIStyle * gstyle);
    std::shared_ptr<RadioButton> CreateRadButton(std::shared_ptr<GUILayer> layer, int count, float x, float y, float width, float height, std::vector<std::string> text, TextStyle *tstyle, GUIStyle *gstyle);
    std::shared_ptr<RadioButton> CreateRadButton(std::shared_ptr<GUILayer> layer, int count, Vector2f position, Vector2f size, std::vector<std::string> text, TextStyle *tstyle, GUIStyle *gstyle);

	//Запускает обработчики у элементов, трогать его не надо
	void handleEvent(const sf::Event& event) override;

	//TODO
	//НЕДОПИЛЕН, НЕ ЮЗАТЬ ПОКА!
	void removeElement(IDrawable* observer) override;
};

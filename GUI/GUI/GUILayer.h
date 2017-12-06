#pragma once
#include <vector>
#include <string>
#include "../General/Headers.h"
#include "GUIBox.h"
#include "../Observable.h"

/*!
\brief Фабрика и базовый отрисовщик элементов

Класс, являющийся фабрикой элементов и родителем для элемнтов без явного назначенных родителей
*/
class GUILayer : public IDrawable, ObservableGUI
{
private:
	RenderWindow* window;//!< указатель на окно на котором находится это слой
	//! Оповестить всех слушателей о событии
	void notifyAll(const sf::Event& event) const override;

	friend class WindowTab;
	friend class ScrollingPanel;
	/*!
	\brief Конструктор класса

	\param renderWindow Окно, в котором будет расположен layer
	\param position Расположение layer
	\param size Размер layer

	Конструктор слоя элементов
	*/
	GUILayer(RenderWindow &Swindow, Vector2f, Vector2f);
	//! Переопределяем функцию Draw
	void Draw() override;
public:

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

	std::shared_ptr<GUICheckButton> CreateCheckButton(float x, float y, float width, float height, std::string text, TextStyle *tstyle, GUIStyle *gstyle, void(*action)());

	std::shared_ptr<ScrollBar> CreateScrollBar(float x, float y, float width, float height, GUIStyle *gstyle, Orientation orientation, float sizeScrollPanel_);

	std::shared_ptr<GUIStatusBar> CreateStatusBar(float height_, float frameSize_, float spacing_, GUIStyle *sBarStyle_, Location location_);

	std::shared_ptr<GUISlider> CreateSlider(float line_position_x, float line_position_y, float line_width_, float line_height_, float handler_width_, float handler_height_, GUIStyle* gst, float value_range_from_, float value_range_to_, float value_);
	std::shared_ptr<GUISlider> CreateSlider(float line_position_x, float line_position_y, float line_width_, float line_height_, float handler_width_, float handler_height_, GUIStyle* gst, float value_range_from_, float value_range_to_, float value_, void(*action_on_move)(float slider_value));

	std::shared_ptr<TextField> CreateTextField(float x, float y, float width, float height, std::string text, TextStyle *tstyle, GUIStyle *gstyle);

	std::shared_ptr<TextArea> CreateTextArea(float x, float y, float width, float height, TextStyle * tstyle, GUIStyle * gstyle);
    std::shared_ptr<RadioButton> CreateRadButton(std::shared_ptr<GUILayer> layer, int count, float x, float y, float width, float height, std::vector<std::string> text, TextStyle *tstyle, GUIStyle *gstyle);
    std::shared_ptr<RadioButton> CreateRadButton(std::shared_ptr<GUILayer> layer, int count, Vector2f position, Vector2f size, std::vector<std::string> text, TextStyle *tstyle, GUIStyle *gstyle);

	std::shared_ptr<Table> CreateTable(float x, float y, float width, float height, TextStyle *tst, GUIStyle *gst);

	//! перегрузка функции обработки событий
	void handleEvent(const sf::Event& event) override;

	//! TODO
	void removeElement(IDrawable* observer) override;
};

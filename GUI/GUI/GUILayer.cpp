#include "GUIlayer.h"
#include <iostream>

GUILayer::GUILayer(RenderWindow &Swindow, Vector2f position_, Vector2f size_) : IDrawable(position_, size_)
{
	window = &Swindow;
}

std::shared_ptr<GUIBox> GUILayer::CreateBox(float x, float y, float width, float height, GUIStyle *gstyle)
{
	std::shared_ptr<GUIBox> box(new GUIBox(window, x, y, width, height, gstyle));
	box->parent = this;
	elements.push_back(box);
	return box;
}
std::shared_ptr<GUIBox> GUILayer::CreateBox(Vector2f position_, Vector2f size_, GUIStyle *gstyle)
{
	std::shared_ptr<GUIBox> box(new GUIBox(window, position_, size_, gstyle));
	box->parent = this;
	elements.push_back(box);
	return box;
}
std::shared_ptr<GUIBox> GUILayer::CreateBox(float x, float y, Vector2f size_, GUIStyle *gstyle)
{
	std::shared_ptr<GUIBox> box(new GUIBox(window, x, y, size_, gstyle));
	box->parent = this;
	elements.push_back(box);
	return box;
}
std::shared_ptr<GUIBox> GUILayer::CreateBox(Vector2f position_, float width, float height, GUIStyle *gstyle)
{
	std::shared_ptr<GUIBox> box(new GUIBox(window, position_, width, height, gstyle));
	box->parent = this;
	elements.push_back(box);
	return box;
}

std::shared_ptr<GUIButton> GUILayer::CreateButton(float x, float y, float width, float height, std::string text_, TextStyle *tstyle, GUIStyle *gstyle, void(*action)())
{
	std::shared_ptr<GUIButton> button(new GUIButton(this, window, x, y, width, height, text_, tstyle, gstyle, action));
	button->parent = this;
	elements.push_back(button);
	return button;
}
std::shared_ptr<GUIButton> GUILayer::CreateButton(Vector2f position_, Vector2f size_, std::string text_, TextStyle *tstyle, GUIStyle *gstyle, void(*action)())
{
	std::shared_ptr<GUIButton> button(new GUIButton(this, window, position_, size_, text_, tstyle, gstyle, action));
	button->parent = this;
	elements.push_back(button);
	return button;
}
std::shared_ptr<GUIButton> GUILayer::CreateButton(Vector2f position_, float width, float height, std::string text_, TextStyle *tstyle, GUIStyle *gstyle, void(*action)())
{
	std::shared_ptr<GUIButton> button(new GUIButton(this, window, position_, width, height, text_, tstyle, gstyle, action));
	button->parent = this;
	elements.push_back(button);
	return button;
}
std::shared_ptr<GUIButton> GUILayer::CreateButton(float x, float y, Vector2f size_, std::string text_, TextStyle *tstyle, GUIStyle *gstyle, void(*action)())
{
	std::shared_ptr<GUIButton> button(new GUIButton(this, window, x, y, size_, text_, tstyle, gstyle, action));
	button->parent = this;
	elements.push_back(button);
	return button;
}

std::shared_ptr<GUILabel> GUILayer::CreateLabel(float x, float y, float width, float height, std::string text_, TextStyle *tstyle, GUIStyle *gstyle)
{
	return CreateLabel(Vector2f(x, y), Vector2f( width, height), text_, tstyle, gstyle);
}
std::shared_ptr<GUILabel> GUILayer::CreateLabel(Vector2f position_, Vector2f size_, std::string text_, TextStyle * tstyle, GUIStyle * gstyle)
{
	std::shared_ptr<GUILabel> label(new GUILabel(window, position_, size_, text_, tstyle, gstyle));
	label->parent = this;
	elements.push_back(label);
	return label;
}
std::shared_ptr<GUILabel> GUILayer::CreateLabel(float x, float y, float width, float height, std::string text_, TextStyle * tstyle, Texture * texture, GUIStyle *gstyle)
{
	return CreateLabel(Vector2f(x, y), Vector2f(width, height), text_, tstyle, texture, gstyle);
}
std::shared_ptr<GUILabel> GUILayer::CreateLabel(Vector2f position_, Vector2f size_, std::string text_, TextStyle * tstyle, Texture * texture, GUIStyle *gstyle)
{
	std::shared_ptr<GUILabel> label(new GUILabel(window, position_, size_, text_, tstyle, texture, gstyle));
	label->parent = this;
	elements.push_back(label);
	return label;
}
std::shared_ptr<GUILabel> GUILayer::CreateLabel(float x, float y, float width, float height, TextStyle * tstyle, Texture * texture, GUIStyle *gstyle)
{
    return CreateLabel(Vector2f(x, y), Vector2f(width, height), tstyle, texture, gstyle);
}
std::shared_ptr<GUILabel> GUILayer::CreateLabel(Vector2f position_, Vector2f size_, TextStyle * tstyle, Texture * texture, GUIStyle *gstyle)
{
    std::shared_ptr<GUILabel> label(new GUILabel(window, position_, size_, tstyle, texture, gstyle));
    label->parent = this;
    elements.push_back(label);
    return label;
}

std::shared_ptr<GUIProgressBar> GUILayer::CreateProgressBar(std::shared_ptr<GUILayer> _layer, float x, float y, float width, float height,
	std::string text_, TextStyle *tstyle, GUIStyle *gstyle,
	float minValue, float maxValue, Color staticBarColor, Color dynamicBarColor)
{
	std::shared_ptr<GUIProgressBar> progressBar(new GUIProgressBar(window, _layer, x, y, width, height, text_, tstyle, gstyle, minValue, maxValue, staticBarColor, dynamicBarColor));
	progressBar->parent = this;
	elements.push_back(progressBar);
	return progressBar;
}

void GUILayer::notifyAll(const sf::Event & event) const
{
	for (auto& element : elements)
		element->handleEvent(event);
}

void GUILayer::removeElement(IDrawable* observer)
{
	IDrawable* IDispPtr = dynamic_cast<IDrawable*> (observer);
	auto position = std::find_if(elements.begin(), elements.end(),
		[IDispPtr](std::shared_ptr<IDrawable> const& i)
	{ return i.get() == IDispPtr; });
	if (position != elements.end())
		std::cout << "found" << std::endl;
}

void GUILayer::handleEvent(const sf::Event & event)
{
	notifyAll(event);
}

void GUILayer::Draw()
{
	for (std::shared_ptr<IDrawable> bo : elements)
		bo->Draw();
}

std::shared_ptr<ScrollBar> GUILayer::CreateScrollBar(float x, float y, float width, float height,
	GUIStyle *gstyle, Orientation orientation, float sizeScrollPanel_) {
	std::shared_ptr<ScrollBar> scrollbar(new ScrollBar(window, orientation, gstyle, sizeScrollPanel_));
	scrollbar->parent = this;
	elements.push_back(scrollbar);
	return scrollbar;
}

std::shared_ptr<GUISlider> GUILayer::CreateSlider(float line_position_x, float line_position_y, float line_width_, float line_height_, float handler_width_, float handler_height_, GUIStyle* gst, float value_range_from_, float value_range_to_, float value_)
{
	std::shared_ptr<GUISlider> slider(new GUISlider(this, window, line_position_x, line_position_y, line_width_, line_height_, handler_width_, handler_height_, gst, value_range_from_, value_range_to_, value_));
	slider->parent = this;
	elements.push_back(slider);
	return slider;
}

std::shared_ptr<GUISlider> GUILayer::CreateSlider(float line_position_x, float line_position_y, float line_width_, float line_height_, float handler_width_, float handler_height_, GUIStyle* gst, float value_range_from_, float value_range_to_, float value_, void(*action_on_move)(float slider_value))
{
	std::shared_ptr<GUISlider> slider(new GUISlider(this, window, line_position_x, line_position_y, line_width_, line_height_, handler_width_, handler_height_, gst, value_range_from_, value_range_to_, value_, action_on_move));
	slider->parent = this;
	elements.push_back(slider);
	return slider;
}

std::shared_ptr<GUIStatusBar> GUILayer::CreateStatusBar(float height_, float frameSize_,
	float spacing_, GUIStyle *sBarStyle_, Location location_)
{
	std::shared_ptr<GUIStatusBar> statusBar(new GUIStatusBar(window, height_, frameSize_,
		spacing_, sBarStyle_, location_));
	statusBar->parent = this;
	elements.push_back(statusBar);
	return statusBar;
}

std::shared_ptr<MenuBar> GUILayer::CreateMenuBar(float x, float y, float width, float height, std::string text, TextStyle *tstyle,
    GUIStyle *gstyle,
    float leftBorder, float rightBorder, Color staticBarColor)
{
    std::shared_ptr<MenuBar> menuBar(new MenuBar(window, x, y, width, height, text, tstyle, gstyle, leftBorder, rightBorder, staticBarColor, this));
    menuBar->parent = this;
    elements.push_back(menuBar);
    return menuBar;
}
std::shared_ptr<ComboBox> GUILayer::CreateComboBox(float x, float y, float width, float height, std::string text, TextStyle *tstyle,
	GUIStyle *gstyle,
	float leftBorder, float rightBorder, Color staticBarColor)
{
	std::shared_ptr<ComboBox> comboBox(new ComboBox(window, x, y, width, height, text, tstyle, gstyle, leftBorder, rightBorder, staticBarColor, this));
	comboBox->parent = this;
	elements.push_back(comboBox);
	return comboBox;
}

std::shared_ptr<TextField> GUILayer::CreateTextField(float x, float y, float width, float height, std::string text_, TextStyle *tstyle, GUIStyle *gstyle)
{
	std::shared_ptr<TextField> textField(new TextField(window, x, y, width, height, text_, tstyle, gstyle));
	textField->parent = this;
	elements.push_back(textField);
	return textField;
}

std::shared_ptr<TextArea> GUILayer::CreateTextArea(float x, float y, float width, float height, TextStyle * tstyle, GUIStyle * gstyle)
{
	std::shared_ptr<TextArea> textarea(new TextArea(window, x, y, width, height, tstyle, gstyle));
	elements.push_back(textarea);
	return textarea;
}
std::shared_ptr<RadioButton> GUILayer::CreateRadButton(std::shared_ptr<GUILayer> layer, int count, float x, float y, float width, float height, std::vector<std::string> text, TextStyle * tstyle, GUIStyle * gstyle)
{
    std::shared_ptr<RadioButton> radBut(new RadioButton(layer, window, count, x, y, width, height, text, tstyle, gstyle));
    elements.push_back(radBut);
    return radBut;
}

std::shared_ptr<RadioButton> GUILayer::CreateRadButton(std::shared_ptr<GUILayer> layer, int count, Vector2f position, Vector2f size, std::vector<std::string> text, TextStyle * tstyle, GUIStyle * gstyle)
{
    std::shared_ptr<RadioButton> radBut(new RadioButton(layer, window, count, position.x, position.y, size.x, size.y, text, tstyle, gstyle));
    elements.push_back(radBut);
    return radBut;
}
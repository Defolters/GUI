#pragma once
#include "../../GUI/GUIBox.h"
#include <vector>
#include <memory>  
#include "CheckButton.h"
#include "../../GUI/GUILayer.h"
class RadioButton: public  IDisplayable
{
public:
	RadioButton(std::shared_ptr<GUILayer> layer, RenderWindow* renderWindow_, int count, float x, float y, float width, float height, std::vector<std::string> text, TextStyle *tstyle, GUIStyle *gstyle);
	~RadioButton();
	std::vector<bool> getState();
protected:
	void Draw() override;
	void handleEvent(const sf::Event & event) override;
private:
	std::vector<GUILabel*> labels;
	std::vector<CheckButton*> options;
	std::vector<bool> stateArray;
};


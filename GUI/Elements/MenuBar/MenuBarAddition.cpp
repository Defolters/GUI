#include "../../GUI/GUILayer.h"
#include "MenuBar.h"



void MenuBar::addButton(std::string name, void(*action)())

{
	//пример создания стиля gui
	static GUIStyle gst;
	gst.mainTex.loadFromFile("resources/03.png");
	gst.pressTex.loadFromFile("resources/04.png");
	gst.overTex.loadFromFile("resources/05.png");

	gst.frameWid = 3;

	//пример создания стиля текста
	static TextStyle tst;
	tst.font.loadFromFile("resources/Robotic.ttf");
	tst.color.r = tst.color.g = tst.color.b = 255;
	tst.fontSize = 30;
	tst.align = 'c';

	std::shared_ptr<GUIBox> box;
	buttonVect.push_back(box);
	
	box = layer->CreateButton(buttonPosHelp, 5, buttonSizeHelp, 40, name, &tst, &gst, action);
	buttonPosHelp = buttonPosHelp + buttonSizeHelp;
	///resizing test
	
	///
}
void MenuBar::resizing()
{
	for (auto a = buttonVect.begin(); a != buttonVect.end(); ++a)
	{
	//	(*a)->GetPosition();
		//buttonPosHelp += (*a)->GetSize().x + 10;
		//((*a)->SetPosition(renderWindow->getSize().x - buttonPosHelp, renderWindow->getSize().y - (*a)->GetSize().y));
	}
 }
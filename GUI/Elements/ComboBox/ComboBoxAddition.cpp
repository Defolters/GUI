#include "../../GUI/GUILayer.h"
#include "ComboBox.h"



void ComboBox::addButton(std::string name, void(*action)())

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

	//пример создания просто "коробки" с созданными стилями, положением 0,0 и размером 300,400 на созданном выше слое
	std::shared_ptr<GUIBox> box;
	buttonVect.push_back(box);

	box = layer->CreateButton(buttonPosHelp, 500, 200, 40, name, &tst, &gst, action);
	buttonPosHelp = buttonPosHelp + 200;

}
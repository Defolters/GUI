#pragma once
#include <map>
#include "../GUI/GUILayer.h"

//просто примите его существование как данность пока что, пользутесь им так же как написан ов handler.cpp (можете прост ctrl-c)
class WindowTab
{
private:
	
public:
	std::map<std::string, GUILayer> GUILayers;
	RenderWindow window;
//TODO	(GUILayer*)addGUILayer(std::string name);
//TODO	void Redraw();
	WindowTab(VideoMode mode, char* name);
	~WindowTab();
};


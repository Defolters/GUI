#pragma once
#include <map>
#include "../GUI/GUILayer.h"

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


#pragma once
#include <map>
#include "../GUI/GUILayer.h"
#include "../Objects/ObjectsField.h"
#include "../Objects/WindowObject.h"

class WindowTab
{
private:
	
public:
	std::vector<std::shared_ptr<WindowObject>> objects;
	std::vector<std::shared_ptr<ObjectField>> fields;
	std::map<std::string, GUILayer> GUILayers;
	RenderWindow window;
	void DrawWindowObjects();
	std::shared_ptr<WindowObject> WindowObj(Texture * src, Vector2f size_, Vector2f position_);
	std::shared_ptr<WindowObject> WindowObj(Texture * src, IntRect orig, Vector2f size_, Vector2f position_);
	std::shared_ptr<WindowObject> WindowObj(Texture * src, IntRect orig, Vector2f size_, Vector2f position_, int frm, float leng);
//	(GUILayer*)addGUILayer(std::string name);
	WindowTab(VideoMode mode, char* name);
	~WindowTab();
};


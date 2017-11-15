#include "WindowTab.h"

std::shared_ptr<WindowObject> WindowTab::WindowObj(Texture * src, Vector2f size_, Vector2f position_)
{
	std::shared_ptr<WindowObject> obj (new WindowObject(&window, src, size_, position_));
	objects.push_back(obj);
	return obj;
}

std::shared_ptr<WindowObject> WindowTab::WindowObj(Texture * src, IntRect orig, Vector2f size_, Vector2f position_)
{
	std::shared_ptr<WindowObject> obj (new WindowObject(&window, src, orig, size_, position_));
	objects.push_back(obj);
	return obj;
}

std::shared_ptr<WindowObject> WindowTab::WindowObj(Texture * src, IntRect orig, Vector2f size_, Vector2f position_, int frm, float leng)
{
	std::shared_ptr<WindowObject> obj (new WindowObject(&window, src, orig, size_, position_, frm, leng));
	objects.push_back(obj);
	return obj;
}

void WindowTab::DrawWindowObjects()
{
	for (std::shared_ptr<WindowObject> obj : objects)
		obj->Draw();
}

WindowTab::WindowTab(VideoMode mode, char * name) : window (mode,name)
{

}

WindowTab::~WindowTab()
{
}

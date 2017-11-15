#include "Headers.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

//окей. теперь fun part
void main() 
{
	//пример создания стиля gui
	static GUIStyle gst;
	gst.mainTex.loadFromFile("backGUI.png");
	gst.pressTex.loadFromFile("pressGUI.png");
	gst.overTex.loadFromFile("overGUI.png");
	gst.frame.loadFromFile("frame.png");
	gst.frameWid = 5;

	//пример создания стиля текста
	static TextStyle tst;
	tst.font.loadFromFile("alte-haas-grotesk.regular.ttf");
	tst.color.r = tst.color.g = tst.color.b = 10;
	tst.fontSize = 22;
	tst.align = 'c';
	
	//создание окна и слоя гуи на нем (можете прям копировать, если лень разбираться, да оно и не сильно надо пока)
	WindowTab main(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "main");
	GUILayer layer(main.window, Vector2f(0,0), Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	//вот досюда

	//пример создания просто "коробки" с созданными стилями, положением 0,0 и размером 300,400 на созданном выше слое
	std::shared_ptr<GUIBox> box = layer.CreateBox(0, 0, 300, 400, "omegaLUL", &tst, &gst);

	//тоже можете просто копировать, это я потом сам допишу
	while (main.window.isOpen())
	{
		main.window.clear();
		Event event;
		while (main.window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				main.window.close();
		}
		layer.Draw();
		main.window.display();
	}
}

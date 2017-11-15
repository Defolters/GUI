#include "Headers.h"

void main() 
{
	static GUIStyle gst;
	gst.mainTex.loadFromFile("backGUI.png");
	gst.pressTex.loadFromFile("pressGUI.png");
	gst.overTex.loadFromFile("overGUI.png");
	gst.frame.loadFromFile("frame.png");
	gst.frameWid = 5;

	static TextStyle tst;
	tst.font.loadFromFile("alte-haas-grotesk.regular.ttf");
	tst.color.r = tst.color.g = tst.color.b = 10;
	tst.fontSize = 22;
	tst.align = 'c';
	
	WindowTab main(VideoMode(800, 600), "Ants");
	
	GUILayer layer(main.window);
	std::shared_ptr<GUIBox> box = layer.CreateBox(0, 0, 300, 400, "omegaLUL", &tst, &gst);
	
	while (main.window.isOpen())
	{
		main.window.clear();
		Event event;
		while (main.window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				main.window.close();
		}
		layer.DrawAll();
		main.window.display();
	}
}
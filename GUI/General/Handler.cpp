#include "Handler.h"

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
	
	GUILayer hui(main.window);
	std::shared_ptr<GUIBox> huebox = hui.CreateBox(0, 0, 300, 400, "fuck you", &tst, &gst);
	static Texture objWTex;
	objWTex.loadFromFile("anthill_1.png");
	std::shared_ptr<WindowObject> objW = main.WindowObj(&objWTex, Vector2f(1, 1), Vector2f(400, 0));
	
	while (main.window.isOpen())
	{
		main.window.clear();
		Event event;
		while (main.window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				main.window.close();
		}
		hui.DrawAll();
		main.DrawWindowObjects();
		main.window.display();
	}
}
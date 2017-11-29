#include "../Window/WindowTab.h"
#include <Windows.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

void buttonAction()
{
	std::cout << "Button pressed!" << std::endl;
}

//функция, которая будет вызываться каждый кадр во время перемещения слайдера
void onSliderMove(float slider_value)
{
	std::cout << "slider value = " << slider_value << std::endl;
}
void buttonAction1()
{
    std::cout << "Button 1 pressed!" << std::endl;
}
void buttonAction2()
{
    std::cout << "Button 2 pressed!" << std::endl;
}
void buttonAction3()
{
    std::cout << "Button 3 pressed!" << std::endl;
}
void buttonAction4()
{
    std::cout << "Button 4 pressed!" << std::endl;
}
//окей. теперь fun part
void main()
{
	//пример создания стиля gui
	static GUIStyle gst;
	gst.mainTex.loadFromFile("backGUI.png");
	gst.pressTex.loadFromFile("pressGUI.png");
	gst.overTex.loadFromFile("overGUI.png");
	gst.frame.loadFromFile("frame.png");
	gst.background.loadFromFile("statusBar.png");
	gst.frameWid = 5;
	//текстуры слайдера
	+gst.sliderBackTex.loadFromFile("slider_back_line.png");
	+gst.sliderFrontTex.loadFromFile("slider_front_line.png");
	+gst.sliderHandlerTex.loadFromFile("slider_handler.png");


    static GUIStyle gst2;
    gst2.mainTex.loadFromFile("01.png");
    gst2.frame.loadFromFile("02.png");
    gst2.frameWid = 5;
	//пример создания стиля текста
	static TextStyle tst;
	tst.font.loadFromFile("Robotic.ttf");
	tst.color.r = tst.color.g = tst.color.b = 255;
	tst.fontSize = 22;
	tst.align = 'c';

	static GUIStyle sBarStyle;
	sBarStyle.background.loadFromFile("statusBar.png");
	
	//создание окна и слоя гуи на нем 
	WindowTab main(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "main");
	std::shared_ptr<GUILayer> layer = main.CreateGUILayer(Vector2f(0,0), Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	//вот досюда

	//пример создания кнопки
	//std::shared_ptr<GUIButton> button = layer->CreateButton(20, 20, 100,100, "button", &tst, &gst, &buttonAction);

	// создание label
	Texture icon, icon2;
	icon.loadFromFile("Danger.png");
	icon2.loadFromFile("Galaxy.png");
	// просто текст
	std::shared_ptr<GUILabel> label = layer->CreateLabel(0, 300, 100, 20, "Just text", &tst, &gst);
	// иконка
	std::shared_ptr<GUILabel> label1 = layer->CreateLabel(0, 330, 100, 40, "", &tst, &icon, &gst);
	// текст и иконка
	std::shared_ptr<GUILabel> label2 = layer->CreateLabel(0, 400, 100, 40, "text to the right of the icon", &tst, &icon2, &gst);

	//сохраняем ID label2
	int label2ID = label2->GetID();
	//добавляем label1 уже существующий label2 как дочерний
	label1->AddElement(label2);
	//получаем указатель на label2, находя его по id
	auto label2again = label1->GetElement(label2ID);
	if (label2again.get() != nullptr)//если label2 дочерний для label1, то вернется указатель на него, если нет, то на nullptr
		std::cout << "label2 is child of label1!" << std::endl;
	// Cоздание прогресс бара. 
	std::shared_ptr<GUIProgressBar> progressBar = layer->CreateProgressBar(layer, SCREEN_WIDTH / 3 + 50, SCREEN_HEIGHT / 3, 200, 30, "Sorting...", &tst, &gst,
		0, 200, Color::White, Color::Green);

    std::shared_ptr<ScrollBar> scrollbarHor = layer->CreateScrollBar(0, 0, 0, 0, &gst, Orientation::HORIZONTAL, 1600);

    std::shared_ptr<ScrollBar> scrollbarVert = layer->CreateScrollBar(0, 0, 0, 0, &gst, Orientation::VERTICAL, 1800);

	//создаем слайдер
	std::shared_ptr<Slider> slider = layer->CreateSlider(225, 450, 350, 20, 35, 38, &gst, 0, 100, 20, &onSliderMove);

	//Создание статус бара
	std::shared_ptr<GUIStatusBar>  statusBar = layer->CreateStatusBar(40, 5, 10, &sBarStyle);
	std::shared_ptr<GUIBox> box1 = layer->CreateButton(100, 0, 50, 50, "", &tst, &gst, &buttonAction);
	std::shared_ptr<GUIBox> box2 = layer->CreateButton(0, 0, 1, 1, "B", &tst, &gst, &buttonAction);
	std::shared_ptr<GUIBox> box3 = layer->CreateButton(0, 0, 4, 1, "Test", &tst, &gst, &buttonAction);
	statusBar->AddElement(box1);
	statusBar->AddElement(box2);
	statusBar->AddElement(box3);


    //menu bar
    std::shared_ptr<MenuBar> menuBar = layer->CreateMenuBar(0, 0, SCREEN_WIDTH - 12, 50, "", &tst, &gst2,
        0, 200, Color::White);
    menuBar->addButton("1", &buttonAction1);
    menuBar->addButton("2", &buttonAction2);
    menuBar->addButton("3", &buttonAction3);
    menuBar->addButton("4", &buttonAction4);

	std::shared_ptr<TextField> textBox = layer->CreateTextField(250, 350, 100, 40, "textField", &tst, &gst);

	std::shared_ptr<TextArea> textArea = layer->CreateTextArea(400, 300, 300, 200, &tst, &gst);

	while (1)
	{
		// Костыль для теста на время, пока нет Observer.
		// Потом будет передаваться ивент об изменении значения бара.
		//*****тест ProgressBar****
		progressBar->increase();
		Sleep(20);
		//*************************

		main.Redraw();
	}	
}

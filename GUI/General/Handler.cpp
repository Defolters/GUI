#include "../Window/WindowTab.h"
#include <Windows.h>
#define LABEL_DEBUG false

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
    gst.mainTex.loadFromFile("resources/backGUI.png");
    gst.pressTex.loadFromFile("resources/pressGUI.png");
    gst.overTex.loadFromFile("resources/overGUI.png");
    gst.frame.loadFromFile("resources/frame.png");
    gst.background.loadFromFile("resources/statusBar.png");
    gst.frameWid = 5;
    //текстуры слайдера
    +gst.sliderBackTex.loadFromFile("resources/slider_back_line.png");
    +gst.sliderFrontTex.loadFromFile("resources/slider_front_line.png");
    +gst.sliderHandlerTex.loadFromFile("resources/slider_handler.png");


    static GUIStyle gst2;
    gst2.mainTex.loadFromFile("resources/01.png");
    gst2.frame.loadFromFile("resources/02.png");
    gst2.frameWid = 5;
    //пример создания стиля текста
    static TextStyle tst;
    tst.font.loadFromFile("resources/Robotic.ttf");
    tst.color.r = tst.color.g = tst.color.b = 255;
    tst.fontSize = 22;
    tst.align = 'c';

    static GUIStyle sBarStyle;
    sBarStyle.background.loadFromFile("resources/statusBar.png");
	sBarStyle.color = Color::Blue;

    //создание окна и слоя гуи на нем 
    WindowTab main(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "main");
    std::shared_ptr<GUILayer> layer = main.CreateGUILayer(Vector2f(0, 0), Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
    //вот досюда

    //пример создания кнопки
    //std::shared_ptr<GUIButton> button = layer->CreateButton(20, 20, 100,100, "button", &tst, &gst, &buttonAction);

    // создание label
    Texture icon, icon2;
    icon.loadFromFile("resources/Danger.png");

    // test label
    if (LABEL_DEBUG)
    {
        // просто текст, который меняется под размер бокса
        std::shared_ptr<GUILabel> label1 = layer->CreateLabel(5, 10, 100, 40, "LEFT", &tst, &gst);
        label1->SetHorizontalAlignment(Alignment::LEFT);
        std::shared_ptr<GUILabel> label2 = layer->CreateLabel(5, 55, 100, 40, "RIGHT", &tst, &gst);
        label2->SetHorizontalAlignment(Alignment::RIGHT);
        std::shared_ptr<GUILabel> label3 = layer->CreateLabel(5, 100, 100, 40, "TOP", &tst, &gst);
        label3->SetVerticalAlignment(Alignment::TOP);
        std::shared_ptr<GUILabel> label4 = layer->CreateLabel(5, 145, 100, 40, "BOTTOM", &tst, &gst);
        label4->SetVerticalAlignment(Alignment::BOTTOM);
        std::shared_ptr<GUILabel> label5 = layer->CreateLabel(5, 190, 100, 40, "CENTER", &tst, &gst);

        // просто текст, который НЕ меняется под размер бокса
        std::shared_ptr<GUILabel> labelN1 = layer->CreateLabel(5, 255, 100, 40, "LEFT", &tst, &gst);
        labelN1->SetHorizontalAlignment(Alignment::LEFT);
        labelN1->SetDependsOnSize(false);
        std::shared_ptr<GUILabel> labelN2 = layer->CreateLabel(5, 300, 100, 40, "RIGHT", &tst, &gst);
        labelN2->SetHorizontalAlignment(Alignment::RIGHT);
        labelN2->SetDependsOnSize(false);
        std::shared_ptr<GUILabel> labelN3 = layer->CreateLabel(5, 345, 100, 40, "TOP", &tst, &gst);
        labelN3->SetVerticalAlignment(Alignment::TOP);
        labelN3->SetDependsOnSize(false);
        std::shared_ptr<GUILabel> labelN4 = layer->CreateLabel(5, 390, 100, 40, "BOTTOM", &tst, &gst);
        labelN4->SetVerticalAlignment(Alignment::BOTTOM);
        labelN4->SetDependsOnSize(false);
        std::shared_ptr<GUILabel> labelN5 = layer->CreateLabel(5, 435, 100, 40, "CENTER", &tst, &gst);
        labelN5->SetDependsOnSize(false);

        // просто иконка, которая меняется под размер бокса 5 по y 30 х
        std::shared_ptr<GUILabel> labelIcon1 = layer->CreateLabel(140, 10, 100, 50, "", &tst, &icon, &gst);
        labelIcon1->SetHorizontalAlignment(Alignment::LEFT);
        std::shared_ptr<GUILabel> labelIcon2 = layer->CreateLabel(140, 65, 100, 50, "", &tst, &icon, &gst);
        labelIcon2->SetHorizontalAlignment(Alignment::RIGHT);
        std::shared_ptr<GUILabel> labelIcon3 = layer->CreateLabel(140, 120, 100, 50, "", &tst, &icon, &gst);
        labelIcon3->SetVerticalAlignment(Alignment::TOP);
        std::shared_ptr<GUILabel> labelIcon4 = layer->CreateLabel(140, 175, 100, 50, "", &tst, &icon, &gst);
        labelIcon4->SetVerticalAlignment(Alignment::BOTTOM);
        std::shared_ptr<GUILabel> labelIcon5 = layer->CreateLabel(140, 230, 100, 50, "", &tst, &icon, &gst);

        // просто иконка, которая НЕ меняется под размер бокса
        std::shared_ptr<GUILabel> labelIconN1 = layer->CreateLabel(140, 305, 100, 50, "", &tst, &icon, &gst);
        labelIconN1->SetHorizontalAlignment(Alignment::LEFT);
        labelIconN1->SetDependsOnSize(false);
        std::shared_ptr<GUILabel> labelIconN2 = layer->CreateLabel(140, 360, 100, 50, "", &tst, &icon, &gst);
        labelIconN2->SetHorizontalAlignment(Alignment::RIGHT);
        labelIconN2->SetDependsOnSize(false);
        std::shared_ptr<GUILabel> labelIconN3 = layer->CreateLabel(140, 415, 100, 50, "", &tst, &icon, &gst);
        labelIconN3->SetVerticalAlignment(Alignment::TOP);
        labelIconN3->SetDependsOnSize(false);
        std::shared_ptr<GUILabel> labelIconN4 = layer->CreateLabel(140, 470, 100, 50, "", &tst, &icon, &gst);
        labelIconN4->SetVerticalAlignment(Alignment::BOTTOM);
        labelIconN4->SetDependsOnSize(false);
        std::shared_ptr<GUILabel> labelIconN5 = layer->CreateLabel(140, 525, 100, 50, "", &tst, &icon, &gst);
        labelIconN5->SetDependsOnSize(false);


        std::shared_ptr<GUILabel> labelTextIcon1 = layer->CreateLabel(400, 10, 100, 50, "Left", &tst, &icon, &gst);
        labelTextIcon1->SetTextToIconAlignment(Alignment::LEFT);
        std::shared_ptr<GUILabel> labelTextIcon2 = layer->CreateLabel(400, 75, 100, 50, "RIGHT", &tst, &icon, &gst);
        labelTextIcon2->SetTextToIconAlignment(Alignment::RIGHT);
        std::shared_ptr<GUILabel> labelTextIcon3 = layer->CreateLabel(400, 155, 100, 50, "TOP", &tst, &icon, &gst);
        labelTextIcon3->SetTextToIconAlignment(Alignment::TOP);
        std::shared_ptr<GUILabel> labelTextIcon4 = layer->CreateLabel(400, 225, 100, 50, "BOTTOM", &tst, &icon, &gst);
        labelTextIcon4->SetTextToIconAlignment(Alignment::BOTTOM);
        std::shared_ptr<GUILabel> labelTextIcon5 = layer->CreateLabel(400, 310, 100, 50, "CENTER", &tst, &icon, &gst);
    }
    
    // Cоздание прогресс бара. 
    std::shared_ptr<GUIProgressBar> progressBar = layer->CreateProgressBar(layer, SCREEN_WIDTH / 3 + 50, SCREEN_HEIGHT / 3, 200, 30, "Sorting...", &tst, &gst,
        0, 200, Color::White, Color::Green);

    std::shared_ptr<ScrollBar> scrollbarHor = layer->CreateScrollBar(0, 0, 0, 0, &gst, Orientation::HORIZONTAL, 1600);

    std::shared_ptr<ScrollBar> scrollbarVert = layer->CreateScrollBar(0, 0, 0, 0, &gst, Orientation::VERTICAL, 1800);

    //создаем слайдер
    std::shared_ptr<Slider> slider = layer->CreateSlider(225, 450, 350, 20, 35, 38, &gst, 0, 100, 20, &onSliderMove);

    //Создание статус бара
    std::shared_ptr<GUIStatusBar>  statusBar = layer->CreateStatusBar(50, 5, 20, &sBarStyle, Location::UPSIDE);
    std::shared_ptr<GUIBox> box1 = layer->CreateButton(100, 0, 50, 50, "A", &tst, &gst, &buttonAction);
    std::shared_ptr<GUIBox> box2 = layer->CreateButton(0, 0, 1, 1, "B", &tst, &gst, &buttonAction);
    std::shared_ptr<GUIBox> box3 = layer->CreateButton(0, 0, 4, 1, "Test", &tst, &gst, &buttonAction);
	std::shared_ptr<TextField> textBox1 = layer->CreateTextField(250, 350, 120, 40, "PrintOnMe", &tst, &gst);
	std::shared_ptr<GUILabel> label1 = layer->CreateLabel(5, 10, 100, 40, "READY...", &tst, &gst);
	label1->SetHorizontalAlignment(Alignment::LEFT);
    statusBar->AddElement(box1);
    statusBar->AddElement(box2);
    statusBar->AddElement(box3);
	statusBar->AddElement(textBox1);
	statusBar->AddElement(label1);
	statusBar->setLocation(Location::DOWNSIDE);

    //menu bar
    /*std::shared_ptr<MenuBar> menuBar = layer->CreateMenuBar(0, 0, SCREEN_WIDTH - 12, 50, "", &tst, &gst2,
        0, 200, Color::White);
    menuBar->addButton("1", &buttonAction1);
    menuBar->addButton("2", &buttonAction2);
    menuBar->addButton("3", &buttonAction3);
    menuBar->addButton("4", &buttonAction4);*/

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

#include "../Window/WindowTab.h"
#include <Windows.h>
#include "../Locale.h"

#define LABEL_DEBUG false
#define PANEL_DEBUG true
#define RADIO_DEBUG false
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
	Locale locale("resources/english.json");
    //пример создания стиля gui
    static GUIStyle gst;
    gst.mainTex.loadFromFile("resources/backGUI.png");
    gst.pressTex.loadFromFile("resources/pressGUI.png");
    gst.overTex.loadFromFile("resources/overGUI.png");
    gst.frame.loadFromFile("resources/frame.png");
    gst.background.loadFromFile("resources/statusBar.png");
    gst.frameWid = 5;
    gst.icon.loadFromFile("resources/Danger.png");
    gst.checkedRadBut.loadFromFile("resources/checked.png");
    gst.uncheckedRadBut.loadFromFile("resources/unchecked.png");
    //текстуры слайдера
    +gst.sliderBackTex.loadFromFile("resources/slider_back_line.png");
    +gst.sliderFrontTex.loadFromFile("resources/slider_front_line.png");
    +gst.sliderHandlerTex.loadFromFile("resources/slider_handler.png");


    static GUIStyle gst2;
    gst2.mainTex.loadFromFile("resources/statusBar.png");
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


    WindowTab main(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "main");
    std::shared_ptr<GUILayer> layer = main.CreateGUILayer(Vector2f(0, 0), Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));

    if (PANEL_DEBUG) {
        std::shared_ptr<ScrollingPanel> panel = main.CreateScrollPanel(Vector2f(800, 600), Vector2f(10, 150), Vector2f(200, 250), Color(50, 50, 50, 255));
        std::shared_ptr<ScrollBar> scrollbarHor2 = panel->CreateScrollBar(0, 0, 0, 0, &gst, Orientation::HORIZONTAL, 800);
        std::shared_ptr<ScrollBar> scrollbarVert2 = panel->CreateScrollBar(0, 0, 0, 0, &gst, Orientation::VERTICAL, 600);

        std::shared_ptr<MenuBar> menuBar2 = panel->CreateMenuBar(0, 0, SCREEN_WIDTH - 12, 50, "", &tst, &gst2,
            0, 200, Color::White);
        menuBar2->addButton("1", &buttonAction1);
        menuBar2->addButton("2", &buttonAction2);
        menuBar2->addButton("3", &buttonAction3);
        menuBar2->addButton("4", &buttonAction4);

        std::shared_ptr<GUILabel> label123 = panel->CreateLabel(60, 60, 100, 40, "LEFT", &tst, &gst);
        std::shared_ptr<TextField> textBox2 = panel->CreateTextField(250, 350, 100, 40, "textField", &tst, &gst);
    }
    //пример создания кнопки
	// текст подгружается из локали
    std::shared_ptr<GUIButton> button = layer->CreateButton(20, 60, 100,100, locale.GetElementName("button"), &tst, &gst, &buttonAction);
	std::shared_ptr<GUICheckButton> checkButton = layer->CreateCheckButton(300, 60, 100, 100, locale.GetElementName("check_button"), &tst, &gst, &buttonAction);
    
	std::shared_ptr<Table> table = layer->CreateTable(750, 300, 5, 6, &tst, &gst);

	// создание label
    Texture icon;
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
        std::shared_ptr<GUILabel> labelIcon1 = layer->CreateLabel(140, 10, 100, 50, "", &tst, &gst.icon, &gst);
        labelIcon1->SetHorizontalAlignment(Alignment::LEFT);
        std::shared_ptr<GUILabel> labelIcon2 = layer->CreateLabel(140, 65, 100, 50, "", &tst, &gst.icon, &gst);
        labelIcon2->SetHorizontalAlignment(Alignment::RIGHT);
        std::shared_ptr<GUILabel> labelIcon3 = layer->CreateLabel(140, 120, 100, 50, "", &tst, &gst.icon, &gst);
        labelIcon3->SetVerticalAlignment(Alignment::TOP);
        std::shared_ptr<GUILabel> labelIcon4 = layer->CreateLabel(140, 175, 100, 50, "", &tst, &gst.icon, &gst);
        labelIcon4->SetVerticalAlignment(Alignment::BOTTOM);
        std::shared_ptr<GUILabel> labelIcon5 = layer->CreateLabel(140, 230, 100, 50, "", &tst, &gst.icon, &gst);

        // просто иконка, которая НЕ меняется под размер бокса
        std::shared_ptr<GUILabel> labelIconN1 = layer->CreateLabel(140, 305, 100, 50, "", &tst, &gst.icon, &gst);
        labelIconN1->SetHorizontalAlignment(Alignment::LEFT);
        labelIconN1->SetDependsOnSize(false);
        std::shared_ptr<GUILabel> labelIconN2 = layer->CreateLabel(140, 360, 100, 50, "", &tst, &gst.icon, &gst);
        labelIconN2->SetHorizontalAlignment(Alignment::RIGHT);
        labelIconN2->SetDependsOnSize(false);
        std::shared_ptr<GUILabel> labelIconN3 = layer->CreateLabel(140, 415, 100, 50, "", &tst, &gst.icon, &gst);
        labelIconN3->SetVerticalAlignment(Alignment::TOP);
        labelIconN3->SetDependsOnSize(false);
        std::shared_ptr<GUILabel> labelIconN4 = layer->CreateLabel(140, 470, 100, 50, "", &tst, &gst.icon, &gst);
        labelIconN4->SetVerticalAlignment(Alignment::BOTTOM);
        labelIconN4->SetDependsOnSize(false);
        std::shared_ptr<GUILabel> labelIconN5 = layer->CreateLabel(140, 525, 100, 50, "", &tst, &gst.icon, &gst);
        labelIconN5->SetDependsOnSize(false);


        std::shared_ptr<GUILabel> labelTextIcon1 = layer->CreateLabel(400, 10, 100, 50, "Left", &tst, &gst.icon, &gst);
        labelTextIcon1->SetTextToIconAlignment(Alignment::LEFT);
        std::shared_ptr<GUILabel> labelTextIcon2 = layer->CreateLabel(400, 75, 100, 50, "RIGHT", &tst, &gst.icon, &gst);
        labelTextIcon2->SetTextToIconAlignment(Alignment::RIGHT);
        std::shared_ptr<GUILabel> labelTextIcon3 = layer->CreateLabel(400, 155, 100, 50, "TOP", &tst, &gst.icon, &gst);
        labelTextIcon3->SetTextToIconAlignment(Alignment::TOP);
        std::shared_ptr<GUILabel> labelTextIcon4 = layer->CreateLabel(400, 225, 100, 50, "BOTTOM", &tst, &gst.icon, &gst);
        labelTextIcon4->SetTextToIconAlignment(Alignment::BOTTOM);
        std::shared_ptr<GUILabel> labelTextIcon5 = layer->CreateLabel(400, 310, 100, 50, "CENTER", &tst, &gst.icon, &gst);
    }
	
  // Cоздание прогресс бара.
	// текст подгружается из локали
    std::shared_ptr<GUIProgressBar> progressBar = layer->CreateProgressBar(layer, SCREEN_WIDTH / 3 + 50, SCREEN_HEIGHT / 3, 200, 30, locale.GetDescription("progress_bar"), &tst, &gst,
        0, 200, Color::White, Color::Green);

    //создаем слайдер
    std::shared_ptr<GUISlider> slider = layer->CreateSlider(30, 450, 350, 20, 35, 38, &gst, 0, 100, 20, &onSliderMove);
	
    //Создание статус бара
    std::shared_ptr<GUIStatusBar>  statusBar = layer->CreateStatusBar(50, 5, 20, &sBarStyle, Location::UPSIDE);
    std::shared_ptr<GUIButton> box1 = layer->CreateButton(100, 0, 50, 50, "A", &tst, &gst, &buttonAction);
    std::shared_ptr<GUIButton> box2 = layer->CreateButton(0, 0, 1, 1, "B", &tst, &gst, &buttonAction);
    std::shared_ptr<GUIButton> box3 = layer->CreateButton(0, 0, 4, 1, "Test", &tst, &gst, &buttonAction);
	// текст подгружается из локали
	std::shared_ptr<TextField> textBox1 = layer->CreateTextField(250, 350, 120, 40, locale.GetInvite("print"), &tst, &gst);
	std::shared_ptr<GUILabel> label1 = layer->CreateLabel(5, 10, 100, 40, "READY...", &tst, &gst);
	label1->SetHorizontalAlignment(Alignment::LEFT);
    statusBar->AddElement(box1);
    statusBar->AddElement(box2);
    statusBar->AddElement(box3);
	statusBar->AddElement(textBox1);
	statusBar->AddElement(label1);
	statusBar->setLocation(Location::DOWNSIDE);

    // Создание МенюБара
    std::shared_ptr<MenuBar> menuBar;
    menuBar = layer->CreateMenuBar(0, 0, 1920, 50, "", &tst, &gst2, 0, 200, Color::White);
    // Добавление четырех кнопок на МенюБар
    menuBar->addButton("1", &buttonAction1);
    menuBar->addButton("2", &buttonAction2);
    menuBar->addButton("3", &buttonAction3);
    menuBar->addButton("4", &buttonAction4);

	// текст подгружается из локали
    std::shared_ptr<TextField> textBox = layer->CreateTextField(250, 350, 100, 40, locale.GetElementName("text_field"), &tst, &gst);

    std::shared_ptr<TextArea> textArea = layer->CreateTextArea(400, 240, 300, 200, &tst, &gst);

    if (RADIO_DEBUG)
    {
        //radioButton 
        std::vector<std::string> texts = { "Yes", "No", "NONO", "OFC","lol","kek", "","","","" };
        std::shared_ptr <RadioButton> radBut = layer->CreateRadButton(layer, 3, Vector2f(550, 100), Vector2f(30, 30), texts, &tst, &gst);
        std::shared_ptr <RadioButton> radBut2 = layer->CreateRadButton(layer, 6, 680, 100, 30, 30, texts, &tst, &gst);
    }
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

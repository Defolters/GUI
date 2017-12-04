#pragma once
#include <map>
#include "../GUI/GUILayer.h"
#include "../GUI/ScrollingPanel.h"

enum WindowTabState
{
	opened = 0,
	closed = 1
};
//просто примите его существование как данность пока что, пользутесь им так же как написан ов handler.cpp (можете прост ctrl-c)
class WindowTab : ObservableGUI
{
private:
	std::vector<std::shared_ptr<GUILayer>> GUILayers; //!< вектор??
	std::vector<std::shared_ptr<ScrollingPanel>> ScrollPanels;
	RenderWindow window; //!< окно
    

    /*!
    \brief Функция, которая изменяет размер компонентов, если окно растянули
    \param event_ Содержит в себе новый размер окна
    */
    void Resizing(const Event& event_);
public:
    WindowTabState state;
	//констуркутор, не парьтесь на этот счет, просто передавайте ему положение размеры
	//пока что вторые два аргумента передавайте (0,0) и (ширинаОкна, высотаОкна)
	//обрезание поля видимости все равно пока не работает :)
	std::shared_ptr<GUILayer> CreateGUILayer(Vector2f position_, Vector2f size_);
	std::shared_ptr<ScrollingPanel> CreateScrollPanel(Vector2f maxScrollPanelSize, Vector2f scrFieldPosition, Vector2f scrFieldSize, Color scrFieldColor, GUIStyle *gst);
	void Redraw();//единственная функция которую надо вызывать для отрисовки, не трогаем ее
	WindowTab(VideoMode mode, char* name);
	
	//TODO
	//НЕДОПИЛЕНА, НЕ ЮЗАТЬ ПОКА!
	void removeElement(IDrawable* observer) override;
	void notifyAll(const sf::Event& event) const override;
	~WindowTab();
};


#pragma once
#include <memory>
#include <vector>
#include <string>
#include "../General/Headers.h"
#include "GUIBox.h"

//по сути Layout, класс группирующий элементы интерфейса 
//как например отдельные зоны для кода, отладки и файлов в visual studio
class GUILayer : IDrawable
{
private:
	//вектора элементов на этом слое
	//в CreateElement() методах для своих элементов добавляйте share_ptr на свои элементы в этот вектор
	//пусть ваш элемент - elementType
	//тогда в CreateElementType()
	//в конце пишите 
	//elements.push_back(тут_shared_ptr_на ваш элемент);
	//return тут_shared_ptr_на ваш элемент;
	std::vector<std::shared_ptr<IDisplayable>> elements;
	//указатель на окно на котором находится это слой
	RenderWindow* window;
public:
	//констуркутор, не парьтесь на этот счет, просто передавайте ему окно и размеры
	//пока что вторые два аргумента передавайте (0,0) и (ширинаОкна, высотаОкна)
	//обрезание поля видимости все равно пока не работает :)
	GUILayer(RenderWindow &Swindow, Vector2f, Vector2f);
	void SetWindow(RenderWindow &Swindow);//ðàáîòàåò íî ïîêà íå ïîëüçóéòåñá è íå óñëîæíÿéòå ñåáå æèçíü

	//КЛЮЧЕВОЙ МОМЕНТ!
	//во избежание проблем с созданием указателей пользуемся shared_ptr<НазваниеЭлемент> (гуглите, на самом деле простоая вещь, синтаксиси похож на простые указатели)
	//для сохранения инкапсуляции:
	//СОЗДАВАЙТЕ ТАКИЕ МЕТОДЫ (хотя бы 1) ДЛЯ СВОИХ ЭЛЕМЕНТОВ
	//он должен создавать элемент, сохранять его в векторе (описаны выше) и возвращать shared_ptr на него (как это используется смотрите в handler.cpp)
	std::shared_ptr<GUIBox> CreateBox(float x, float y, float width, float height, std::string text, TextStyle *tstyle, GUIStyle *gstyle);
	std::shared_ptr<GUIBox> CreateBox(Vector2f position_, Vector2f size_, std::string text, TextStyle *tstyle, GUIStyle *gstyle);
	std::shared_ptr<GUIBox> CreateBox(Vector2f position_, float width, float height, std::string text, TextStyle *tstyle, GUIStyle *gstyle);
	std::shared_ptr<GUIBox> CreateBox(float x, float y, Vector2f size_, std::string text, TextStyle *tstyle, GUIStyle *gstyle);

	std::shared_ptr<GUIButton> CreateButton(float x, float y, float width, float height, std::string text, TextStyle *tstyle, GUIStyle *gstyle, void(*action)());
	std::shared_ptr<GUIButton> CreateButton(Vector2f position_, Vector2f size_, std::string text, TextStyle *tstyle, GUIStyle *gstyle, void(*action)());
	std::shared_ptr<GUIButton> CreateButton(Vector2f position_, float width, float height, std::string text, TextStyle *tstyle, GUIStyle *gstyle, void(*action)());
	std::shared_ptr<GUIButton> CreateButton(float x, float y, Vector2f size_, std::string text, TextStyle *tstyle, GUIStyle *gstyle, void(*action)());
	
	//это метод отрисоывавает все содержимое векторов с элементами, ТРОГАТЬ ЕГО НЕ НАДО
	void Draw() override;
};

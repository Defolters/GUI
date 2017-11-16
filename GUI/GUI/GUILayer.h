#pragma once
#include <memory>
#include <vector>
#include <string>
#include "GUIButton.h"

//по сути Layout, класс группирующий элементы интерфейса 
//как например отдельные зоны дл€ кода, отладки и файлов в visual studio
class GUILayer : IDrawable
{
private:
	//вектора элементов на этом слое
	//в CreateElement() методах дл€ своих элементов добавл€йте share_ptr на свои элементы в этот вектор
	//пусть ваш элемент - elementType
	//тогда в CreateElementType()
	//в конце пишите 
	//elements.push_back(тут_shared_ptr_на ваш элемент);
	//return тут_shared_ptr_на ваш элемент;
	std::vector<std::shared_ptr<IDisplayable>> elements;
	//указатель на окно на котором находитс€ это слой
	RenderWindow* window;
public:
	//констуркутор, не парьтесь на этот счет, просто передавайте ему окно и размеры
	//пока что вторые два аргумента передавайте (0,0) и (ширинаќкна, высотаќкна)
	//обрезание пол€ видимости все равно пока не работает :)
	GUILayer(RenderWindow &Swindow, Vector2f, Vector2f);
	void SetWindow(RenderWindow &Swindow);//работает но пока не пользуйтесб и не усложн€йте себе жизнь

	// Ћё„≈¬ќ… ћќћ≈Ќ“!
	//во избежание проблем с созданием указателей пользуемс€ shared_ptr<ЌазваниеЁлемент> (гуглите, на самом деле простоа€ вещь, синтаксиси похож на простые указатели)
	//дл€ сохранени€ инкапсул€ции:
	//—ќ«ƒј¬ј…“≈ “ј »≈ ћ≈“ќƒџ (хот€ бы 1) ƒЋя —¬ќ»’ ЁЋ≈ћ≈Ќ“ќ¬
	//он должен создавать элемент, сохран€ть его в векторе (описаны выше) и возвращать shared_ptr на него (как это используетс€ смотрите в handler.cpp)
	std::shared_ptr<GUIBox> CreateBox(float x, float y, float width, float height, std::string text, TextStyle *tstyle, GUIStyle *gstyle);
	std::shared_ptr<GUIBox> CreateBox(Vector2f position_, Vector2f size_, std::string text, TextStyle *tstyle, GUIStyle *gstyle);
	std::shared_ptr<GUIBox> CreateBox(Vector2f position_, float width, float height, std::string text, TextStyle *tstyle, GUIStyle *gstyle);
	std::shared_ptr<GUIBox> CreateBox(float x, float y, Vector2f size_, std::string text, TextStyle *tstyle, GUIStyle *gstyle);

	std::shared_ptr<GUIButton> CreateButton(float x, float y, float width, float height, std::string text, TextStyle *tstyle, GUIStyle *gstyle, void(*action)());
	std::shared_ptr<GUIButton> CreateButton(Vector2f position_, Vector2f size_, std::string text, TextStyle *tstyle, GUIStyle *gstyle, void(*action)());
	std::shared_ptr<GUIButton> CreateButton(Vector2f position_, float width, float height, std::string text, TextStyle *tstyle, GUIStyle *gstyle, void(*action)());
	std::shared_ptr<GUIButton> CreateButton(float x, float y, Vector2f size_, std::string text, TextStyle *tstyle, GUIStyle *gstyle, void(*action)());

	//это метод отрисоывавает все содержимое векторов с элементами, “–ќ√ј“№ ≈√ќ Ќ≈ Ќјƒќ
	void Draw() override;
};
#pragma once
#include "../General/Styles.hpp"
#include "../IDisplayable.h"

//Базовый класс для одиночных элементов
//от него наследуйте
//этот  класс, как и остальные НЕ МОДИФИЦИРУЙТЕ
//иначе мы все умрем
class GUIBox : public IDisplayable
{
private:
	//графический стиль и текстовый стиль описаны в styles.h
	GUIStyle *gstyle;
	TextStyle *tstyle;
	//обычный sfml спрайт
	Sprite sprite;
	//спрайты рамок (вроде пытался объяснить на паре зачем они нужны отдельно)
	//если не слышали зачем - поверьте на слово
	Sprite frames[4];
	//текст (кек)
	Text text;
	//пока что нужно, подумаю как избавиться, но не думаю что возможно
	friend class GUILayer;
protected:
	//стандартные конструкторы, как и в IDisplayable
	GUIBox(RenderWindow* renderWindow_, float x, float y, float width, float height, std::string text, TextStyle *tstyle, GUIStyle *gstyle);
	GUIBox(RenderWindow* renderWindow_, Vector2f position_, Vector2f size_, std::string text, TextStyle *tstyle, GUIStyle *gstyle);
	GUIBox(RenderWindow* renderWindow_, float x, float y, Vector2f size_, std::string text, TextStyle *tstyle, GUIStyle *gstyle);
	GUIBox(RenderWindow* renderWindow_, Vector2f position_, float width, float height, std::string text, TextStyle *tstyle, GUIStyle *gstyle);
public:
	//те же функции что и в IDisplayable
	//без надобности лучше их не перегружать, если перегружаете - вызывать функцию родительского класса в начале
	//если не поняли что написано выше - стучите в лс или гуглите, но это риал важно
	virtual void Draw() override;
	virtual void SetPosition(float x, float y) override;
	virtual void SetPosition(Vector2f position_) override;
	virtual void SetSize(float width, float height) override;
	virtual void SetSize(Vector2f size_) override;
	//сеттеры стилей и текста
	virtual void SetText(char *text);
	virtual void SetGStyle(GUIStyle *gstyle);
	virtual void SetTStyle(TextStyle *tstyle);
	//КЛЮЧЕВОЙ МОМЕНТ
	//если при изменении размера или положения элемента что-то должно мменяться - прегружайте в наследниках эту функцию
	//и тоже самое - если перегрузили, то в начале вызываем ее родительскую версию, потом свой код
	virtual void Recalc();
};

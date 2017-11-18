#pragma once
#include "../General/Styles.hpp"
#include "../IDisplayable.h"

//Ѕазовый класс дл€ одиночных элементов
//от него наследуйте
//этот  класс, как и остальные Ќ≈ ћќƒ»‘»÷»–”…“≈
//иначе мы все умрем
class GUIBox : public IDisplayable
{
private:
	//графический стиль и текстовый стиль описаны в styles.h
	GUIStyle *gstyle;
	TextStyle *tstyle;
	//обычный sfml спрайт
	Sprite sprite;
	//спрайты рамок (вроде пыталс€ объ€снить на паре зачем они нужны отдельно)
	//если не слышали зачем - поверьте на слово
	Sprite frames[4];
	//текст (кек)
	Text text;
	//пока что нужно, подумаю как избавитьс€, но не думаю что возможно
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
	//если не пон€ли что написано выше - стучите в лс или гуглите, но это риал важно
	virtual void Draw() override;
	virtual void SetPosition(float x, float y) override;
	virtual void SetPosition(Vector2f position_) override;
	virtual void SetSize(float width, float height) override;
	virtual void SetSize(Vector2f size_) override;
	//сеттеры стилей и текста
	virtual void SetText(char *text);
	virtual void SetGStyle(GUIStyle *gstyle);
	virtual void SetTStyle(TextStyle *tstyle);

	//ѕ–»ћ≈–  ј—“ќћЌќ√ќ ќЅ–јЅќ“„» ј —ќЅџ“»…!!!
	void handleEvent(const sf::Event& event) override
	{
	//—мотрит была ли нажата ЋёЅјя кнопка мыши
	if (event.type == sf::Event::MouseButtonPressed)
	{
	std::cout << "Mouse button pressed" << std::endl;
	//—мотрит, была ли это Ћ≈¬јя кнопка
	if (event.mouseButton.button == sf::Mouse::Left)
	{
	std::cout << "It was LEFT button" << std::endl;
	std::cout << "mouse x: " << event.mouseButton.x << std::endl;
	std::cout << "mouse y: " << event.mouseButton.y << std::endl;
	//» если нажали на этот элемент, выводит сообщение "Pressed element!"
	if (sprite.getGlobalBounds().contains(Vector2f(event.mouseButton.x, event.mouseButton.y)))
	std::cout << "Pressed element!" << std::endl;
	}
	std::cout << std::endl;
	}
	};

	// Ћё„≈¬ќ… ћќћ≈Ќ“
	//если при изменении размера или положени€ элемента что-то должно ммен€тьс€ - прегружайте в наследниках эту функцию
	//и тоже самое - если перегрузили, то в начале вызываем ее родительскую версию, потом свой код
	virtual void Recalc();
};

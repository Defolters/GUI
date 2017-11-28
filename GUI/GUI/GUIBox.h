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
	//пока что нужно, подумаю как избавиться, но не думаю что возможно
	friend class GUILayer;
protected:
	//графический стиль и текстовый стиль описаны в styles.h
	GUIStyle *gstyle;
	//обычный sfml спрайт
	Sprite sprite;
	//спрайты рамок (вроде пытался объяснить на паре зачем они нужны отдельно)
	//если не слышали зачем - поверьте на слово
	Sprite frames[4];
	//стандартные конструкторы, как и в IDisplayable
	GUIBox(RenderWindow* renderWindow_, float x, float y, float width, float height, GUIStyle *gstyle);
	GUIBox(RenderWindow* renderWindow_, Vector2f position_, Vector2f size_, GUIStyle *gstyle);
	GUIBox(RenderWindow* renderWindow_, float x, float y, Vector2f size_, GUIStyle *gstyle);
	GUIBox(RenderWindow* renderWindow_, Vector2f position_, float width, float height, GUIStyle *gstyle);
	virtual void Draw() override;
	virtual void Recalc();
public:
	//те же функции что и в IDisplayable
	//без надобности лучше их не перегружать, если перегружаете - вызывать функцию родительского класса в начале
	//если не поняли что написано выше - стучите в лс или гуглите, но это риал важно
	virtual void SetPosition(float x, float y) override;
	virtual void SetPosition(Vector2f position_) override;
	virtual void SetSize(float width, float height) override;
	virtual void SetSize(Vector2f size_) override;
	//сеттеры стилей и текста
	virtual void SetGStyle(GUIStyle *gstyle);

	//ПРИМЕР КАСТОМНОГО ОБРАБОТЧИКА СОБЫТИЙ!!!
	/*void handleEvent(const sf::Event& event) override
	{
	//Смотрит была ли нажата ЛЮБАЯ кнопка мыши
	if (event.type == sf::Event::MouseButtonPressed)
	{
	std::cout << "Mouse button pressed" << std::endl;
	//Смотрит, была ли это ЛЕВАЯ кнопка
	if (event.mouseButton.button == sf::Mouse::Left)
	{
	std::cout << "It was LEFT button" << std::endl;
	std::cout << "mouse x: " << event.mouseButton.x << std::endl;
	std::cout << "mouse y: " << event.mouseButton.y << std::endl;
	//И если нажали на этот элемент, выводит сообщение "Pressed element!"
	if (sprite.getGlobalBounds().contains(Vector2f(event.mouseButton.x, event.mouseButton.y)))
	std::cout << "Pressed element!" << std::endl;
	}
	std::cout << std::endl;
	}
	};*/

	//КЛЮЧЕВОЙ МОМЕНТ
	//если при изменении размера или положения элемента что-то должно мменяться - прегружайте в наследниках эту функцию
	//и тоже самое - если перегрузили, то в начале вызываем ее родительскую версию, потом свой код
};

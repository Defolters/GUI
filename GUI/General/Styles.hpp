#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
//Стиль для текста - шрифт, размер и цвет
struct TextStyle {
	Font font;
	int fontSize;
	Color color;
	char align;//единственное интересное место. Если == 'c', то текст равнятеся по центру, елси 'l' - по левому краю
};

//Стиль для текста - шрифт, размер и цвет
struct GUIStyle {
	Texture mainTex, pressTex, overTex;//пока что не робит, грузите все одной текстурой
	Texture frame;//рамки (в тестовом примере просто коричневые)
	Texture background;
	int frameWid;//ширина рамки в пикселях
};
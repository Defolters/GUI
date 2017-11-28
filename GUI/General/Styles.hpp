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
	Texture mainTex, pressTex, overTex;
	Texture frame;//рамки (в тестовом примере просто коричневые)
	int frameWid;//ширина рамки в пикселях
	Texture sliderBackTex, sliderFrontTex, sliderHandlerTex;//текстуры для слайдера
	Texture background;
};
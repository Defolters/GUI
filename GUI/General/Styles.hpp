#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
//Стиль для текста - шрифт, размер и цвет
struct TextStyle {
	Font font;
	int fontSize;
	Color color;
	char align;
};
//Стиль для текста - шрифт, размер и цвет
struct GUIStyle {
	Texture mainTex, pressTex, overTex;
	Texture frame;
	int frameWid;
};
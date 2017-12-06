#pragma once
#include "../../GUI/GUIBox.h"

class PasswordField : public GUIBox
{
private:
    friend class GUILayer;
    bool press = false; ///< Переменная для проверки нажатия во время печати
    std::string text; ///< Ввод строки в поле пароля
    std::string textIn; ///< Исходная строка, которая задается при вызове
    Text txt;  ///< Вывод строки поля пароля          
    std::string textButt; ///< Ввод строки в поле кнопки
    Text txtButt;  ///< Вывод строки поля пароля        
    RectangleShape field; ///< Область для поля пароля
    RectangleShape fieldButt; ///< Область для поля кнопки
    std::vector<char> vect; ///< Вектор для набранных символов
    std::string correct; ///< Правильный пароль, задается при вызове
    bool buttPass = false; ///< Проверка на то, нажата ли ЛКМ в поле кнопки
    bool fieldPass = false; ///< Проверка на то, нажата ли ЛКМ в поле пароля

protected:
    /// Конструктор
    PasswordField(RenderWindow* renderWindow_, float x, float y, float width, float height, std::string text, TextStyle *tstyle, GUIStyle *gstyle, std::string correct);
    bool inField; ///< Координаты мыши в поле пароля, если true 
    bool inFieldButt; ///< Координаты мыши в поле кнопки, если true

public:
    virtual void Draw() override; ///< Переопределение функции Draw()
    virtual void Recalc() override; ///< Переопредение функции Recalc()
    Text Display();  ///< Вывод текста в поле пароля
    Text DisplayButt(); ///< Вывод текста в поле кнопки
    void handleEvent(const sf::Event& event) override; ///< Обработчик событий. Нажатие и печать текста.
    bool Inside(Vector2i); ///< Проверка вхождения мыши в поле пароля
    bool InsideButt(Vector2i); ///< Проверка вхождения мыши в поле кнопки
};
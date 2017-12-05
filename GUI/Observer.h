#ifndef OBSERVER_H
#define OBSERVER_H
#include <SFML/Graphics.hpp>
/*!
\brief Абстрактный класс слушателю событий

*/
class Observer abstract
{
public:
    //! базовая функция обработки событий
    virtual void handleEvent(const sf::Event& event) = 0;
};

#endif // OBSERVER_H

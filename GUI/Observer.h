#ifndef OBSERVER_H
#define OBSERVER_H
#include <SFML/Graphics.hpp>

class Observer abstract
{
public:
    virtual void handleEvent(const sf::Event& event) = 0;
};

#endif // OBSERVER_H

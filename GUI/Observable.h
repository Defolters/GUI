#ifndef OBSERVABLE_H
#define OBSERVABLE_H
#include "Observer.h"
#include "IDrawable.h"

class ObservableGUI abstract
{
public:
    virtual void removeElement(IDrawable* observer) = 0;
    virtual void notifyAll(const sf::Event& event) const = 0;
};

#endif // OBSERVABLE_H

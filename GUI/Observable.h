#ifndef OBSERVABLE_H
#define OBSERVABLE_H
#include "Observer.h"
#include "IDrawable.h"
/*!
\brief Абстрактный класс слушателю событий

Абстрактный класс рассыльщика событий
*/
class ObservableGUI abstract
{
public:
    //! удалить слушателя
    virtual void removeElement(IDrawable* observer) = 0;
    //! объявить событие всем слушателям
    virtual void notifyAll(const sf::Event& event) const = 0;
};

#endif // OBSERVABLE_H

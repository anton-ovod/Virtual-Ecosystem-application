

#include "Organizm.h"

Organizm::Organizm(unsigned short lengthoflife,
                   unsigned short limitofmeals,
                   unsigned short costofchild):
LimitOfmeals(limitofmeals),
CostOfChild(costofchild),
CountOfLife(lengthoflife),
CountOfMeals(0)
{}

bool Organizm::meal() {
    if(hungry())
    {
        CountOfMeals++;
        return true;
    } else return false;
}

bool Organizm::child() {
    if(budding())
    {
        CountOfMeals -= CostOfChild;
        return true;
    } else return false;
}

void Organizm::StepOfSimulation() {
    if(alive()) CountOfLife--;
}

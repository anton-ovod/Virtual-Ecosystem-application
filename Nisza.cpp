//
// Created by USER on 17.04.2023.
//

#include "Nisza.h"

Nisza::Nisza() : lokator(nullptr) {}

Nisza::Nisza(Nisza &innanisza) {
    if (innanisza.zajeta())
    {
        lokator = innanisza.lokator;
        innanisza.lokator = nullptr;
    }
    else
    {
        lokator = nullptr;
    }
}

Nisza::~Nisza() {
    if (lokator != nullptr)
    {
        delete lokator;
    }
}

Nisza &Nisza::operator=(Nisza &innanisza) {
    Mieszkaniec * tmp = lokator;
    lokator = innanisza.lokator;
    innanisza.lokator = tmp;
    return *this;
}

void Nisza::przyjmijLokatora(Mieszkaniec *lokatorBezdomny) {
    if(!zajeta())
    {
        lokator = lokatorBezdomny;
        lokatorBezdomny = nullptr;
    }
}

Mieszkaniec *Nisza::oddajLokatora() {
    Mieszkaniec * tmp = nullptr;

    if(zajeta()){
        tmp = lokator;
        lokator = nullptr;
    }
    return tmp;
}

bool Nisza::lokatorZywy() const {
    if(zajeta())
    {
        TypeOfCell r = lokator ->kimJestes();
        return r == GLON || r == GRZYB || r == BAKTERIA;
    }
    else {
        return false;
    }
}

char Nisza::jakiSymbol() const {
    if(!zajeta()) return SettingsOfSimulation::getSettings().symbolEmptySpace;
    else return lokator->jakiSymbol();
}
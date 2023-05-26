#ifndef C___LABS_MIESZKANIEC_H
#define C___LABS_MIESZKANIEC_H
#include "settings.h"

class Sasiedztwo;

class ZamiarMieszkanca{
public:
    const ActionOfMember akcja;
    const Location gdzie;

    ZamiarMieszkanca(ActionOfMember _akcja = NIC, Location _gdzie = NIGDZIE): akcja(_akcja), gdzie(_gdzie){}
};



class Mieszkaniec{
protected:
    char symbol;
public:
    Mieszkaniec(char symbol = SettingsOfSimulation::getSettings().symbolNotDefined);

    Mieszkaniec(const Mieszkaniec &mieszkaniec);

    virtual char jakiSymbol() const final;

    virtual ~Mieszkaniec();

    virtual TypeOfCell kimJestes() = 0;

    virtual ZamiarMieszkanca wybierzAkcje(Sasiedztwo sasiedztwo) = 0;

    virtual Mieszkaniec *dajPotomka() = 0;

    virtual void przyjmijZdobycz(Mieszkaniec *mieszkaniec) = 0;
};



#endif

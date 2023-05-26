//
// Created by USER on 17.04.2023.
//

#ifndef C___LABS_OSOBNIKI_H
#define C___LABS_OSOBNIKI_H

#include "Organizm.h"
#include "Mieszkaniec.h"



class Glon: protected Organizm, public Mieszkaniec{
public:
    Glon();
    virtual TypeOfCell kimJestes() final;
    virtual ZamiarMieszkanca wybierzAkcje(Sasiedztwo sasiedztwo);
    virtual Mieszkaniec *dajPotomka();
    virtual void przyjmijZdobycz(Mieszkaniec *mieszkaniec);

};


class Grzyb: protected Organizm, public Mieszkaniec{
public:
    Grzyb();
    virtual TypeOfCell kimJestes() final;

    virtual ZamiarMieszkanca wybierzAkcje(Sasiedztwo sasiedztwo);
    virtual Mieszkaniec *dajPotomka();
    virtual void przyjmijZdobycz(Mieszkaniec *mieszkaniec);
};

class Bakteria: protected Organizm, public Mieszkaniec{
public:
    Bakteria();
    virtual TypeOfCell kimJestes() final;
    virtual ZamiarMieszkanca wybierzAkcje(Sasiedztwo sasiedztwo);
    virtual Mieszkaniec *dajPotomka();
    virtual void przyjmijZdobycz(Mieszkaniec *mieszkaniec);
};


#endif //C___LABS_OSOBNIKI_H

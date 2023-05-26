//
// Created by USER on 17.04.2023.
//

#ifndef C___LABS_NISZA_H
#define C___LABS_NISZA_H

#include "Mieszkaniec.h"
#include "sasiedztwo.h"
#include "Srodowisko.h"

class Nisza {
private:
    Mieszkaniec *lokator;
public:
    Nisza();
    Nisza(Nisza & innanisza);
    ~Nisza();

    Nisza& operator=(Nisza & innanisza);

    void przyjmijLokatora(Mieszkaniec *lokatorBezdomny);

    Mieszkaniec * oddajLokatora();

    bool zajeta() const {return lokator != nullptr;}

    friend void Srodowisko::wykonajAkcje(unsigned int wiersz, unsigned int kolumna);

    TypeOfCell ktoTuMieszka()
    {
        return zajeta() ? lokator->kimJestes() : PUSTKA;
    }

    bool lokatorZywy() const;

    char jakiSymbol() const;

    ZamiarMieszkanca aktywujLokatora(Sasiedztwo sasiedztwo)
    {
        return lokator->wybierzAkcje(sasiedztwo);
    }

private:
    Mieszkaniec * wypuscPotomka()
    {
        return lokator->dajPotomka();
    }
    void przyjmijZdobycz(Mieszkaniec *ofiara)
    {
        lokator->przyjmijZdobycz(ofiara);
    }

};


#endif //C___LABS_NISZA_H

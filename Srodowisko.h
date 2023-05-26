//
// Created by USER on 22.05.2023.
//

#ifndef C___LABS_SRODOWISKO_H
#define C___LABS_SRODOWISKO_H
#include <string>
#include "settings.h"

class Nisza;
class Mieszkaniec;
class Sasiedztwo;

class Srodowisko {
public:
    const unsigned int wiersze, kolumny;
    const unsigned long liczbaNisz;
private:
    Nisza **nisza;
public:
    Srodowisko(unsigned int _wiersze, unsigned int _kolumny);
    ~Srodowisko();

    void lokuj(Mieszkaniec * mieszkaniec, unsigned int wiersz, unsigned int kolumna);

    Sasiedztwo ustalSasiedztwo(unsigned int wiersz, unsigned int kolumna) const;

    unsigned long liczba(TypeOfCell rodzaj) const;

    bool martwy();

    void wykonajSkok(unsigned int wiersz, unsigned int kolumna);

    void wykonajAkcje(unsigned int wiersz, unsigned int kolumna);

    void wykonajKrokSymulacji();

    std::string doTekstu() const;
    void operator++(int) {wykonajKrokSymulacji();}
    bool operator!() {return !martwy();}

};
std::ostream& operator<<(std::ostream& strumien, const Srodowisko& srodowisko);



#endif //C___LABS_SRODOWISKO_H

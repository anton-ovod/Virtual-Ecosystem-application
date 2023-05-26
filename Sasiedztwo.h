#ifndef C___LABS_SASIEDZTWO_H
#define C___LABS_SASIEDZTWO_H

#include "settings.h"

class Sasiedztwo{
private:
    TypeOfCell sasiad[3][3];
    TypeOfCell * elementWewnetrzny(Location location);
    static Location losujPolozenie();

public:
    Sasiedztwo(TypeOfCell type = NIEZNANE);

    void okreslSasida(Location location, TypeOfCell type);

    TypeOfCell ktoJestSasiadiem(Location location);

    unsigned short ile(TypeOfCell type) const;

    Location losujSasiada(TypeOfCell type);

    static void zmienIndeksyWgPolozenia(Location location, long & wiersz, long & kolumna);

    static void zmienIndeksyWgPolozenia(Location location, unsigned int & wiersz,  unsigned int & kolumna);



};


#endif

/*
string nazwaRodzaju(TypeOfCell rodzaj) {
    switch(rodzaj)
    {
        case GLON:
            return "GLON";
        case GRZYB:
            return "GRZYB";
        case BAKTERIA:
            return "BAKTERIA";
        case PUSTKA:
            return "PUSTKA";
        case SCIANA:
            return "SCIANA";
        case TRUP:
            return "TRUP";
        case NIEZNANE:
            return "NIEZNANE";

    }
}
int main() {
    Sasiedztwo sasiedztwo;

    sasiedztwo.okreslSasida(P, GLON);
    sasiedztwo.okreslSasida(PG, GRZYB);
    sasiedztwo.okreslSasida(G, GRZYB);
    sasiedztwo.okreslSasida(LG, GLON);
    sasiedztwo.okreslSasida(L, BAKTERIA);
    sasiedztwo.okreslSasida(LD, BAKTERIA);
    sasiedztwo.okreslSasida(D, GLON);
    sasiedztwo.okreslSasida(PD, PUSTKA);

    cout << "Przeglad sasiedztwa: " << endl;

    for(int i = 0; i < 8; i++)
    {
        Location p = static_cast<Location>(i);
        TypeOfCell r = sasiedztwo.ktoJestSasiadiem(p);

        cout<< "polozenie: " << p << " rodzaj: " << nazwaRodzaju(r) << endl;
    }

    cout << endl << "Policazenie sasiadow: "
         << "okreslonego rodzaju: " << endl
         << "glony: " << sasiedztwo.ile(GLON) << endl
         << "grzyby: " << sasiedztwo.ile(GRZYB) << endl
         << "trupy: " << sasiedztwo.ile(TRUP) << endl;

    cout << endl << "Losowanie sasiada: " << endl
         << "glon -> " << sasiedztwo.losujSasiada(GLON) << endl
         << "pustka -> " << sasiedztwo.losujSasiada(PUSTKA) << endl
         << "trup -> " << sasiedztwo.losujSasiada(TRUP) << endl;

    long wiersz, kolumna;
    cout << endl
         << "Zmiana indeksow [5][7]"
         << "wg polozenia: " << endl;

    for(int i = 0; i<8; i++)
    {
        Location p = static_cast<Location>(i);
        wiersz = 5;
        kolumna = 7;
        Sasiedztwo::zmienIndeksyWgPolozenia(p, wiersz, kolumna);
        cout << "polozenie: " << p << " wiersz: " << wiersz << " kolumna: " << kolumna << endl;
    }
    cout << endl;
    system("pause");
}*/

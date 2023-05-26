#include "Sasiedztwo.h"
#include "RandomGenerator.h"
TypeOfCell * Sasiedztwo::elementWewnetrzny(Location location) {
    switch(location)
    {
        case P:
            return &sasiad[1][2];
        case PG:
            return &sasiad[0][2];
        case G:
            return &sasiad[0][1];
        case LG:
            return &sasiad[0][0];
        case L:
            return &sasiad[1][0];
        case LD:
            return &sasiad[2][0];
        case D:
            return &sasiad[2][1];
        case PD:
            return &sasiad[2][2];
        default:
            return nullptr;
    }
}

Location Sasiedztwo::losujPolozenie() {
    unsigned short min = 0, max = 8;
    return static_cast<Location>(RandomGenerator::RandomBetween(min, max));
}

Sasiedztwo::Sasiedztwo(TypeOfCell type) {
    for(int i: {0,1,2})
        for(int j: {0,1,2})
            sasiad[i][j] = type;
    sasiad[1][1] = NIEZNANE;
}

void Sasiedztwo::okreslSasida(Location location, TypeOfCell type) {
    if (location != NIGDZIE)
        *elementWewnetrzny(location) = type;
}

TypeOfCell Sasiedztwo::ktoJestSasiadiem(Location location) {
    if(location != NIGDZIE)
        return *elementWewnetrzny(location);
    else
        return NIEZNANE;
}

unsigned short Sasiedztwo::ile(TypeOfCell type) const {
    unsigned short counter = 0;
    for(int  i: {0,1,2})
        for(int  j: {0,1,2}) {
            if (i == 1 && j == 1) continue;
            if (sasiad[i][j] == type) counter++;
        }
    return counter;
}

Location Sasiedztwo::losujSasiada(TypeOfCell type) {
    if(ile(type) == 0)
        return NIGDZIE;
    else
    {
        Location location = Sasiedztwo::losujPolozenie();
        while(ktoJestSasiadiem(location) != type)
            location = Sasiedztwo::losujPolozenie();
        return location;
    }
}
void Sasiedztwo::zmienIndeksyWgPolozenia(Location location, long & wiersz, long & kolumna) {
    if(location == PG || location == P || location == PD)
        kolumna++;
    else if(location == LG || location == L || location == LD)
        kolumna--;
    if(location == LG || location == G || location == PG)
        wiersz--;
    else if(location == LD || location == D || location == PD)
        wiersz++;
}

void Sasiedztwo::zmienIndeksyWgPolozenia(Location location, unsigned int &wiersz, unsigned int &kolumna) {
    long w = static_cast<long>(wiersz);
    long k = static_cast<long>(kolumna);

    zmienIndeksyWgPolozenia(location, w, k);

    wiersz = static_cast<unsigned int>(w);
    kolumna = static_cast<unsigned int>(k);
}

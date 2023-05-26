//
// Created by USER on 17.04.2023.
//

#include "Osobniki.h"
#include "settings.h"
#include "RandomGenerator.h"
#include "Sasiedztwo.h"

static const SettingsOfSimulation & UST = SettingsOfSimulation::getSettings();


Glon::Glon(): Organizm(RandomGenerator::RandomBetween(UST.glonMinLife, UST.glonMaxLife),
                       UST.glonLimitOfMeals, UST.glonCostOfChild),
                       Mieszkaniec(UST.symbolGlon){}
Grzyb::Grzyb(): Organizm(RandomGenerator::RandomBetween(UST.grzybMinLife, UST.grzybMaxLife),
                         UST.grzybLimitOfMeals, UST.grzybCostOfChild),
                         Mieszkaniec(UST.symbolGrzyb){}
Bakteria::Bakteria(): Organizm(RandomGenerator::RandomBetween(UST.bakteriaMinLife, UST.bakteriaMaxLife),
                               UST.bakteriaLimitOfMeals, UST.bakteriaCostOfChild),
                               Mieszkaniec(UST.symbolBakteria){}
TypeOfCell Glon::kimJestes(){
    return alive() ? GLON : TRUP;
}

TypeOfCell Grzyb::kimJestes(){
    return alive() ? GRZYB : TRUP;
}

TypeOfCell Bakteria::kimJestes(){
    return alive() ? BAKTERIA : TRUP;
}

Mieszkaniec * Glon::dajPotomka() {
    Mieszkaniec * m = nullptr;
    if(child()){ m = new Glon(); }
    return m;
}

Mieszkaniec * Grzyb::dajPotomka() {
    Mieszkaniec * m = nullptr;
    if(child()){ m = new Grzyb(); }
    return m;
}

Mieszkaniec * Bakteria::dajPotomka() {
    Mieszkaniec * m = nullptr;
    if(child()){ m = new Bakteria(); }
    return m;
}

void Glon::przyjmijZdobycz(Mieszkaniec *mieszkaniec){
    if(mieszkaniec != nullptr) delete mieszkaniec;
}

void Grzyb::przyjmijZdobycz(Mieszkaniec *mieszkaniec){
    if(mieszkaniec != nullptr) {
        if (mieszkaniec->kimJestes() == TRUP) meal();
        delete mieszkaniec;
    }
}

void Bakteria::przyjmijZdobycz(Mieszkaniec *mieszkaniec) {
    if(mieszkaniec != nullptr){
        TypeOfCell r = mieszkaniec->kimJestes();
        if(r == GLON || r == GRZYB) meal();
        delete mieszkaniec;
    }
}

ZamiarMieszkanca Glon::wybierzAkcje(Sasiedztwo sasiedztwo) {
    StepOfSimulation();
     if(alive() && budding() && sasiedztwo.ile(PUSTKA) > 0){
         return ZamiarMieszkanca(POTOMEK, sasiedztwo.losujSasiada(PUSTKA));
     }

     if(alive() && hungry()) meal();
     if(!alive() && symbol != UST.symbolTrup){
        symbol = UST.symbolTrup;
     }
    return ZamiarMieszkanca();

}

ZamiarMieszkanca Grzyb::wybierzAkcje(Sasiedztwo sasiedztwo) {
    StepOfSimulation();
    if(alive() && budding() && sasiedztwo.ile(PUSTKA) > 0){
        return ZamiarMieszkanca(POTOMEK, sasiedztwo.losujSasiada(PUSTKA));
    }

    if(alive() && hungry() && sasiedztwo.ile(TRUP) > 0){
        return ZamiarMieszkanca(ROZKLAD, sasiedztwo.losujSasiada(TRUP));
    }
    if(!alive() && symbol != UST.symbolTrup){
        symbol = UST.symbolTrup;
    }
    return ZamiarMieszkanca();

}

ZamiarMieszkanca Bakteria::wybierzAkcje(Sasiedztwo sasiedztwo) {
    StepOfSimulation();
    if(alive() && budding() && sasiedztwo.ile(PUSTKA) > 0){
        return ZamiarMieszkanca(POTOMEK, sasiedztwo.losujSasiada(PUSTKA));
    }

    if(alive() && hungry() && sasiedztwo.ile(GLON) > 0)
    {
        return ZamiarMieszkanca(POLOWANIE, sasiedztwo.losujSasiada(GLON));
    }
    if(alive() && hungry() && sasiedztwo.ile(BAKTERIA) > 0)
    {
        return ZamiarMieszkanca(POLOWANIE, sasiedztwo.losujSasiada(BAKTERIA));
    }
    if(!alive() && symbol != UST.symbolTrup){
        symbol = UST.symbolTrup;
    }
    return ZamiarMieszkanca();

}


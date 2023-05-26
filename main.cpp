#include <iostream>

#include "nisza.h"
#include "osobniki.h"
#include "sasiedztwo.h"


using namespace std;



int main()
{
   Srodowisko ekoSystem(8, 12);

   ekoSystem.lokuj(new Glon, 0, 10);
   ekoSystem.lokuj(new Glon, 1, 10);
   ekoSystem.lokuj(new Glon, 1, 13);
   ekoSystem.lokuj(new Glon, 3, 10);
   ekoSystem.lokuj(new Grzyb, 1, 11);
   ekoSystem.lokuj(new Grzyb, 0, 0);
   ekoSystem.lokuj(new Bakteria, 3, 3);
   ekoSystem.lokuj(new Bakteria, 2, 6);


   unsigned long i = 0;
   while(i < 200 && !ekoSystem)
   {
       system("CLS");
       std::cout << "Krok symulacji: " << i<< std::endl
       << std::endl << ekoSystem << std::endl;

       cin.ignore(1);
       ekoSystem++;
       i++;
   }
   system("CLS");
   std::cout << "Krok symulacji: " << i<< std::endl << std::endl << ekoSystem << std::endl;
   system("pause");

}

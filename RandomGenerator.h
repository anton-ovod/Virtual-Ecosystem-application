#ifndef C___LABS_RANDOMGENERATOR_H
#define C___LABS_RANDOMGENERATOR_H

#include <random>



class Indeks2D
{
public:
    unsigned int wiersz, kolumna;
    Indeks2D(unsigned int _w = 0, unsigned int _k = 0)
    : wiersz(_w), kolumna(_k) {}
};
typedef std::vector<Indeks2D> WektorIndeksow2D;
class RandomGenerator {
private:
    static std::random_device device;
    RandomGenerator(){}
public:
    static unsigned short RandomBetween(unsigned short min, unsigned short max);
    static WektorIndeksow2D indeksyLosowe(unsigned int wiersze, unsigned int kolumny);
    static long RandomBetween(long min, long max);
    static int randomfromzero(int max);
};

typedef RandomGenerator GEN;


#endif
/*
int main()
{
    cout << "Random integer numbers: " << endl;
    cout << "from 0 to 5: ";
    for(int i = 0; i < 10; i++)
    {
        cout << GEN::randomfromzero(5) << " ";
    }
    cout << endl << "from 0 to 3: ";
    for(int i = 0; i < 10; i++)
        cout << GEN::randomfromzero(3) << " ";
    cout << endl << "form 0 to 20: ";
    for(int i = 0; i < 10; i++)
        cout << GEN::randomfromzero(20) << " ";
    cout << endl << endl;

    cout << "Random long numbers: " << endl;
    cout << "from -2 to 2: ";
    for(int i = 0; i < 10; i++)
        cout << GEN::RandomBetween(-2L, 2L) << " ";
    cout << endl << endl;

    cout << "Random unsigned short numbers: "<< endl;
    cout << "from 2 to 6: ";
    unsigned short min = 2, max = 6;
    for(int i = 0; i < 10; i++)
        cout << GEN::RandomBetween(min, max) << " ";
    cout << endl << endl;
    system("pause");

}*/

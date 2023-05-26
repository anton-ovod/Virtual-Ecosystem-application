//
// Created by USER on 20.03.2023.
//

#include "RandomGenerator.h"
#include <algorithm>

std::random_device RandomGenerator::device;


unsigned short RandomGenerator::RandomBetween(unsigned short min, unsigned short max) {
    if (min > max)
    {
        unsigned short t = min;
        min = max;
        max = t;
    }
    std::uniform_int_distribution<unsigned short> dist(min, max);

    return dist(RandomGenerator::device);
}


long RandomGenerator::RandomBetween(long min, long max) {
    if(min > max)
    {
        long t = min;
        min = max;
        max = t;
    }

    std::uniform_int_distribution<long> dist(min, max);
    return dist(RandomGenerator::device);
}

int RandomGenerator::randomfromzero(int max) {
    std::uniform_int_distribution<int> dist(0, max);
    return dist(RandomGenerator::device);
}

WektorIndeksow2D RandomGenerator::indeksyLosowe(unsigned int wiersze, unsigned int kolumny)
{
    WektorIndeksow2D indeksy;

    for(unsigned int w = 0; w < wiersze; w++)
    {
        for(unsigned int k = 0; k < kolumny; k++)
        {
            indeksy.push_back(Indeks2D(w, k));
        }
    }

    std::random_shuffle(indeksy.begin(), indeksy.end(), RandomGenerator::randomfromzero);
    return indeksy;
}

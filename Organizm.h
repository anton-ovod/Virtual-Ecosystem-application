#ifndef C___LABS_ORGANIZM_H
#define C___LABS_ORGANIZM_H


class Organizm {
public:
    const unsigned short LimitOfmeals;
    const unsigned short CostOfChild;
private:
    unsigned short CountOfLife;
    unsigned short CountOfMeals;
public:
    Organizm(unsigned short lengthoflife, unsigned short limitofmeals, unsigned short costofchild);
    bool alive() const
    {
        return CountOfLife > 0;
    }

    bool hungry() const
    {
        return alive() && CountOfMeals < LimitOfmeals;
    }

    bool budding() const
    {
        return alive() && CountOfMeals > CostOfChild;
    }
    unsigned short StateOfLifeCount() const
    {
        return CountOfLife;
    }
    unsigned short StateOfMealsCount() const
    {
        return CountOfMeals;
    }

    bool meal();
    bool child();

    void StepOfSimulation();

};


#endif

/*
void PrintOrganizm(const Organizm & o);
int main()
{
    Organizm organizm1(8, 3, 2);
    Organizm organizm2 = organizm1;
    Organizm organizm3(organizm1);

    cout << "The result of object creation: " << endl << endl;
    cout << "Organism 1" << endl;
    PrintOrganizm(organizm1);
    cout << "Organism 2" << endl;
    PrintOrganizm(organizm2);
    cout << "Organism 3" << endl;
    PrintOrganizm(organizm3);

    organizm1.meal();
    organizm1.meal();
    organizm2.meal();
    organizm3.StepOfSimulation();

    cout << "The result of object properties: " << endl << endl;
    cout << "Organism 1: " << endl;
    PrintOrganizm(organizm1);
    cout << "Organism 2: " << endl;
    PrintOrganizm(organizm2);
    cout << "Organism 3: " << endl;
    PrintOrganizm(organizm3);

    Organizm organizm4(8,3,2);

    cout << "The result of object creation: " << endl << endl;
    cout << "State at the beginning: " << endl;
    PrintOrganizm(organizm4);

    for(int i = 1; i < 11; i++)
    {
        organizm4.StepOfSimulation();

        if(organizm4.budding())
        {
            organizm4.child();
            cout << "---> Child" << endl;
        } else organizm4.meal();

        cout << "After step of simulation: " << i << endl;
        PrintOrganizm(organizm4);
    }

    system("pause");
}

void PrintOrganizm(const Organizm & o)
{
    cout << "Count Of Life: "
         << o.StateOfLifeCount()
         << " Count Of Meals: "
         << o.StateOfMealsCount() << endl
         << "Limit Of Meals: "
         << o.LimitOfmeals
         << " Cost of Child "
         << o.CostOfChild << endl
         << "Hungry: " << o.hungry()
         << " Budding: " << o.budding() << endl << endl;
}*/

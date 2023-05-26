#ifndef C___LABS_SETTINGS_H
#define C___LABS_SETTINGS_H

enum TypeOfCell {GLON, GRZYB, BAKTERIA, PUSTKA, SCIANA, TRUP, NIEZNANE};
enum ActionOfMember {POTOMEK, POLOWANIE, ROZKLAD, NIC};
enum Location {P = 0, PG = 1, G = 2, LG = 3, L = 4, LD = 5, D = 6, PD = 7, NIGDZIE = 8};

class SettingsOfSimulation
{
public:
    const char
        symbolGlon = '*',
        symbolGrzyb = '#',
        symbolBakteria = '@',
        symbolTrup = '+',
        symbolNotDefined = '?',
        symbolEmptySpace = '_',
        symbolSep = ' ';

    unsigned short
        glonMinLife = 5,
        glonMaxLife = 10,
        glonCostOfChild = 2,
        glonLimitOfMeals = 6,

        grzybMinLife = 40,
        grzybMaxLife = 60,
        grzybCostOfChild = 3,
        grzybLimitOfMeals = 30,

        bakteriaMinLife = 25,
        bakteriaMaxLife  = 40,
        bakteriaCostOfChild = 3,
        bakteriaLimitOfMeals = 10;

    bool CorrectSymbolOfSpace(char symbol) const
    {
        return symbol ==symbolGlon || symbol == symbolGrzyb ||
                symbol == symbolBakteria || symbol == symbolTrup ||
                symbol == symbolEmptySpace;
    }

    bool CorrectSep(char symbol) const
    {
        return symbol == symbolSep;

    }

private:
    SettingsOfSimulation(){}
    SettingsOfSimulation(SettingsOfSimulation&);
public:
    static SettingsOfSimulation & getSettings()
    {
        static SettingsOfSimulation settings;
        return settings;
    }
};

#endif


/*void printSettings(SettingsOfSimulation & set)
{
    cout << "Sumbol glon: " << set.symbolGlon
         << " minlife: " << set.glonMinLife
         << " maxlife: " << set.glonMaxLife << endl;
}
int main()
{
    SettingsOfSimulation & SET1 = SettingsOfSimulation::getSettings();
    SettingsOfSimulation & SET2 = SettingsOfSimulation::getSettings();
    SettingsOfSimulation & SET3 = SettingsOfSimulation::getSettings();

    cout << "Getting settings 3x" << endl;
    cout << "SET1 : "; printSettings(SET1);
    cout << "SET2 : "; printSettings(SET2);
    cout << "SET3 : "; printSettings(SET3);


    cout << endl << "Changing the value only first one: " << endl;
    SET2.glonMaxLife = 100;
    cout << "SET1 : "; printSettings(SET1);
    cout << "SET2 : "; printSettings(SET2);
    cout << "SET3 : "; printSettings(SET3);
    system("pause");

}*/

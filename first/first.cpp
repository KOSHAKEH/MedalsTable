#include <iostream>
#include <string>
#include "MedalsTable.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    MedalsTable table;

    table.addMedal("Россия", 5, 4, 3);
    table.addMedal("США", 7, 6, 5);
    table.addMedal("Китай", 4, 5, 6);
    table.addMedal("Польша", 0, 4, 1);
    table.addMedal("Франция", 3, 4, 5);


    cout << table << endl;

    MedalRow maxMedal = table("Польша");

    switch (maxMedal) {
    case MedalRow::GOLD:
        cout << "Максимальная медаль для Польши: Золото\n";
        break;
    case MedalRow::SILVER:
        cout << "Максимальная медаль для Польши: Серебро\n";
        break;
    case MedalRow::BRONZE:
        cout << "Максимальная медаль для Польши: Бронза\n";
        break;
    }

    maxMedal = table("Россия");
    cout << "Максимальная медаль для России: " << (maxMedal == MedalRow::GOLD ? "Золото" : maxMedal == MedalRow::SILVER ? "Серебро" : "Бронза") << "\n";
    return 0;
}
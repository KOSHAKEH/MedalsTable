#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

enum class MedalRow {
    GOLD,
    SILVER,
    BRONZE
};

struct Medal {
    string country;
    int gold;
    int silver;
    int bronze;
};

class MedalsTable
{
private:
    vector<Medal> medals;

public:
    MedalsTable() = default;

    MedalsTable(size_t size) : medals(size) {}

    MedalsTable(const MedalsTable& other) : medals(other.medals) {}
    MedalsTable& operator=(const MedalsTable& other) {
        if (this != &other) {
            medals = other.medals;
        }
        return *this;
    }

    MedalsTable(MedalsTable&& other) noexcept : medals(move(other.medals)) {}
    MedalsTable& operator=(MedalsTable&& other) noexcept {
        if (this != &other) {
            medals = move(other.medals);
        }
        return *this;
    }


    MedalRow operator()(const string& country) const {
        int max_medals = 0;
        MedalRow max_medal_type = MedalRow::BRONZE;

        for (const auto& medal : medals) {
            if (medal.country == country) {
                if (medal.gold > max_medals) {
                    max_medals = medal.gold;
                    max_medal_type = MedalRow::GOLD;
                }
                else if (medal.silver > max_medals) {
                    max_medals = medal.silver;
                    max_medal_type = MedalRow::SILVER;
                }
                else if (medal.bronze > max_medals) {
                    max_medals = medal.bronze;
                    max_medal_type = MedalRow::BRONZE;
                }
            }
        }
        return max_medal_type;
    }

    void addMedal(const string& country, int gold, int silver, int bronze) {
        Medal medal = { country, gold, silver, bronze };
        medals.push_back(medal);
    }

    friend ostream& operator<<(ostream& os, const MedalsTable& table) {
        os << "Таблица медалей:\n";
        os << "Страна | Золото | Серебро | Бронза\n";
        os << "-------|--------|---------|--------\n";
        for (const auto& medal : table.medals) {
            os << medal.country << " | " << medal.gold << " | " << medal.silver << " | " << medal.bronze << "\n";
        }
        return os;
    }

};


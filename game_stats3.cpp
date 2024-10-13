/*
Программа Game Stats 3.0
Демонстрирует работу с константами
*/
#include <iostream>

using namespace std;

int main()
{
    const int ALIEN_POINTS = 150;
    int aliensKilled = 10;
    int score = aliensKilled * ALIEN_POINTS;
    cout << "score: " << score << endl;
    enum difficulty {NOVICE, EASY, NORMAL, HARD, UNBEATABLE};
    difficulty myDifficulty = EASY;
    enum shipCost {FIGHTER_COST = 25, BOMBER_COST, INTERCEPTOR_COST, CRUISER_COST =50};
    shipCost myShipCost = INTERCEPTOR_COST;
    cout << "\nmyShipCost: " << myShipCost;
    cout << "\nTo upgrade my ship to a Cruiser will cost " << (CRUISER_COST - myShipCost) << " Resource Points. \n";

    cout << "Seven divided by three is " << 7 / 3 << endl;
    return 0;
}

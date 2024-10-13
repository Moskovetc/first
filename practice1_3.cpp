#include <iostream>

using namespace std;

int main()
{
    short score1, score2, score3;
    cout << "\n enter score 1 : ";
    cin >> score1;
    cout << "\n enter score 2 : ";
    cin >> score2;
    cout << "\n enter score 3 : ";
    cin >> score3;

    cout << "\naverage score: " << (score1 + score2 + score3)/3.0 << endl;
    return 0;
}
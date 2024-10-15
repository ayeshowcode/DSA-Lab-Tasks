#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;
void game(int p, int x)
{
    int n;
    cout << "Enter the number between 1 to 100: " << endl;
    cout << "player: " << p << " ";
    cin >> n;
    if (n == x)
    {
        cout << "player " << p << " won" << endl;
        return;
    }
    if (n < x)
    {
        cout << "try greater number" << endl;
    }
    else
    {
        cout << "try lesser number" << endl;
    }
    if (p == 1)
    {
        cout << "player 2 turn" << endl;
         game(2, x);
    }
    else
    {
        cout << "player 1 turn" << endl;
         game(1, x);
    }
}
int main()
{
    srand(static_cast<unsigned int>(std::time(0)));

    int randomNumber = (std::rand() % 100) + 1;

    game(1, randomNumber);
}
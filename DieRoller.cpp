

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand((unsigned)time(0));

	int luckyNums[] = { 1,6 };
	int randNum = (rand() % 6) + 1;

	cout << "You rolled a " << randNum << endl;
	for (int i = 1; i <= 6; i++)
	{
		if (randNum == luckyNums[i])
		{
			cout << "You rolled a lucky number!" << endl;
		}
	}
    return 0;
}


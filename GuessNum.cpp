#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	srand(rand());
	int secretNum = rand();
	int guess;

	while(secretNum != guess)
	{
		cout << "Enter guess: ";
		cin >> guess;
		if(guess > secretNum)
		{
			cout << "Too big!" << endl;
		} 
		else if(guess < secretNum)
		{
			cout << "Too small!" << endl;
		}
	}

	cout << "You win!";

	return 0;
}
#include <iostream>

using namespace std;

int main()
{
	int num1;
	int num2;
	char operation;

	cout << "Please enter the first number: ";
	cin >> num1;
	cout << "Please enter the second number: ";
	cin >> num2;
	cout << "Please select your operation(+, -, /, *): ";
	cin >> operation;


	switch (operation)
	{
	case '+':
		cout << num1 + num2;
		break;
	case '-':
		cout << num1 - num2;
		break;
	case '/':
		cout << num1 / num2;
		break;
	case '*':
		cout << num1 * num2;
		break;
	}
	cout << endl;

	cout << "Please enter the first number: ";
	cin >> num1;
	cout << "Please enter the second number: ";
	cin >> num2;
	cout << "Please select your operation(+, -, /, *): ";
	cin >> operation;
	

   	return 0;
}

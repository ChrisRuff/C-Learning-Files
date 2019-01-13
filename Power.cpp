#include <iostream>

using namespace std;

double power(double baseNum, double exponent);

int main()
{
	int baseNum;
	int exponent;

	cout << "Please enter the base number: ";
	cin >> baseNum;
	cout << "Please enter the exponent: ";
	cin >> exponent;	

	cout << power(baseNum, exponent) << endl;
    	return 0;
}

double power(double baseNum, double exponent)
{
	int result = 1;
	for(int i = 0; i < exponent; i++)
	{
		result *= baseNum;
	}
	return result;
}
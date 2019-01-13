#include <iostream>

using namespace std;

int main()
{
	for(int i = 18; i >= 0; i -= 2)
	{
		for(int j = i; j >= 0; j -= 2)
		{
			cout << j << " ";	
		}
		cout << endl;
	}
	return 0;
}
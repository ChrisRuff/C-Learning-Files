#include <iostream>
#include <boost/lexical_cast.hpp>

using namespace std;

bool andF(bool i, bool x)
{
	if(i && x)
		return true;
	return false;
}

bool orF(bool i, bool x)
{
	if(i || x)
		return true;
	return false;
}
bool logic(std::string input, bool *bools[])
{
	int position = 0;
	int counter = 0;

	for(char c: input)
	{
		if(c == '!')
		{
			input.at(position) = !boost::lexical_cast<bool>(input.at(position));	
			
		}

		if(c == '+')
		{
			*bools[counter] = orF(boost::lexical_cast<bool>(input.at(position-1)),  boost::lexical_cast<bool>(input.at(position+1)));	
			counter++;
		}
	
		if(c == '*')
		{
			*bools[counter] = andF(boost::lexical_cast<bool>(input.at(position-1)),  boost::lexical_cast<bool>(input.at(position+1)));	
			counter++;
		}
		positiot++;
	}
	return false;
		
	
}

int main()
{
	std::string input;
	bool result;
		

	cout << "Please enter function:" << endl;
	cin >> input;
	bool bools[input.length()/2] = {false};
	bool *boolsptr = bools;
	cout << logic(input, boolsptr) << endl;
	return 0;
}

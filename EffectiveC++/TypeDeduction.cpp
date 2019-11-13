#include <array>

template<typename T, std::size_t N>								
constexpr std::size_t arraySize(T (&)[N]) noexcept //In compile time calculate the size of array T, using it's reference 
{																									 //Reference because it can read the array length where a pointer would 
	return N;																				 //Decay to the initial size of the array
}


int main()
{

	int keyVals[] = {1, 3, 5, 6, 7, 8, 10, 30};
	std::array<int, arraySize(keyVals)> mappedVals;

	return 0;
}
	

	

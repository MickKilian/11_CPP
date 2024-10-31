#include <iostream>

template <typename T>
T	min( T x, T y )
{
	return ( x < y ? x : y );
}

int main(void)
{
	std::cout << "min : " << min<int>(3,4) << std::endl;
	return (0);
}

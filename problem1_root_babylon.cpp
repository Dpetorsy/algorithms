#include <iostream>

//calculate square root of an integer with Babylon method
float square_root(int n)
{
	float x = n;
	float y = 1;
	float e = 0.00001;
	while(x - y > e)
	{
		x = (x + y) / 2;
		y = n / x;
	}
	return x;
}

int main()
{
	int n;
	std::cout << "print number: ";
	std::cin >> n;
	std::cout << "Square root of " << n << " is " << square_root(n) << std::endl;

	return 0;
}

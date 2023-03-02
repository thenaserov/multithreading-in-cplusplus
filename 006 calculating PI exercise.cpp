#include <iostream>
#include <thread>
#include <iomanip>

float CalculatePi(int terms)
{
	float result{ 0 };
	for (int i = 0; i <= terms; i++)
	{
		int sign = pow(-1, i);
		double term = 1.0 / (i * 2 + 1);
		result += sign * term;
	}
	return result * 4;
}

int main()
{
	std::cout << std::setprecision(30) << CalculatePi(1'000'000'000) << std::endl;
	return 0;
}
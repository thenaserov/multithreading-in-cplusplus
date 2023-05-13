#include <iostream>
#include <thread>
#include <future>
#include <iomanip>
#include <exception>

void CalculatePi(int terms, std::promise<float> prms)
{
	float result{ 0 };
	try
	{
		if (terms < 1)
		{
			throw std::runtime_error("can not be less than one");
		}
		for (int i = 0; i <= terms; i++)
		{
			int sign = pow(-1, i);
			double term = 1.0 / (i * 2 + 1);
			result += sign * term;
		}
		prms.set_value(result * 4);
	}
	catch(...)
	{
		prms.set_exception(std::current_exception());
	}
	
}

int main()
{
	std::promise<float> prms;
	std::future<float> ftr = prms.get_future();
	std::thread t1(std::ref(CalculatePi), -2, std::move(prms));
	try
	{
		std::cout << std::setprecision(20) << ftr.get() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what()
			<< std::endl;
	}
	t1.join();
	return 0;
}
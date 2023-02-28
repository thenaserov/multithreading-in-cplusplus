#include <iostream>
#include <thread>
#include <mutex>

int main()
{
	int count{ 0 };
	const int ITERATIONS = 1'000'000;
	std::mutex mtx;

	std::thread t1([&count, &mtx]() {
		mtx.lock();
		for (int i{ 0 }; i < ITERATIONS; i++)
		{
			++count;
		}
		mtx.unlock();
	});

	std::thread t2([&count, &mtx]() {
		mtx.lock();
		for (int i{ 0 }; i < ITERATIONS; i++)
		{
			++count;
		}
		mtx.unlock();
	});

	t1.join();
	t2.join();

	std::cout << count << std::endl;
}
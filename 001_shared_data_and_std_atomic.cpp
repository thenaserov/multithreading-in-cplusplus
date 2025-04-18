#include <iostream>
#include <thread>
#include <atomic>


int main()
{
    std::atomic<int> count;
    count = 0;
    const int ITERATIONS = 1000000;

    std::thread t1([&count, &ITERATIONS]()
    {
        for (int i = 0; i < ITERATIONS; i++)
        {
            ++count;
        }
    });

    std::thread t2([&count, &ITERATIONS]()
    {
        for (int i = 0; i < ITERATIONS; i++)
        {
            ++count;
        }
    });

    t1.join();
    t2.join();

    std::cout << count << std::endl;
}

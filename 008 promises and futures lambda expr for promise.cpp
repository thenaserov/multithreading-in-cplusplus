#include <iostream>
#include <thread>
#include <future>
#include <iomanip>


float CalculatePi(int terms)
{
    float sum = 0.0;

    for (int i = 0; i < terms; i++)
    {
        int sign = pow(-1, i);
        double term = 1.0 / (i * 2 + 1);
        sum += sign * term;
    }

    return sum * 4;
}

int main()
{
    std::promise<float> promise;

    auto do_calculation = [&](int terms) {
        auto result = CalculatePi(terms);

        promise.set_value(result);
    };

    std::thread t1(do_calculation, 1'000'000'000);

    std::future<float> future = promise.get_future();

    std::cout << std::setprecision(15) << future.get() << std::endl;

    t1.join();
    return 0;
}
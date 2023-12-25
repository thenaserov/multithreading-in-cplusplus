#include <iostream>
#include <future>
#include <chrono>
#include <thread>
#include <vector>
#include <mutex>
#include <cmath>
#include <iomanip>

using ll = long long;

double calculate_pi(ll terms, int start, int skip)
{
    double sum = 0.0;

    for (ll i = start; i < terms; i += skip)
    {
        int sign = pow(-1, i);
        double term = 1.0 / (i * 2 + 1);
        sum += sign * term;
    }

    return sum * 4;
}

int main()
{
    std::vector<std::shared_future<double>> futures;

    const int CONCURRENCY = std::thread::hardware_concurrency();
    std::cout << CONCURRENCY << std::endl;
    for (int i = 0; i < CONCURRENCY; i++)
    {
        std::shared_future<double> f = std::async(std::launch::async, calculate_pi, 1E10, i, CONCURRENCY);
        futures.push_back(f);
    }

    double sum = 0.0;

    for (auto f : futures)
    {
        sum += f.get();
    }

    std::cout << std::setprecision(15) << "PI:  " << 3.14159 << std::endl;
    std::cout << std::setprecision(15) << "Our PI: " << sum << std::endl;

    return 0;
}

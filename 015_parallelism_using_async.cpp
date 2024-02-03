//lets calculate the sum of n numbers parallely using std::async
#include <iostream>
#include <iomanip>
#include <vector>
#include <future>
#include <cmath>

double CalculatePi(int terms, int start, int skip) {
    double result{ 0 };
    for (int i{start}; i < terms; i += skip) {
        int sign = std::pow(-1, i);
        double term = 1.0 / (i * 2 + 1);
        result += sign * term;
    }
    return result * 4;
}

int main() {
    constexpr int terms{ 1'000'000'000 };

    int parts_count = std::thread::hardware_concurrency(); //the no of parallel units that processes the vector
    std::vector<std::shared_future<double>> futures;
    for (int i {0}; i < parts_count; i++) {
        std::shared_future<double> result = std::async(std::launch::async, CalculatePi, terms, i, parts_count);
        futures.push_back(std::move(result));
    }

    double total{0};
    for (auto& future : futures) {
        total += future.get();
    }

    std::cout << std::setprecision(30) << total << std::endl;
    return 0;
}

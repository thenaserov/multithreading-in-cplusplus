// do this at your own risk
#include <thread>
#include <vector>
#include <iostream>
#include <cmath>
#include <cstdint>

int main() {
    unsigned int cores = std::thread::hardware_concurrency();
    if (cores == 0) cores = 4;
    std::cout << "Burning CPU on " << cores << " cores...\n";
    std::cout << "Terminate with Ctrl+C\n";
    std::vector<std::thread> workers;
    workers.reserve(cores);
    
    for (unsigned int i = 0; i < cores; ++i) {
        workers.emplace_back([i]() {  
            volatile double a = 1.000001 * (i + 1);
            volatile double b = 1.000002;
            volatile double c = 1.000003;
            while (true) {
                for (int k = 0; k < 1'000'000; ++k) {
                    a = std::sin(a) * std::cos(b);
                    b = std::sqrt(a * a + c);
                    c = std::log(b + 1.0);
                    a += b * c;
                }
            }
        });
    }
    for (auto &t : workers)
        t.join();
    return 0;
}

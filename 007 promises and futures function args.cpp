#include <math.h>

#include <future>
#include <iomanip>
#include <iostream>
#include <thread>

void CalculatePi(int terms, std::promise<float> prms) {
    float result{0};
    for (int i = 0; i <= terms; i++) {
        int sign = pow(-1, i);
        double term = 1.0 / (i * 2 + 1);
        result += sign * term;
    }
    prms.set_value(result * 4);
}

int main() {
    std::promise<float> prms;
    std::future<float> ftr = prms.get_future();
    std::thread t1(std::ref(CalculatePi), 1'000'000'000, std::move(prms));
    std::cout << std::setprecision(20) << ftr.get() << std::endl;
    t1.join();
    return 0;
}

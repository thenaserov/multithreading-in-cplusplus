#include <iostream>
#include <thread>

thread_local int counter = 0; // Each thread gets its own 'counter'

void increment(const std::string& name) {
    for (int i = 0; i < 3; ++i) {
        ++counter;
        std::cout << name << ": counter = " << counter << std::endl;
    }
}

int main() {
    std::thread t1(increment, "Thread 1");
    std::thread t2(increment, "Thread 2");

    t1.join();
    t2.join();
    return 0;
}

#include <iostream>
#include <mutex>
#include <thread>

void func(int &count, std::mutex &mtx) {
    mtx.lock();
    for (int i = 0; i < 1000; i++) {
        ++count;
    }
    mtx.unlock();
}

int main() {
    int count = 0;
    std::mutex mtx;

    std::thread t1(func, std::ref(count), std::ref(mtx));
    std::thread t2(func, std::ref(count), std::ref(mtx));

    t1.join();
    t2.join();

    std::cout << count << std::endl;
    std::cin.get();
    return 0;
}

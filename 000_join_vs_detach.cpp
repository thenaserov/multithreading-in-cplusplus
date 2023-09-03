#include <iostream>
#include <thread>
#include <chrono>

void fun(){
    std::this_thread::sleep_for(std::chrono::milliseconds(2'000));
    std::cout << "in fun" << std::endl;
}

void fun2(){
    std::this_thread::sleep_for(std::chrono::milliseconds(2'000));
    std::cout << "in fun2" << std::endl;
}

int main(){
    std::thread t1(&fun);
    std::thread t2(&fun2);
    t1.detach();
    t2.join();
    return 0;
}

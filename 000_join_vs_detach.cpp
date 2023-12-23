#include <iostream>
#include <thread>
#include <chrono>

//Thread routine that takes more time to execute
void fun(){
    for(int i=0; i<5; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1'000));
        std::cout << "in fun. count: " << i + 1 << std::endl;
    }
}

//Thread routine that takes lesser time to execute
void fun2(){
    for(int i=0; i<5; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout << "in fun2. count: " << i + 1 << std::endl;
    }
}

int main(){
    std::thread t1(&fun);
    std::thread t2(&fun2);
    t1.detach();
    t2.join();
    return 0;
}

/*
Output:
in fun2. count: 1
in fun. count: 1
in fun2. count: 2
in fun2. count: 3
in fun. count: 2
in fun2. count: 4
in fun2. count: 5
*/

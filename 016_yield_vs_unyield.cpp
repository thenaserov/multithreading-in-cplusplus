//github.com/thenaserov
#include <iostream>  
#include <thread>  
#include <chrono>  

void threadFunction(int id) {  
    for (int i = 0; i < 5; ++i) {  
        std::cout << "Thread " << id << " is running: iteration " << i << std::endl;  
        std::this_thread::yield();  // Yield to allow other threads to run  
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate work  
    }  
}  

int main() {  
    std::thread thread1(threadFunction, 1);  
    std::thread thread2(threadFunction, 2);  

    thread1.join();  
    thread2.join();  

    return 0;  
} 

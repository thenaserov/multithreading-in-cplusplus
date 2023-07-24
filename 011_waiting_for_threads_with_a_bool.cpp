#include <iostream>
#include <thread>
#include <chrono>

int main() {
    std::atomic<bool> ready = false;
	std::thread t1([&](){
	    std::cout << "Waiting for 2000 milli-seconds" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(2'000));
            ready = true;
        });
    while(!ready) {
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "ready " << ready << std::endl;
    t1.join();
    return 0;
}

#include <iostream>
#include <thread>
#include <chrono>
#include <condition_variable>

int main() {
	bool ready = false;
	std::condition_variable condition;
	std::mutex mtx;

	std::thread t1([&]() {
		std::this_thread::sleep_for(std::chrono::microseconds(2'000));
		std::unique_lock<std::mutex> lock(mtx); // will wait untill it can lock
		ready = true;
		lock.unlock();
		condition.notify_one(); // notifies the waiting thread
	});
	std::unique_lock<std::mutex> lock(mtx);
	while (!ready) {
		condition.wait(lock);
	}
	t1.join();
	return 0;
}

// conditions are good mechanism to do signaling between threads
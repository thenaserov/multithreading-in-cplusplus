#include <iostream>
#include <future>
#include <chrono>
#include <thread>
#include <vector>
#include <mutex>
#include <cmath>
#include <queue>

std::mutex g_mtx;

template <typename T>
class blocking_queue {
private:
    std::mutex _mtx;
    std::condition_variable _cond;
    int _max_size;
    std::queue<T> _queue;

public:
    blocking_queue(int max_size) : _max_size(max_size) {}

    void push(T data) {
        std::unique_lock<std::mutex> lock(_mtx);
        _cond.wait(lock, [this]() { return _queue.size() < _max_size; });
        _queue.push(data);
        lock.unlock();
        _cond.notify_one();
    }

    T front() {
        std::unique_lock<std::mutex> lock(_mtx);
        _cond.wait(lock, [this]() { return !_queue.empty(); });
        return _queue.front();
    }

    void pop() {
        std::unique_lock<std::mutex> lock(_mtx);
        _cond.wait(lock, [this]() { return !_queue.empty(); });
        _queue.pop();
        lock.unlock();
        _cond.notify_one();
    }

    int size() {
        std::lock_guard<std::mutex> lock(_mtx);
        return _queue.size();
    }
};

int work(int id) {
    std::unique_lock<std::mutex> lock(g_mtx);
    std::cout << "Starting " << id << std::endl;
    lock.unlock();
    int seconds = int((5.0 * rand()) / RAND_MAX + 3);
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
    return id;
}

int main() {
    // Here the argument supplied to the queue needs to be
    // one less than the number of threads you want to launch.
    blocking_queue<std::shared_future<int>> futures(2);
    std::thread t([&]() {
        for (int i = 0; i < 20; i++)
        {
            std::shared_future<int> f = std::async(std::launch::async, work, i);
            futures.push(f);
        }
    });

    for (int i = 0; i < 20; i++) {
        std::shared_future<int> f = futures.front();
        int value = f.get();
        futures.pop();
        std::cout << "Returned: " << value << std::endl;
    }

    t.join();
    return 0;
}

#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>

template<typename T>
class BlockingQueue {

public:
    BlockingQueue (int max_size): _max_size(max_size) {
        
    }

    void push(T data) {
        std::unique_lock<std::mutex> lock(_mtx);
        _cond.wait(lock, [this](){ return _queue.size() < _max_size; });
        _queue.push(data);
        lock.unlock();
        _cond.notify_one();
    }

    T pop() {
        std::unique_lock<std::mutex> lock(_mtx);
        _cond.wait(lock, [this](){ return!_queue.empty(); });
        _queue.pop();
        lock.unlock();
        _cond.notify_one();
    }

    int size() {
        std::lock_guard<std::mutex> lock(_mtx);
        return _queue.size();
    }

    T front() {
        std::unique_lock<std::mutex> lock(_mtx);
        return _queue.front();
    }

private:

    int _max_size;
    std::queue<T> _queue;

    // SYNCHRONIZATION VARIABLES
    std::mutex _mtx;
    std::condition_variable _cond;
};


int main() {
    BlockingQueue <int>bq(10);

    // Producer
    // BTW this '&' in the [] inside the lamda expression captures the local data and will have access to them!
    std::thread t1([&](){
        for(int i{0}; i < 10; ++i) {
            bq.push(i);
	    std::cout << "Produced >> " << i << std::endl;        
        }
    });

    // Consumer
    std::thread t2([&](){
        for(int i{0}; i < 10; ++i) {
            auto item = bq.front();
            bq.pop();
            std::cout << "Consumed: " << item << std::endl;
        }
    });

    t1.join();
    t2.join();

    return 0;
}

// simply we are handling a segmentation fault using a condition_variable and a lock

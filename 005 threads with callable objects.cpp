#include <iostream>
#include <mutex>
#include <thread>

class App {
public:
    void operator()() {
        for (int i = 0; i < 1'000'000; i++) {
            const std::lock_guard<std::mutex> guard(mtx_);
            ++count_;
        }
    }
    int GetCount() { return count_; }

private:
    int count_ = 0;
    std::mutex mtx_;

protected:
};

int main() {
    App app;

    std::thread t1(std::ref(app));
    std::thread t2(std::ref(app));

    t1.join();
    t2.join();

    std::cout << app.GetCount() << std::endl;
    return 0;
}

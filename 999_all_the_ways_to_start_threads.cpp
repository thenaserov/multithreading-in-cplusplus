#include <iostream>
#include <thread>

void execute(std::thread &t) {
    if (t.joinable()) {
        t.join();
    }
}

void task(int i) {
    std::cout << "In function" << std::endl;
    std::cout << i << std::endl;
}

class Task {
public:
    void operator()(int i) {
        std::cout << "In functor" << std::endl;
        std::cout << i << std::endl;
    }
};

class MyClass {
public:
    void run(int i) {
        std::cout << "In member function" << std::endl;
        std::cout << i << std::endl;
    }
};

class MyClass2 {
public:
    static void run(int i) {
        std::cout << "In static member function" << std::endl;
        std::cout << i << std::endl;
    }
};

int main() {
    int i{1};

    // 1. Function Pointer
    std::thread t(task, i);
    execute(t);

    // 2. Lambda Expression
    std::thread t_lambda([](int i) {
        std::cout << "In lambda expr" << std::endl;
        std::cout << i << std::endl;
    }, i);
    execute(t_lambda);

    // 3. Functor (Fix Most Vexing Parse)
    Task task;
    std::thread t_functor(task, i);
    execute(t_functor);

    // 4. Non-Static Member Function
    MyClass obj;
    std::thread t_member_function(&MyClass::run, std::ref(obj), i);
    execute(t_member_function);

    // 5. Static Member Function
    std::thread t_static_member_function(&MyClass2::run, i);
    execute(t_static_member_function);

    return 0;
}

// start a thread in a class

#include <iostream>
#include <thread>

class Hello {
public:
	void sayHello() {
		while(1)
			std::cout << "HELLO\n";
	}
	void startThread() {
		t = std::thread(&Hello::sayHello, this);
		t.join();
	}
private:
	std::thread t;
};

int main() {
	Hello h;
	h.startThread();

	return 0;
}

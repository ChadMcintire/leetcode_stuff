#include <iostream>
#include <functional>
#include <thread>
#include <mutex>
#include <stdexcept>
#include <climits>

using namespace std;

void printFirst(){
    cout << "first";
}

void printSecond(){
    cout << "second";
}

void printThird(){
    cout << "Third";
}

class Foo {
public:
    mutex m1;
    mutex m2;
    Foo() {
        m1.lock();
        m2.lock();
    }

    
    void first(function<void()> printFirst) {
        printFirst();
        m1.unlock();
    }

    void second(function<void()> printSecond) {
        m1.lock();
        printSecond();
        m1.unlock();
        m2.unlock();
    }

    void third(function<void()> printThird) {
        m2.lock();
        printThird();
        m2.unlock();
    }

private:
};


int main(){
    Foo foo;
    //foo.first(printFirst);
    //foo.first(void a)
    //foo.first();
    std::thread t1(&Foo::first, &foo, printFirst);
    std::thread t2(&Foo::second, &foo, printSecond);
    std::thread t3(&Foo::third, &foo, printThird);
    //t1.detach();
    //t2.detach();
    //t3.detach();
    t1.join();
    t2.join();
    t3.join();
}

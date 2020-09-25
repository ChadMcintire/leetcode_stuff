#include <iostream>
#include <functional>
#include <thread>
#include <mutex>
#include <stdexcept>
#include <climits>
#include <condition_variable>

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
    void first(function<void()> printFirst)
    {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();

        {
            // prevent lost wakeup and spurious wakeup
            // and with CTAD (since C++17), you don't need to type std::mutex as template argument
            //lock_guard can only lock a single mutext safely
            //mutex is automatically released when a lock goes out of scope
            std::lock_guard<std::mutex> lock { mutex_ };
            done_first_ = true;
        }
        //notifies all threads waiting to check their condition
        cv_.notify_all();
    }

    void second(function<void()> printSecond)
    {
        {
            std::unique_lock<std::mutex> lock { mutex_ };
            //cv_.wait parameters (std::unique_lock<std::mutex> object, and a bool function)
            //returns false if the waiting should continue
            cv_.wait(lock, [this] { return done_first_; });
        }

        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();

        {
            std::lock_guard<std::mutex> lock { mutex_ };
            done_second_ = true;
        }
        
        cv_.notify_one();
    }

    void third(function<void()> printThird)
    {
        {
            std::unique_lock<std::mutex> lock { mutex_ };
            cv_.wait(lock, [this] { return done_second_; });
        }

        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }

private:
    bool done_first_ { false };
    bool done_second_ { false };
    mutable std::mutex mutex_;
    std::condition_variable cv_;
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

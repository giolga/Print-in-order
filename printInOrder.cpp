#include <bits/stdc++.h>
using namespace std;

class Foo {
private:
    mutex task1, task2;
public:
    Foo() {
        task1.lock();
        task2.lock();
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();

        task1.unlock();
    }

    void second(function<void()> printSecond) {
        task1.lock();

        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();

        task2.unlock();
    }

    void third(function<void()> printThird) {
        task2.lock();

        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
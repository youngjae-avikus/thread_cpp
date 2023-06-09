#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std::literals;

std::timed_mutex m;

int main()
{
    std::unique_lock<std::timed_mutex> u1;
    std::unique_lock<std::timed_mutex> u2(m);

    // u1 = u2; // [ERROR] not apply copy
    u1 = std::move(u2);

    std::cout << u1.owns_lock() << std::endl;
    // std::cout << u2.owns_lock() << std::endl;

    if (u1) {
        std::cout << "acquire" << std::endl;
    }

    u1.unlock();

    std::cout << u1.owns_lock() << std::endl;
    
    if (u1.try_lock_for(2s)) {
        // ...
        u1.unlock();
    }

    u1.lock();

    u1.release();

    // u2 = std::move(u1);

    // std::cout << u2.owns_lock() << std::endl;

    std::unique_lock<std::timed_mutex> u3(m, std::adopt_lock);

    std::cout << u3.owns_lock() << std::endl;

    return 0;
}
#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;

struct storage
{
    size_t size = 10;
    std::queue<int> q;

    bool isFull() const { return q.size() == size; }
    bool isEmpty() const { return q.empty(); }

    void push(int n) { q.push(n); }
    void pop() { q.pop(); }

	size_t getSize() const { return q.size(); }
};

static void producer(storage& s)
{
    while (true)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&]() { return !s.isFull(); });

        s.push(1);

        std::cout << "(PUSH) Produced: " << s.getSize() << std::endl;

		lock.unlock();
        cv.notify_one();

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

static void consumer(storage& s)
{   
    while (true)
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [&](){ return !s.isEmpty(); });

        s.pop();

        std::cout << "(POP) Consumed: " << s.getSize() << std::endl;

        lock.unlock();
        cv.notify_one();

        std::this_thread::sleep_for(std::chrono::milliseconds(550));
    }
}

int main()
{
	storage s;

    std::thread prod1(producer, std::ref(s));
    std::thread prod2(producer, std::ref(s));

    std::thread cons1(consumer, std::ref(s));
    std::thread cons2(consumer, std::ref(s));

    prod1.join(); prod2.join(); cons1.join(); cons2.join();

    return 0;
}

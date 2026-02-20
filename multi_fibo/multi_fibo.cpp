#include <iostream>
#include <vector>
#include <mutex>
#include <future>
#include <thread>
#include <chrono>

constexpr int SIZE = 1000;
std::vector<long long> vec(SIZE, -1);
std::mutex mtx;

long long fibo(int n)
{
    if (n < 2) return 1;

    {
        std::lock_guard<std::mutex> lock(mtx);
        if (vec[n] != -1) return vec[n];
    }
    
    long long res = fibo(n - 1) + fibo(n - 2);
    
    {
        std::lock_guard<std::mutex> lock(mtx);
        vec[n] = res;
    }

	return res;  
}

int main()
{
	std::vector<int> targets = { 40, 20, 55, 30 };
	std::vector<std::future<long long>> futures;
    
    auto start = std::chrono::high_resolution_clock::now();

    for(auto& target : targets) 
    {
        futures.emplace_back(std::async(std::launch::async, fibo, target));
	}

    for (int i = 0; i < targets.size(); i++)
    {
		std::cout << "targets[" << i << "] = " << targets[i] << " fibo number = " << futures[i].get() << std::endl;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;


    std::cout << "Total parallel time: " << duration.count() << "s" << std::endl;

    return 0;
}
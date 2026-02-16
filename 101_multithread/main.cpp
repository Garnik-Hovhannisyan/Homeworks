#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <ctime>
#include <future>

constexpr size_t size = 1000 * 1000 * 1000;
const int thread_count = std::thread::hardware_concurrency();

void fill(std::vector<char>& vec)
{
    std::vector<std::thread> vec_threads;
    size_t step = size / thread_count;
    
    for (int i = 0; i < thread_count; i++)
    {
        size_t start = i * step;
        size_t end = (i + 1) * step;

        vec_threads.emplace_back([&, start, end]()
        {
            for (size_t j = start; j < end; j++) vec[j] = rand() % 100;
		});
    }

    for (auto& thread : vec_threads) thread.join();
}

size_t calc(std::vector<char>& vec)
{
    std::vector<std::thread> vec_threads;
    std::vector<size_t> sums(thread_count, 0);

    int num_threads = std::thread::hardware_concurrency();
    size_t step = size / thread_count;

    for (int i = 0; i < thread_count; i++)
    {
        size_t start = i * step;
        size_t end = (i + 1) * step;

        vec_threads.emplace_back([&, start, end, i]()
            {
                size_t temp = 0;
                for (size_t j = start; j < end; j++) temp += vec[j];
                sums[i] = temp;
            });
    }

    for (auto& thread : vec_threads) thread.join();

    size_t finalSum = 0;
    for (auto& s : sums) finalSum += s;
    return finalSum;
}

int main()
{
    std::vector<char> vec;
    vec.resize(size);

    auto fill_start = std::chrono::high_resolution_clock::now();
    fill(vec);
    auto fill_end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> fill_duration = fill_end - fill_start;

    auto calc_start = std::chrono::high_resolution_clock::now();
    size_t result = calc(vec);
    auto calc_end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> calc_duration = calc_end - calc_start;

    std::cout << "Fill time: " << fill_duration.count() << ".s" << std::endl;
    std::cout << "Calc time: " << calc_duration.count() << ".s" << std::endl;
	std::cout << "Sum: " << result << std::endl;
    return 0;
}


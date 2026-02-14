#include <iostream>
#include <chrono>
#include <thread>
#include <vector>


constexpr size_t size = 1000 * 1000 * 1000;

void fill(std::vector<size_t>& vec, size_t start, size_t end)
{
    for (size_t i = start; i < end; ++i)
    {
        vec[i] = (start + 58 + i * 21313 - 4564) % 100;
    }
}

void calc(std::vector<size_t>& vec, size_t start, size_t end, size_t& sum)
{
    size_t temp = 0;
    for (size_t i = start; i < end; ++i)
    {
        temp += vec[i];
    }
    sum = temp;
}

int main()
{
    auto start_time = std::chrono::high_resolution_clock::now();

    std::vector<size_t> vec;
    vec.resize(size);

    size_t step = size / 5;
    size_t sums[5] = { 0 };

	std::thread t1(fill, std::ref(vec), 0, step);
    std::thread t2(fill, std::ref(vec), step, step * 2);
    std::thread t3(fill, std::ref(vec), step * 2, step * 3);
    std::thread t4(fill, std::ref(vec), step * 3, step * 4);
    std::thread t5(fill, std::ref(vec), step * 4, size);

    t1.join(); t2.join(); t3.join(); t4.join(); t5.join();

    t1 = std::thread(calc, std::ref(vec), 0, step, std::ref(sums[0]));
    t2 = std::thread(calc, std::ref(vec), step, step * 2, std::ref(sums[1]));
    t3 = std::thread(calc, std::ref(vec), step * 2, step * 3, std::ref(sums[2]));
    t4 = std::thread(calc, std::ref(vec), step * 3, step * 4, std::ref(sums[3]));
    t5 = std::thread(calc, std::ref(vec), step * 4, size, std::ref(sums[4]));

    t1.join(); t2.join(); t3.join(); t4.join(); t5.join();

    size_t finalSum = 0;
    for (size_t i = 0; i < 5; ++i) finalSum += sums[i];
    
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end_time - start_time;

	std::cout << "Sum: " << finalSum << std::endl;
    std::cout << "Time: " << duration.count() << ".s" << std::endl;
    
    return 0;
}


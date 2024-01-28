//lets calculate the sum of n numbers parallely using std::async
#include <iostream>
#include <vector>
#include <future>
#include <algorithm>

using namespace std;

int main()
{
    constexpr int n = 1'000'000;
    std::vector<int> nums(n, 0);
    std::generate(nums.begin(), nums.end(), [n = 1]() mutable {return n++;}); //fill the vector with sequential numbers

    int parts_count = std::thread::hardware_concurrency(); //the no of parallel units that processes the vector
    size_t chunkSize = n / parts_count;

    auto calculate_chunk_sum = [&nums](size_t start, size_t end) {
        long long sum = 0;
        for (size_t i = start; i < end; ++i) {
            sum += nums[i];
        }
        return sum;
    };

    std::vector<std::future<long long>> parts_sum_futures;
    for (int i = 0; i < parts_count; i++)
    {
        size_t start = i * chunkSize;
        size_t end = (i == parts_count - 1) ? n : (i + 1) * chunkSize;

        auto result = std::async(
            calculate_chunk_sum,
            start, 
            end);

        parts_sum_futures.emplace_back(std::move(result));
    }

    long long total_sum = 0ll;
    for (auto& future : parts_sum_futures) {
        total_sum += future.get(); //wait and get the result of each async
    }

    std::cout << total_sum << std::endl;
    return 0;
}

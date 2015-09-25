#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <algorithm>


int cycle_length(int const& x, std::unordered_map<int, int>& cache)
{
    int cnt = 0, curr = x;
    while (curr != 1)
    {
        auto entry = cache.find(curr);
        if (entry != cache.end())
        {
            cache[x] = cnt + entry->second;
            return cache[x];
        }
        
        cnt++;
        curr = curr % 2 == 0 ? curr / 2 : 3 * curr + 1;
    } 

    cache[x] = cnt + 1;
    return cache[x];
}

int find_max_cycle_length(int x, int const& end, std::unordered_map<int, int>& cache)
{
    if (x > end)
    {
        return find_max_cycle_length(end, x, cache);
    }

    int max_cycle = cycle_length(x, cache);
    while (++x < end)
    {
        max_cycle = std::max(max_cycle, cycle_length(x, cache));
    }
    return max_cycle;
}


int main ()
{
    std::unordered_map<int, int> cache;

    std::string line;
    while (std::getline(std::cin, line)) 
    {
        std::stringstream tokenizer(line);
        int i, j; 
        tokenizer >> i >> j;

        std::cout << i << " "; 
        std::cout << j << " "; 
        std::cout << find_max_cycle_length(i, j, cache) << std::endl; 
    }
}

#include <algorithm>
#include <sstream>
#include <vector>
#include <iostream>

int amount_exchanged(std::vector<int> money)
{
    int total = std::accumulate(money.begin(), money.end(), 0);
    int nguys = money.size();
    int change = total % nguys;
    int quot = total / nguys;

    int amt = 0;
    for (auto m : money)
    {
        if (m < quot)
        {
            amt += quot - m;
        }
    }

    return amt;
}

int main()
{
    // int m[] = {1000, 2000, 3000};
    // int m[] = {1500, 1501, 300, 301};
    // int nguys = sizeof(m) / sizeof(int);
    // std::vector<int> money(nguys);
    // std::copy(m, m+nguys, money.begin());
    // std::cout << amount_exchanged(money) << std::endl;

    std::string line;
    while (std::getline(std::cin, line))
    {
        std::stringstream ss(line);
        int nguys; 
        ss >> nguys;

        if (nguys == 0)
        {
            return 0;
        }

        std::vector<int> money;
        while (nguys--)
        {
            std::getline(std::cin, line);
            std::stringstream ss(line);
            double x;
            ss >> x;
            money.push_back(x * 100);
        }
        printf("$%1.2f\n", amount_exchanged(money) / 100.0);
    }
}

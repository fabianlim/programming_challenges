#include <iostream>
#include <list>
#include <algorithm>
#include <sstream>

// for s = 3
// Hor    " --- "
// Double "|   |"
// Left   "|    "
// Right  "    |"
enum Line {Hor, Double, Left, Right, Blank};

void print_line(int s, char const& left, char const& mid, char const& right)
{
    std::string m(s, mid);
    std::cout << left << m << right;
}

void print_builder(
        int const& s, 
        std::list<Line> commands)
{
    while (!commands.empty())
    {
        switch (commands.front())
        {
            case Hor:
                print_line(s, ' ', '-', ' ');
                break;
            case Double:
                print_line(s, '|', ' ', '|');
                break;
            case Left:
                print_line(s, '|', ' ', ' ');
                break;
            case Right:
                print_line(s, ' ', ' ', '|');
                break;
            case Blank:
                print_line(s, ' ', ' ', ' ');
                break;
        }
        commands.pop_front();
    }
}

int get_region(int line, int const& s)
{
    if (line == 1)
    {
        return 1;
    }
    line -= 1;

    if (line <= s)
    {
        return 2;
    }
    line -= s;

    if (line == 1)
    {
        return 3;
    }
    line -= 1;

    if (line <= s)
    {
        return 4;
    }

    return 5;
}
void print_digit(int const& x, int const& line, int const& size)
{
    std::list<Line> commands;

    // TODO: overly complicated. Just need single print lines below
    // TODO: print_builder doesnt need to execute multiple commands
    switch (get_region(line, size)) 
    {
        case 1:
            if (x == 1 || x == 4)
            {
                commands.push_back(Blank);
            } else {
                commands.push_back(Hor);
            }
            break;
        case 2:
            if (x == 5 || x == 6)
            {
                commands.push_back(Left);
            } else if (x == 1 || x == 2 || x == 3 || x == 7) {
                commands.push_back(Right);
            } else {
                commands.push_back(Double);
            }
            break;
        case 3:
            if (x == 1 || x == 7 || x == 0)
            {
                commands.push_back(Blank);
            } else {
                commands.push_back(Hor);
            }
            break;
        case 4:
            if (x == 2)
            {
                commands.push_back(Left);
            } else if (x == 6 || x == 8 || x == 0) {
                commands.push_back(Double);
            } else {
                commands.push_back(Right);
            }
            break;
        case 5:
            if (x == 1 || x == 4 || x == 7)
            {
                commands.push_back(Blank);
            } else {
                commands.push_back(Hor);
            }
            break;
    }
    print_builder(size, commands);
}

void raster(std::string const& nums, int const& s)
{

    for (int cnt = 1; cnt <= 2*s + 3; cnt++)
    {
        for (auto x: nums)
        {
            print_digit(x - '0', cnt, s);
            printf(" ");
        }
        printf("\n");
    }
}

int main () 
{
    std::string line;

    while (std::getline(std::cin, line))
    {
        std::stringstream ss(line);
        int digit_size;
        ss >> digit_size;

        if (digit_size == 0)
        {
            return 0;
        }

        std::string digits;
        ss >> digits;
        raster(digits, digit_size);
    }
}

#include <string>
#include <sstream>
#include <iostream>
#include <vector>

void update_line(
        int const& row, 
        int const& nrows, 
        std::vector<std::string>& map, 
        std::string const& line)
{
    int col = 0, ncols = line.size();
    for (auto c: line)
    {
        if (c == '*')
        {
            // set 
            map[row][col] = '*';

            // update neighbors
            for (int y=row-1; y <= row+1; y++)
            {
                for (int x= col-1; x <= col+1; x++)
                {
                    if (x >= 0 && x < ncols &&
                        y >= 0 && y < nrows &&
                        map[y][x] != '*')
                    {
                        map[y][x]++;
                    }
                }
            }
        }
        col++;
    }
}

int main() 
{
    std::string line;
    int fieldnum = 0;
    
    while (std::getline(std::cin, line))
    {
        std::stringstream ss(line);
        int nrow, ncol;
        ss >> nrow >> ncol;

        if (nrow == 0 && ncol == 0)
        {
            return 0;
        }

        std::string initline(ncol, '0');
        std::vector<std::string> map(nrow, initline);

        for (int cnt = 0; cnt < nrow; cnt++)
        {
            std::getline(std::cin, line);
            std::cout << line << std::endl;
            update_line(cnt, nrow, map, line);
        }

        std::cout << "Field #" << ++fieldnum << ":" << std::endl;
        for (auto s : map)
        {
            std::cout << s << std::endl;
        }
    }
}

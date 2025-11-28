#include <cstddef>
#include <stdexcept>
#include <iostream>

void PrintBits(long long value, size_t bytes)
{
    if (bytes <= 8 && bytes > 0){
        char counter = 0;

        std::cout << "0b";

        for (int i = 8*bytes - 1; i >= 0; --i)
        {
            if (counter % 4 == 0 && counter)
            {
                std::cout << '\'';
                counter = 0;
            }
            std::cout << ((value >> i) & 1);
            ++counter;
        }

        std::cout << '\n';
    }
    
}

#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <cmath>


void SolveQuadratic(int a, int b, int c)
{
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                std::cout << "infinite solutions";
            } else {
                std::cout << "no solutions";
            }
        } else {
            std::cout << static_cast<double>(-c) / static_cast<double>(b);
        }
        return;
    }
    
    double discr = b * b - 4 * a * c;

    if (discr)
    {
        if (discr > 0)
        {
            double solution1 = 0;
            double solution2 = 0;

            solution1 = (-b + std::sqrt(discr)) / (a * 2.);
            solution2 = (-b - std::sqrt(discr)) / (a * 2.);

            if (solution1 > solution2)
                std::swap(solution1, solution2);

            std::cout << std::setprecision(6) << solution1 << ' ' << solution2;
        }
        else
        {
            std::cout << "no solutions";
                
        }
    }
    else
    {
        std::cout << std::setprecision(6) << (-b - std::sqrt(discr)) / (2.0 * a);
    
    }
}
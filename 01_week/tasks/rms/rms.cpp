#include <cstdef>
#include <stdexcept>
#include <cmath>

double CalculateRMS(double values[], size_t size)
{
    if (!size){
        return 0.;
    }
    long double sum = 0;
    for (size_t i = 0; i < size; ++i)
    {
        sum += std::pow(values[i]);
    }
    
    return static_cast<double>(std::sqrt(sum/static_cast<double> size));
}
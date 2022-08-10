#ifndef UTILS_H
#define UTILS_H

#include<iostream>
#include <math.h>


template <typename T>
T round(T data, int dec2round)
{
    return floor(data * std::pow(10, dec2round - 1) + 0.5) / std::pow(10, dec2round - 1);
}


#endif // UTILS_H

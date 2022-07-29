#ifndef UTILS_H
#define UTILS_H

#include<iostream>
#include <math.h>


template <typename T>
T round(T data, int decplace)
{
    int ibase = data * std::pow(10,decplace-1);
    int diff = data * std::pow(10,decplace) - (ibase * 10);

    T tbase = ibase/std::pow(10,decplace-1);

    return diff < 5 ? tbase : tbase + 1/std::pow(10,decplace-1);
}





#endif // UTILS_H

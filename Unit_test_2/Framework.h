#ifndef FRAMEWORK_H
#define FRAMEWORK_H

#include <cassert>
#include <iostream>
#include "Unit_test_2.h"

void test_mean(int first, int second)
{
    ExtArray<int> v1{ 4, 2, 7, 3, -5, 0, -3, 1 };
    try
    {
        assert(v1.mean(first, second));
        std::cout << "Mean test OK" << std::endl;
    }
    catch (const std::invalid_argument& e) 
    {
        std::cout << "исключение: " << e.what() << std::endl;
    }
}

#endif
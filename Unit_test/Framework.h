#ifndef FRAMEWORK_H
#define FRAMEWORK_H

#include <cassert>
#include <iostream>
#include "Extended_array.h"

void test_mean() 
{
    ExtArray<int> v1{ 4, 2, 7, 3, -5, 0, -3, 1 };
    assert(v1.mean() == 1.125);
    std::cout << "Mean test OK" << std::endl;
}

void test_median() 
{
    ExtArray<double> v2{ 4.5, 0.7, 10.8, 2.6, -3.5 };
    assert(v2.median() == 2.6);
    std::cout << "Median test OK" << std::endl;
}

void test_mode() 
{
    ExtArray<int> v1{ 4, 2, 7, 2, 5, -5, 0, 5, 5 };
    auto result = v1.mode();
    assert(result.first == 5 && result.second == 3);
    std::cout << "Mode test OK" << std::endl;
}

void test_empty_array()
{
    ExtArray<int> empty(0);
    assert(empty.mean() == 0.0);
    assert(empty.median() == 0.0); 
    auto mode_result = empty.mode();
    assert(mode_result.first == 0);
    assert(mode_result.second == 0);
    std::cout << "0" << std::endl;
}
#endif
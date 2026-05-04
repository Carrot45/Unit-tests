#define CATCH_CONFIG_MAIN  
#include "catch.hpp"       
#include "Unit_test_3.h"  
#include <string>
#include <windows.h>

TEST_CASE("checkSum() полная проверка", "[checksum]")
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    SECTION("Правильные данные")
    {
        ExtArray<int> arr{ 1, 0, 1 };
        CHECK(arr.checkSum() == 2);
    }

    SECTION("Неправильные данные")
    {
        ExtArray<int> arr{ 1, 0, 1 };
        CHECK(arr.checkSum() == 1);
    }

    SECTION("Некорректное значение (2)")
    {
        ExtArray<int> arr{ 1, 0, 2, 1 };
        CHECK_THROWS_AS(arr.checkSum(), std::logic_error);
    }

    SECTION("Отрицательное число")
    {
        ExtArray<int> arr{ 1, -1, 1 };
        CHECK_THROWS_AS(arr.checkSum(), std::logic_error);
    }

    SECTION("Неправильный тип (double)")
    {
        ExtArray<double> arr{ 1.0, 0.0, 1.0 };
        CHECK_THROWS_AS(arr.checkSum(), std::bad_typeid);
    }
}
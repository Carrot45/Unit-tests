#define CATCH_CONFIG_MAIN  
#include "catch.hpp"       
#include "Unit_test_3.h"  
#include <string>
#include <windows.h>


TEST_CASE("checkSum() полная проверка", "[checksum]")
{
    SECTION("Неправильное содержимое (число 2)")
    {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        ExtArray<int> arr{ 1, 0, 2, 1 };
        try {
            arr.checkSum();
            CHECK(false); // Если дошли сюда - исключения не было, тест провален
        }
        catch (const std::logic_error& e) {
            std::cout << "Обработана ошибка: " << e.what() << std::endl;
            CHECK(true); // Ожидаемое исключение - тест пройден
        }
        catch (const std::exception& e) {
            std::cerr << "Неожиданная ошибка: " << e.what() << std::endl;
            CHECK(false);
        }
    }
    SECTION("Правильные данные")
    {
        ExtArray<int> arr{ 1, 0, 1 };
        //CHECK_NOTHROW(arr.checkSum());
        CHECK(arr.checkSum() == 2);
    }

    SECTION("Неправильное содержимое (число 2)")
    {
        ExtArray<int> arr{ 1, 0, 2, 1 };
        CHECK_THROWS_AS(arr.checkSum(), std::logic_error);
    }

    SECTION("Неправильное содержимое (отрицательное число)")
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
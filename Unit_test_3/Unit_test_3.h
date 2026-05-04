#ifndef UNIT_TEST_3_H
#define UNIT_TEST_3_H

#include <vector>
#include <initializer_list>
#include <stdexcept>
#include <type_traits>

template <typename T>
class ExtArray
{
private:
    std::vector<T> extended_array;
    size_t _size;

public:
    ExtArray(std::initializer_list<T> l) : extended_array(l), _size(l.size()) {}
    ExtArray(int size) : extended_array(size), _size(size) {}

    T& operator[](size_t index) { return extended_array[index]; }
    size_t size() const { return _size; }

    double mean(int first, int second)
    {
        if (_size == 0) return 0.0;
        if (first < 0 || second > static_cast<int>(_size) || first >= second)
        {
            throw std::invalid_argument("Значения для номеров указаны неверно");
        }
        double sum = 0;
        for (int i = first; i < second; i++)
        {
            sum += extended_array[i];
        }
        return sum / (second - first);
    }

    int checkSum()
    {
        // Проверка типа
        if constexpr (!std::is_same_v<T, bool> && !std::is_same_v<T, int>)
        {
            throw std::bad_typeid();
        }

        int count = 0;

        if constexpr (std::is_same_v<T, bool>)
        {
            for (size_t i = 0; i < _size; i++)
            {
                if (extended_array[i] == true)
                    count++;
            }
        }

        if constexpr (std::is_same_v<T, int>)
        {
            for (size_t i = 0; i < _size; i++)
            {
                if (extended_array[i] == 1)
                    count++;
                else if (extended_array[i] != 0 && extended_array[i] != 1)
                {
                    throw std::logic_error("Массив содержит значения, отличные от 0 и 1");
                }
            }
        }

        return count;
    }
};

#endif 
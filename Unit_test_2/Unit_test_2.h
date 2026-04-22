#ifndef EXTENDED_ARRAY_H
#define EXTENDED_ARRAY_H

#include <vector>
#include <initializer_list>
//#include <utility>
//#include <algorithm>
#include <iostream>
#include <string>
#include <windows.h>
#include <stdexcept>

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

	bool is_valid_range(int first, int second) const
	{
		return !(first < 0 || second > static_cast<int>(_size) || first >= second);
	}

	double mean(int first, int second)
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		if (_size == 0)
		{
			return 0.0;
		}
		else
		{
			if (!is_valid_range(first, second))
			{
				throw std::invalid_argument("Значения для номеров указаны неверно");
			}
			double sum = 0;
			for (size_t i = first; i < second; i++)
			{
				sum += extended_array[i];
			}
			return (sum / (second - first));
		}
	}
};


#endif
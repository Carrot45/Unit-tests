#ifndef EXTENDED_ARRAY_H
#define EXTENDED_ARRAY_H

#include <vector>
#include <initializer_list>
#include <utility>
#include <algorithm>
#include <iostream>

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

	double mean()
	{
		if (_size == 0)
		{
			return 0.0;
		}
		else
		{
			double sum = 0;
			for (size_t i = 0; i < _size; i++)
			{
				sum += extended_array[i];
			}
			return sum / _size;
		}
	}

	double median()
	{
		if (_size == 0)
		{
			return 0.0;
		}
		else
		{
			std::vector<T> temp_array;
			std::copy(extended_array.begin(), extended_array.end(), back_inserter(temp_array));
			std::sort(temp_array.begin(), temp_array.end());
			if (_size % 2 == 1)
			{
				return temp_array[_size / 2];
			}
			else
			{
				return static_cast<double>(temp_array[(_size / 2) - 1] + temp_array[_size / 2]) / 2;
			}
		}
	}

	std::pair<T, int> mode()
	{
		if (_size == 0) 
		{ 
			return std::pair<T, int>(T(), 0);
		}
		else
		{
			T max = extended_array[0], cmax = 0, rmax = 0;
			for (int i = 0; i < _size; i++)
			{
				if (cmax > rmax)
				{
					rmax = cmax;
					max = extended_array[i - 1];
				}
				cmax = 0;
				for (int j = i; j < _size; j++)
				{
					if (extended_array[j] == extended_array[i])
					{
						cmax++;
					}
				}
			}
			return std::pair<T, int>(max, rmax);
		}
	}
};


#endif
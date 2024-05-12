#include <iostream>
#include <vector>
#include <cstdint>
#include "support_functions.h"

std::vector<std::vector<uint32_t>> conversion_table{
    {12, 4, 6, 2, 10, 5, 11, 9, 14, 8, 13, 7, 0, 3, 15, 1},
    {6, 8, 2, 3, 9, 10, 5, 12, 1, 14, 4, 7, 11, 13, 0, 15},
    {11, 3, 5, 8, 2, 15, 10, 13, 14, 1, 7, 4, 12, 9, 6, 0},
    {12, 8, 2, 1, 13, 4, 15, 6, 7, 0, 10, 5, 3, 14, 9, 11},
    {7, 15, 5, 10, 8, 1, 6, 13, 0, 9, 3, 14, 11, 4, 2, 12},
    {5, 13, 15, 6, 9, 2, 12, 10, 11, 7, 8, 1, 4, 3, 14, 0},
    {8, 14, 2, 5, 6, 9, 1, 12, 15, 4, 11, 0, 13, 10, 3, 7},
    {1, 7, 14, 13, 0, 5, 8, 3, 4, 15, 10, 6, 9, 12 ,11 ,2}
};

uint32_t applyConversionTable(const uint32_t& num) { // функция, которая заменяет исходное 32 битное число с помощью таблицы перестановок
	uint32_t result{0};
    for(int j{0}; j < 8; j++) {
        uint32_t value_of_4_bits{(num << 4*(7-j)) >> 28}; // выделение j-ых подряд идущих 4 бита
        value_of_4_bits = (conversion_table[j][value_of_4_bits]) << 4*j; // замена на элементы из таблицы conversion_table
        result += value_of_4_bits;
    }
    return result;
}
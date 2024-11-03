/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-02 16:56:46
 * @LastEditTime: 2024-11-02 17:18:34
 * @Description: 编写函数，接受一对指向 vector<int＞的迭代器和一个int值。在两个迭 代器指定的范围中查找给定的值，返回一个布尔值来指出是否找到。
 * 
 */


#include <cstdlib>
#include <iostream>
#include <ostream>
#include <vector>

/**
 * @brief 在两个迭 代器指定的范围中查找给定的值，返回一个布尔值来指出是否找到。
 * 
 * @param begin vector<int>的 begin 迭代器
 * @param end vector<int>的 end 迭代器
 * @param val 要确认是否存在的元素值
 * @return true 
 * @return false 
 */
bool findVal(std::vector<int>::const_iterator begin,
             std::vector<int>::const_iterator end,
             int val) {

    while (begin != end) {
        if (*begin == val) {
            return true;
        }
        ++begin;
    }

    return false;
}


/**
 * @brief 重写上一题的函数，返回一个迭代器指向找到的元素。注意，程序必须处理未找到给定值的情况。
 * 
 * @param begin 
 * @param end 
 * @param val 
 * @return std::vector<int>::const_iterator 
 */
std::vector<int>::const_iterator
backVal(std::vector<int>::const_iterator begin,
        std::vector<int>::const_iterator end,
        int val) {
    while (begin != end) {
        if (*begin == val) return begin;
        ++begin;
    }

    return end;
}


int main(int argc, const char **argv) {

    std::vector<int> i_v{0, 1, 2, 3, 4, 5, 6};

    std::cout << std::boolalpha << findVal(i_v.begin(), i_v.end(), 6) << std::endl;

    return 0;
}
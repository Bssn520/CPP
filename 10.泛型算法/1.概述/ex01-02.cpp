/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-09 16:06:55
 * @LastEditTime: 2024-11-09 16:12:46
 * @Description: 标准库 count 函数
 *
 */
#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

int main(int argc, const char **argv)
{
    std::vector<int> iv{0, 1, 2, 3, 4, 5, 6, 7, 8, 4, 4};
    const int times = std::count(iv.cbegin(), iv.cend(), 4);
    std::cout << times << std::endl; // 3

    std::list<std::string> il{"hello", "world", "hello", "你好"};
    const int times2 = std::count(il.cbegin(), il.cend(), "hello");
    std::cout << times2 << std::endl; // 2

    return 0;
}

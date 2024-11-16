/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-16 18:21:17
 * @LastEditTime: 2024-11-16 18:23:49
 * @Description:
 *
 */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
int main(int argc, const char **argv)
{
    std::list<int> lv{0, 1, 2, 3, 6, 0, 3, 4, 0, 8, 9};

    auto comma = std::find(lv.crbegin(), lv.crend(), 0);

    std::cout << std::distance(comma, lv.crend()) << std::endl; // 9

    return 0;
}

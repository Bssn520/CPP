/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-16 15:19:06
 * @LastEditTime: 2024-11-16 15:28:06
 * @Description:
 *
 */
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

bool greater_than(const std::string &s, std::string::size_type sz)
{
    return s.size() < sz;
}

int main(int argc, const char **argv)
{
    std::string s = "myLength10";
    std::vector<int> iv{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    auto greater_than_size = std::bind(greater_than, s, std::placeholders::_1);
    auto iter = std::find_if(iv.cbegin(), iv.cend(), greater_than_size);

    std::cout << *iter << std::endl; // 11

    return 0;
}

/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-16 15:13:10
 * @LastEditTime: 2024-11-16 15:17:59
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
    return s.size() > sz;
}

int main(int argc, const char **argv)
{
    std::vector<std::string> sv{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle", "1234567"};

    std::string::size_type sz = 6;

    auto greater_than_6 = std::bind(greater_than, std::placeholders::_1, sz);

    std::cout << std::count_if(sv.cbegin(), sv.cend(), greater_than_6) << std::endl;


    return 0;
}

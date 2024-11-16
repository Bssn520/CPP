/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-15 11:04:57
 * @LastEditTime: 2024-11-15 11:09:55
 * @Description:
 *
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, const char **argv)
{
    std::vector<std::string> sv{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle", "1234567"};

    auto cnt = std::count_if(sv.begin(), sv.end(),
                             [](const std::string &s)
                             { return s.size() > 6; });

    std::cout << cnt << std::endl; // 1


    return 0;
}

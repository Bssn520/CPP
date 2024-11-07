/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-07 20:25:49
 * @LastEditTime: 2024-11-07 20:38:14
 * @Description: 从一个 vector<char>初始化一个 string
 * 
 */

#include <iostream>
#include <string>
#include <vector>

int main(int argc, const char **argv)
{
    std::vector<char> cv{'a', 'b', 'c'};

    std::string s(cv.begin(), cv.end());

    std::cout << s << std::endl;// abc

    return 0;
}
/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-16 17:10:35
 * @LastEditTime: 2024-11-16 17:26:48
 * @Description:
 *
 */


#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

int main(int argc, const char **argv)
{
    std::vector<std::string> sv;
    std::ifstream fin("../3.定制操作/input.txt");
    std::istream_iterator<std::string> in_iter(fin), eof;

    while (in_iter != eof)
    {
        sv.push_back(*in_iter++);
    }

    for (const auto &s : sv)
        std::cout << s << " ";
    std::cout << std::endl;

    return 0;
}

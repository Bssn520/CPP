/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-18 16:39:45
 * @LastEditTime: 2024-11-18 16:49:25
 * @Description:
 *
 */

#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main(int argc, const char **argv)
{
    std::vector<std::pair<std::string, int>> vp;
    std::string s;
    int i;
    while (std::cin >> s >> i)
    {
        if (s == "q")
            break;

        vp.push_back(std::make_pair(s, i));
        // 等价
        vp.push_back(std::pair<std::string, int>(s, i));
        // 等价
        std::pair<std::string, int> p(s, i);
        vp.push_back(p);
        // 等价
        std::pair<std::string, int> p2 = {s, i};
        vp.push_back(p2);
        // 等价
        vp.emplace_back(s, i);
    }

    for (const auto &pair : vp)
    {
        std::cout << pair.first << " " << pair.second << std::endl;
    }


    return 0;
}

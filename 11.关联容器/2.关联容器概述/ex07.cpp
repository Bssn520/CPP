/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-17 17:46:46
 * @LastEditTime: 2024-11-17 17:58:57
 * @Description:
 *
 */

#include <iostream>
#include <map>
#include <string>
#include <vector>

int main(int argc, const char **argv)
{
    std::map<std::string, std::vector<std::string>> families;
    std::string last_name, first_name;

    std::cout << "请输入姓氏: ";
    std::cin >> last_name;
    std::cout << "请输入名字: ";
    while (std::cin >> first_name)
    {
        if (first_name == "q")
            break;
        std::cout << "请输入名字: ";
        families[last_name].push_back(first_name);
    }

    for (const auto &s : families)
    {
        std::cout << "姓氏: " << s.first << std::endl
                  << " 家族成员: " << std::endl;
        for (const auto &last : s.second)
        {
            std::cout << s.first << last << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

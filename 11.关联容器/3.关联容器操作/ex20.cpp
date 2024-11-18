/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-18 17:47:18
 * @LastEditTime: 2024-11-18 18:00:14
 * @Description:
 *
 */
#include <cstddef>
#include <iostream>
#include <map>
#include <string>
#include <utility>
int main(int argc, const char **argv)
{
    std::map<std::string, size_t> word_count;
    std::string word;
    while (std::cin >> word)
    {
        if (word == "q")
            break;

        auto ret = word_count.insert({word, 1});
        // 等价于
        // std::pair<std::map<std::string, size_t>::iterator, bool> ret2 = word_count.insert({word, 1});

        if (!ret.second)
            ++ret.first->second;
    }
    for (const auto &w : word_count)
        std::cout << w.first << " " << w.second << std::endl;

    return 0;
}

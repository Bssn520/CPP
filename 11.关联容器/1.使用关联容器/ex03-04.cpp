/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-17 17:20:17
 * @LastEditTime: 2024-11-17 17:31:44
 * @Description: 单词计数程序
 *
 */

#include <algorithm>
#include <cctype>
#include <cstddef>
#include <iostream>
#include <map>
#include <set>
#include <string>

int main(int argc, const char **argv)
{
    std::map<std::string, size_t> word_count; // string 映射到 size_t 的空 map(键映射到值)
    std::set<std::string> exclude = {"The", "But", "And", "Or", "An", "A", "the", "but", "and", "or", "an", "a"};
    std::string word;

    while (std::cin >> word)
    {
        if (word == "q")
            break;
        // 删除标点
        word.erase(std::find_if(word.begin(), word.end(), ispunct), word.end());
        // 将word转化为小写
        std::for_each(word.begin(), word.end(), [](char &c)
                      { c = std::tolower(c); });
        if (exclude.find(word) == exclude.end())
            ++word_count[word]; // 提取 word 的计数器并将其加 1
    }

    for (const auto &w : word_count) // 对 map 中的每个元素
    {
        std::cout << w.first << " occous " << w.second
                  << ((w.second > 1) ? " times" : " time") << std::endl;
    }

    return 0;
}

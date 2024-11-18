/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-17 16:53:08
 * @LastEditTime: 2024-11-17 17:19:52
 * @Description:
 *
 */


/*
使用关联容器

关联容器中的元素按关键字来保存和访问。

关联容器类型
按关键字有序保存元素:
map         // 关联数组: 保存键值对
set         // 关联字即值，即只保存关键字的容器
multimap    // 关键字可以重复出现的map
multiset    // 关键字可以重复出现的set
无序集合:
unordered_map       // 用哈希函数组织的map
unordered_set       // 用哈希函数组织的set
unordered_multimap  // 哈希组织的map；关键字可以重复出现
unordered_multiset  // 哈希组织的set；关键字可以重复出现

使用 map

    std::map<std::string, size_t> word_count; // string 映射到 size_t 的空 map(键映射到值)
    std::string word;
    从标准输入读取单词，并使用读取到的单词对 map 进行下标操作，如果 word 还不在 map 中，下标运算符会创建一个新元素，关键字为 word，值为 0
    while (std::cin >> word)
        ++word_count[word];

使用 set

    std::set<std::string> exclude = {"The", "But", "And", "Or", "An", "A", "the", "but", "and", "or", "an", "a"};
    if (exclude.find(word) == exclude.end()) {}
 成员find 函数返回一个迭代器。如果关键字在set中，迭代器指向该关键字。否则，返回尾后迭代器。




*/

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

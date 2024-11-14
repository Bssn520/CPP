/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-14 16:01:36
 * @LastEditTime: 2024-11-14 16:17:30
 * @Description:
 *
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void elimDups(std::vector<std::string> &words)
{
    // 按字典序排序
    std::sort(words.begin(), words.end());

    // unique 重排
    auto end_unique = std::unique(words.begin(), words.end());

    // 使用向量操作 erase 删除重复单词
    words.erase(end_unique, words.end());
}

void biggies(std::vector<std::string> &words,
             std::vector<std::string>::size_type sz)
{
    elimDups(words);
    std::stable_sort(words.begin(), words.end(),
                     [](const std::string &a, const std::string &b)
                     { return a.size() < b.size(); });

    // 获取一个迭代器，指向第一个满足 size() >= sz 的元素
    auto wc = std::find_if(words.begin(), words.end(),
                           [sz](const std::string &s)
                           { return s.size() >= sz; });

    // 计算满足 size() >= sz 的元素的数目
    auto count = words.end() - wc;

    std::for_each(wc, words.end(),
                  [](const std::string &s)
                  { std::cout << s << " "; });
    std::cout << std::endl;
}


int main(int argc, const char **argv)
{
    std::vector<std::string> vs = {"d", "c", "b", "a", "a", "c", "e", "bb", "aa", "aaa", "aaaaa"};

    biggies(vs, 2);

    return 0;
}

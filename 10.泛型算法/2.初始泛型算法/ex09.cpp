/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-09 19:37:07
 * @LastEditTime: 2024-11-09 19:51:44
 * @Description: 排序并删除vector<string>中的重复单词
 *
 */


#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void printVec(std::string title, const std::vector<std::string> &vec)
{
    std::cout << title << std::endl;
    for (const auto &s : vec)
        std::cout << s << " ";
    std::cout << std::endl;
}

void elimDups(std::vector<std::string> &words)
{
    // 按字典序排序
    std::sort(words.begin(), words.end());
    printVec("After sort: ", words);

    // unique 重排
    auto end_unique = std::unique(words.begin(), words.end());
    printVec("After unique: ", words);

    // 使用向量操作 erase 删除重复单词
    words.erase(end_unique, words.end());
    printVec("After erase: ", words);
}

int main(int argc, const char **argv)
{
    std::vector<std::string> sv{"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};

    elimDups(sv);

    return 0;
}

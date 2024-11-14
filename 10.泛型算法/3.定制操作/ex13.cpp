/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-14 11:36:09
 * @LastEditTime: 2024-11-14 11:45:59
 * @Description: 编写函数，接受一个 string，返回一个boo1值，指出 string 是否有5个或更多字符。使用此函数划分 words。打印出长度大于等于5的元素。
 *
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool greater_than_5(const std::string &s)
{
    return s.size() >= 5;
}

void printVec(std::string title, const std::vector<std::string> &vec)
{
    std::cout << title << std::endl;
    for (const auto &s : vec)
        std::cout << s << " ";
    std::cout << std::endl
              << std::endl;
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

    auto iter = std::partition(sv.begin(), sv.end(), greater_than_5);
    printVec("After partitionm: ", sv);

    sv.erase(iter, sv.end());
    printVec("After erase: ", sv);

    return 0;
}

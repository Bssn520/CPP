/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-16 18:24:27
 * @LastEditTime: 2024-11-16 18:32:04
 * @Description: 给定一个包含10个元素的 vector，将位置3到7之间的元素按逆序拷贝到一个 list中。
 *
 */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>
int main(int argc, const char **argv)
{
    std::vector<int> iv{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::list<int> lv;

    std::copy(iv.crbegin() + 2, iv.crend() - 3, std::back_inserter(lv));

    for (const auto i : lv)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}

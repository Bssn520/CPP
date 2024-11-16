/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-16 16:27:12
 * @LastEditTime: 2024-11-16 16:34:05
 * @Description:
 *
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

int main(int argc, const char **argv)
{
    std::vector<int> iv{1, 2, 3, 3, 5, 5, 3, 6, 7};
    std::list<int> lv;

    std::sort(iv.begin(), iv.end());

    std::unique_copy(iv.cbegin(), iv.cend(), std::back_inserter(lv));

    for (const auto &i : lv)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}

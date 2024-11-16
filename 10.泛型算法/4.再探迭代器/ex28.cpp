/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-16 16:27:16
 * @LastEditTime: 2024-11-16 16:43:35
 * @Description:
 *
 */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <vector>

void printList(const std::string title, const std::list<int> &list)
{
    std::cout << title;
    for (const auto &i : list)
        std::cout << i << " ";
    std::cout << std::endl;
}

int main(int argc, const char **argv)
{
    std::vector<int> iv{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::list<int> l1, l2, l3;

    std::copy(iv.cbegin(), iv.cend(), std::back_inserter(l1));
    printList("back_inserter: ", l1);

    std::copy(iv.cbegin(), iv.cend(), std::front_inserter(l2));
    printList("front_inserter: ", l2);

    std::copy(iv.cbegin(), iv.cend(), std::inserter(l3, l3.end()));
    printList("inserter: ", l3);

    return 0;
}

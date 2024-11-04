/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-04 14:49:51
 * @LastEditTime: 2024-11-04 14:57:38
 * @Description: 从一个 list<int> 拷贝元素到两个 deque 中。值为偶数的所有元素都拷贝到一个 deque 中，而奇数值元素都拷贝到另一个 deque 中。
 * 
 */

#include <cstddef>
#include <deque>
#include <iostream>
#include <list>

int main(int argc, const char **argv) {
    std::list<int> il;
    std::deque<int> odd;
    std::deque<int> even;

    for (size_t i = 0; i != 100; ++i)
        il.push_back(i);

    for (const auto i: il)
        (i % 2) ? odd.push_back(i) : even.push_back(i);

    std::cout << "奇数: ";
    for (const auto i: odd)
        std::cout << i << " ";
    std::cout << std::endl;

    std::cout << "偶数: ";
    for (const auto i: even)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
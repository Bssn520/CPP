/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-20 21:11:13
 * @LastEditTime: 2024-11-20 21:19:20
 * @Description:
 *
 */

#include <iostream>
#include <vector>

std::vector<int> *create_vi()
{
    return new std::vector<int>();
}

void push_vi(std::vector<int> *vi)
{
    int i;
    while (std::cin >> i)
        vi->push_back(i);
}

void print_vi(std::vector<int> *vi)
{
    for (const auto &i : *vi)
        std::cout << i << " ";
    std::cout << std::endl;
}

int main(int argc, const char **argv)
{
    auto vi_ptr = create_vi();
    push_vi(vi_ptr);
    print_vi(vi_ptr);
    delete vi_ptr;

    return 0;
}

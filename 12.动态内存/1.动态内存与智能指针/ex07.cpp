/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-20 21:11:13
 * @LastEditTime: 2024-11-20 21:22:57
 * @Description:
 *
 */

#include <iostream>
#include <memory>
#include <vector>

std::shared_ptr<std::vector<int>> create_vi()
{
    return std::make_shared<std::vector<int>>();
}

void push_vi(std::shared_ptr<std::vector<int>> p)
{
    int i;
    while (std::cin >> i)
        p->push_back(i);
}

void print_vi(std::shared_ptr<std::vector<int>> p)
{
    for (const auto &i : *p)
        std::cout << i << " ";
    std::cout << std::endl;
}

int main(int argc, const char **argv)
{
    auto vi_ptr = create_vi();
    push_vi(vi_ptr);
    print_vi(vi_ptr);

    return 0;
}

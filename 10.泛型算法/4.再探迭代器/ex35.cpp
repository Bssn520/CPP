/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-16 18:17:22
 * @LastEditTime: 2024-11-16 18:20:44
 * @Description:
 *
 */

#include <iostream>
#include <vector>

int main(int argc, const char **argv)
{
    std::vector<int> iv{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (auto i = iv.size(); i != 0; --i)
        std::cout << iv[i] << " ";
    std::cout << std::endl;
    // 等价
    for (auto iter = iv.end(); iter != iv.begin(); --iter)
        std::cout << *iter << " ";
    std::cout << std::endl;

    return 0;
}

/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-16 18:13:08
 * @LastEditTime: 2024-11-16 18:16:44
 * @Description:
 *
 */
#include <iostream>
#include <vector>
int main(int argc, const char **argv)
{
    std::vector<int> iv{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (auto r_iter = iv.crbegin(); r_iter != iv.crend(); ++r_iter)
        std::cout << *r_iter << " ";
    std::cout << std::endl;

    return 0;
}

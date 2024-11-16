/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-15 11:11:02
 * @LastEditTime: 2024-11-15 11:20:34
 * @Description:
 *
 */

#include <iostream>

int main(int argc, const char **argv)
{
    int i = 3;
    auto f = [&]() -> bool
    {
        if (i != 0)
            --i;
        return i == 0; };


    // 测试lambda
    while (!f())
    {
        std::cout << "i is not zero, current value: " << i << std::endl;
    }

    std::cout << "i is now zero!" << std::endl;

    return 0;
}

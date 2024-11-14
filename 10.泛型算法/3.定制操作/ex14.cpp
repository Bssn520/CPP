/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-14 15:56:46
 * @LastEditTime: 2024-11-14 15:56:57
 * @Description: 编写一个 lambda，接受两个 int，返回它们的和。
 *
 */

#include <iostream>
int main(int argc, const char **argv)
{
    auto add_int = [](int a, int b)
    { return a + b; };
    std::cout << add_int(203, 292) << std::endl; // 495

    return 0;
}

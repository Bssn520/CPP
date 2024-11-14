/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-14 15:59:33
 * @LastEditTime: 2024-11-14 16:00:52
 * @Description: 编写一个lambda，捕获它所在函数的int，并接受一个int参数。lambda应该返回捕获的int 和 int 参数的和。
 *
 */

#include <iostream>
int main(int argc, const char **argv)
{
    int x = 1;
    auto add_int = [x](int y)
    { return x + y; };

    std::cout << add_int(78) << std::endl; // 79

    return 0;
}

#include <iostream>

int main()
{
    // 打印 Hello World
    std::cout << "Hello, World" << std::endl;

    // 打印两个数的积, 并且将每个运算对象的打印操作放在一条独立的语句中。
    int n1 = 0, n2 = 0;
    std::cout << "Enter 2 numbers:";
    std::cout << std::endl;

    std::cin >> n1;
    std::cin >> n2;

    std::cout << n1;
    std::cout << " 与 ";
    std::cout << n2;
    std::cout << " 乘积为: ";
    std::cout << n1 * n2;
    std::cout << std::endl;

    return 0;
}
#include <iostream>

int main()
{
    int value = 0, sum = 0;
    while (std::cin >> value) // Mac 按 ctrl + d 结束输入
    {
        sum += value;
    }
    std::cout << "Sum is: " << sum << std::endl;

    return 0;
}
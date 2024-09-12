#include <iostream>

int main()
{
    // 计算从 50-100的整数相加和
    int i = 50, sum = 0;
    while (i <= 100)
    {
        sum += i;
        i++;
    }
    std::cout << "Sum of 50 to 100 inclusive is: " << sum << std::endl;

    // 练习使用递减运算符
    int i2 = 10;
    while (i2 >= 1)
    {
        std::cout << i2 << std::endl;
        i2--;
    }

    // 打印用户所输入的两个数字之间的所有整数
    std::cout << "Enter 2 numbers:" << std::endl;
    int largeNum = 0, smallNum = 0;
    std::cin >> largeNum >> smallNum;
    int tmp = 0;
    if (largeNum < smallNum)
    {
        tmp = largeNum;
        largeNum = smallNum;
        smallNum = tmp;
    }

    while (smallNum <= largeNum)
    {
        std::cout << smallNum << std::endl;
        smallNum++;
    }

    return 0;
}
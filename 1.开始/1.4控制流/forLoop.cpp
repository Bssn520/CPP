#include <iostream>

int main()
{
    // for 循环计算 -100 + -99 + ... + 99 + 100 的和
    int sum = 0;
    for (int i = -100; i <= 100; i++)
    {
        sum += i;
    }
    std::cout << sum <<std::endl;

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

    /**
     * for循环执行流程
     * 1. 创建变量 i 并初始化
     * 2. 检查 i 是否小于等于10: 如果为真，执行for循环体；
     *    如果为假，退出循环执行for循环后的第一条语句。
     * 3. 将 i 的值 +1
     * 4. 继续重复第二步，直至条件判断为假
     */
    for (int i = smallNum; i <= largeNum; i++)
    {
        std::cout << i << std::endl;
    }

    return 0;
}
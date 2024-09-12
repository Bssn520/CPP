#include <iostream>

int main()
{
    // currVal 是当前轮正在统计的数值, val是读入的新值
    int currVal = 0, val = 0;
    if (std::cin >> currVal)
    {
        int cnt = 1;
        while (std::cin >> val)
        {
            if(currVal == val) // 判断记录值是否与新输入的值相等
            {
                cnt++; // 如果相等则计数器 +1 并接受下一的输入
            } else {
                std::cout << currVal << " occurs "
                 << cnt << " times." << std::endl; // 打印统计结果
                
                currVal = val; // 记住新值
                cnt = 1; // 重置计数器
            }
        }
        // 打印最后一个记录值的个数
        std::cout << currVal << " occurs "
        << cnt << " times." << std::endl;  
    }

    return 0;
}
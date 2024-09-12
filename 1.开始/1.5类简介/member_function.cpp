#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item currItem, valItem;
    if (std::cin >> currItem)
    {
        int count = 1;

        while (std::cin >> valItem)
        {
            // 判断 ISBN 是否相等
            if (valItem.isbn() == currItem.isbn())
            {
                count++;
            }
            else
            {
                std::cout << currItem << " occurs "
                << count << " times." << std::endl; // 打印统计结果

                currItem = valItem;
                count = 1;
            }
        }
        // 打印最后一个记录值的个数
        std::cout << currItem << " occurs "
        << count << " times." << std::endl;  
    }

    return 0;
}


#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item total, trans;
    if (std::cin >> total)
    {
        while (std::cin >> trans)
        {
            // 判断 ISBN 是否相等
            if (trans.isbn() == total.isbn())
            {
                total += trans; // 更新总销售额
            }
            else
            {
                // 打印前一本书的销售结果
                std::cout << total << std::endl;
                total = trans;
            }
        }
        // 打印最后一本书的结果
        std::cout << total << std::endl;  
    }
    else
    {
        std::cerr << "No data?!" <<std::endl;

        return -1;
    }

    return 0;
}


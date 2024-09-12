#include <iostream>
#include "Sales_item.h"

/**
 * addItems 为可执行程序名, items.txt 为输入来源, items_out.txt 为输出目标
 * ./addItems <items.txt >items_out.txt
 */
int main()
{
    Sales_item item, sum;
    while (std::cin >> item)
    {
       sum += item;
    }
    std::cout << sum << std::endl;

    return 0;
}
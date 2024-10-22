#include <iostream>
#include <ostream>
#include <string>
#include "Sales_data_ex11.h"



int main()
{
    // 默认构造函数
    Sales_data item_default;
    print(std::cout, item_default);
    std::cout << std::endl;
    // 初始化 bookNo 的构造函数
    Sales_data item_bookNo("12121");
    print(std::cout, item_bookNo);
    std::cout << std::endl;
    // 初始化三个数据成员的构造函数
    Sales_data item_all("12122", 2, 5);
    print(std::cout, item_all);
    std::cout << std::endl;


    return  0;
}
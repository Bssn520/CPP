#include <iostream>
#include <string>
#include "Sales_data_ex06.h"

using namespace std;


int main()
{
    /** Sales_data 类测试 */
    Sales_data total;   // 用来保存当前的操作结果
    if (read(std::cin, total))
    {
        Sales_data trans;   // 用来保存下一笔交易的数据
        while (read(std::cin, trans))
        {

            if (total.isbn() == trans.isbn())   // 如果和上本书不是同一本
                total.combine(trans);   // 更新total的值
            else
            {
                print(std::cout, total);

                total = trans;  // 从头开始保存
            }
        }
        print(std::cout, total);
    }
    else
    {
        std::cerr << "No Data?!" << endl;
    }

    return 0;
}
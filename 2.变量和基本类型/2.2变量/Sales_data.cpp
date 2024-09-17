#include <iostream>
#include <string>
#include "Sales_data.h"
using namespace std;

int main()
{
    // 定义类对象
    struct Sales_data data1, data2;

    /**
     * 1. Sales_data对象读入数据
     */
    double price = 0; // 书的单价，用于计算销售收入

    // 读入第一笔交易 “ISBN 销售数量 单价”
    cin >> data1.bookNo >> data1.units_sold >> price;
    // 计算销售收入
    data1.revenue = data1.units_sold * price;

    // 读入第二笔交易
    cin >> data2.bookNo >> data2.units_sold >> price;
    data2.revenue = data2.units_sold * price;

    /**
     * 2. 输出两个Sales_data对象的和
     */
    if (data1.bookNo == data2.bookNo)
    {
        unsigned totalCnt = data1.units_sold + data2.units_sold;
        double totalRevenue = data1.revenue + data2.revenue;

    // 输出 ISBN 总销售量 总销售额 平均价格
    cout << data1.bookNo << " " << totalCnt
         << " " << totalRevenue << " ";
         if (totalCnt != 0)
            cout << totalRevenue/totalCnt << endl;
        else
            cout << "(no sales)" << endl;

    return 0;
    }
    else
    {
        cerr << "Data must refer to the same ISBN" << endl;

        return -1;
    }


}
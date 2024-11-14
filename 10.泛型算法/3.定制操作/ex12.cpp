/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-14 11:12:23
 * @LastEditTime: 2024-11-14 11:29:15
 * @Description: 编写名为 compareIsbn 的函数，比较两个 Sales_data 对象的 isbn() 成员。使用这个函数排序一个保存 Sales_data 对象的 vector。
 *
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Sales_data_ex41.hpp"

bool compareIsbn(const Sales_data &data1, const Sales_data &data2)
{
    return data1.isbn() < data2.isbn();
}


int main(int argc, const char **argv)
{
    std::vector<std::string> sales_v;

    std::ifstream is("./input.txt");
    std::string buf;

    if (!is)
    {
        std::cout << "Open file error" << std::endl;
        return 1;
    }

    while (std::getline(is, buf))
        sales_v.push_back(buf);

    std::vector<Sales_data> sales_sorted;
    for (const auto &s : sales_v)
    {
        std::istringstream iss(s);
        sales_sorted.push_back(Sales_data(iss));
    }

    std::stable_sort(sales_sorted.begin(), sales_sorted.end(), compareIsbn);

    for (const auto s : sales_sorted)
        std::cout << s.isbn() << " ";
    std::cout << std::endl;

    return 0;
}

#ifndef SALES_DATA_H_
#define SALES_DATA_H_

#include <istream>
#include <string>
#include <iostream>

struct Sales_data;

std::istream &read(std::istream &is, Sales_data &item);
std::ostream &print(std::ostream &os, const Sales_data &item);
Sales_data add(const Sales_data &item1, const Sales_data &item2);


struct Sales_data {
    // 构造函数
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s) { }
    Sales_data(const std::string &s, unsigned n, double p) :
                bookNo(s), units_sold(n), revenue(n * p) { }
    Sales_data(std::istream &s) { read(s, *this); }
    // 成员函数
    std::string isbn() const { return bookNo; }
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
    // 数据成员
    std::string bookNo;        // ISBN
    unsigned units_sold = 0;   // 销售数量
    double revenue = 0.0;      // 总收入
};

// 成员函数的定义
Sales_data& Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;

    return *this;
}

double Sales_data::avg_price() const
{
    if (units_sold)
        return revenue/units_sold;
    else
        return 0;
}

// 非成员函数的定义
Sales_data add(const Sales_data &item1, const Sales_data &item2)
{
    Sales_data sum = item1;
    sum.combine(item2);

    return sum;
}

std::istream &read(std::istream &is, Sales_data &item)
{
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold * price;

    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();

    return os;
}

#endif
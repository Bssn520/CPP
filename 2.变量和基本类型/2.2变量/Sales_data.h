#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>

struct Sales_data {
    std::string bookNo;        // ISBN
    unsigned units_sold = 0;   // 销售数量
    double revenue = 0.0;      // 收入
};

#endif
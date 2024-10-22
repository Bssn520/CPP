#ifndef PERSON_H_
#define PERSON_H_

#include <string>
#include <iostream>

struct Person
{
    // 成员函数
    std::string get_name() const { return name; }
    std::string get_address() const { return address; }
    // 数据成员
    std::string name;
    std::string address;
};

/** 读取一个 Person 实例 */
std::istream &read(std::istream &is, Person &item)
{
    is >> item.name >> item.address;

    return is;
}
/** 打印一个 Person 实例 */
std::ostream &print(std::ostream &os, const Person &item)
{
    os << item.name << " " << item.address;

    return os;
}

#endif

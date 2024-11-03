/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-03 17:34:10
 * @LastEditTime: 2024-11-03 17:40:11
 * @Description: 将一个1ist 中的char *指针（指向C风格字符串）元素赋值给一个 vector 中的 string。
 * 
 */


#include <iostream>
#include <list>
#include <string>
#include <vector>


int main(int argc, const char **argv) {
    std::list<const char *> c_l;
    std::vector<std::string> s_v;

    c_l.push_back("hello");
    c_l.push_back("world");

    s_v.assign(c_l.begin(), c_l.end());

    for (const auto s: s_v) std::cout << s << " ";
    std::cout << std::endl;// hello world

    return 0;
}
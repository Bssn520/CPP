/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-04 14:41:08
 * @LastEditTime: 2024-11-04 14:46:37
 * @Description: 从标准输入读取 string 序列，存入一个deque 中。编写一个循环，用迭代器打印 deque 中的元素
 * 
 */


#include <deque>
#include <iostream>
#include <string>
int main(int argc, const char **argv) {
    std::deque<std::string> d_s;

    std::string buf;
    while (std::cin >> buf) {
        if (buf == "q")
            break;
        d_s.push_back(buf);
    }

    for (auto iter = d_s.cbegin(); iter != d_s.cend(); ++iter) {
        std::cout << *iter << " ";
    }

    return 0;
}
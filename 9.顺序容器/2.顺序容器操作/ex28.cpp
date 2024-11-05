/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-04 20:40:37
 * @LastEditTime: 2024-11-04 21:02:15
 * @Description: 编写函数，接受一个 forward_list<string>和两个 string 共三个参数。
 * 函数应在链表中查找第一个 string，并将第二个 string 插入到紧接着第一个string之后的位置。
 * 若第一个 string 未在链表中，则将第二个 string 插入到链表末尾。
 * 
 */


#include <forward_list>
#include <iostream>
#include <string>


void insertString(std::forward_list<std::string> &flist,
                  std::string s1, std::string s2) {
    auto prev = flist.before_begin();
    auto curr = flist.begin();

    while (curr != flist.end()) {
        if (*curr == s1) {
            curr = flist.insert_after(curr, s2);
            return;
        } else {
            prev = curr;
            ++curr;
        };
    }
    std::cout << "未找到目标值: " + s1 << std::endl;
    flist.insert_after(prev, s2);
}


int main(int argc, const char **argv) {
    std::forward_list<std::string> flist = {"Every", "man", "is", "a", "poet", "when", "he", "is", "in", "love"};

    std::string s1("a"), s2("romantic");
    insertString(flist, s1, s2);

    std::cout << "结果: ";
    for (const auto s: flist) {
        std::cout << s << " ";
    }
    std::cout << "." << std::endl;

    return 0;
}

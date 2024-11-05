/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-04 20:35:10
 * @LastEditTime: 2024-11-04 20:40:09
 * @Description: 查找并删除forward_1ist<int>中的奇数元素。
 * 
 */


#include <forward_list>
#include <iostream>


int main(int argc, const char **argv) {
    std::forward_list<int> flist = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    auto prev = flist.before_begin();
    auto curr = flist.begin();

    while (curr != flist.end()) {
        if (*curr % 2 != 0)
            curr = flist.erase_after(prev);
        else {
            prev = curr;
            ++curr;
        }
    }

    for (auto i: flist)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}

/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-04 19:34:58
 * @LastEditTime: 2024-11-04 19:52:01
 * @Description: 
 * 
 */

#include <iostream>
#include <list>
#include <vector>
int main(int argc, const char **argv) {
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};

    std::vector<int> iv(ia, std::end(ia));
    std::list<int> il(ia, std::end(ia));

    for (auto it = il.begin(); it != il.end();) {
        if (*it % 2 != 0) {
            it = il.erase(it);
        } else {
            ++it;
        }
    }

    for (auto it = iv.begin(); it != iv.end();) {
        if (*it % 2 == 0) {
            it = iv.erase(it);
        } else {
            ++it;
        }
    }

    for (const auto i: iv)
        std::cout << i << " ";
    std::cout << std::endl;

    for (const auto i: il)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}

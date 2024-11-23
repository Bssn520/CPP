/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-22 21:02:51
 * @LastEditTime: 2024-11-22 21:08:08
 * @Description:
 *
 */

#include <cstring>
#include <iostream>
#include <string>

int main(int argc, const char **argv)
{

    char a[] = "aaa";
    char b[] = "bbb";
    char *pc = new char[strlen("aaa"
                               "bbb") +
                        1];
    strcat(pc, a);
    strcat(pc, b);
    std::cout << std::string(pc) << std::endl;

    delete[] pc;

    return 0;
}

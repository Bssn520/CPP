/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-16 17:35:04
 * @LastEditTime: 2024-11-16 17:35:22
 * @Description:
 *
 */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
int main(int argc, const char **argv)
{
    std::istream_iterator<int> in_iter(std::cin), eof;
    std::ostream_iterator<int> out_iter(std::cout, " ");

    std::vector<int> iv(in_iter, eof);

    std::sort(iv.begin(), iv.end());

    std::unique_copy(iv.cbegin(), iv.cend(), out_iter);
    std::cout << std::endl;


    return 0;
}

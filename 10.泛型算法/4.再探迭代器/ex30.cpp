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

    std::copy(iv.cbegin(), iv.cend(), out_iter);
    std::cout << std::endl;


    return 0;
}

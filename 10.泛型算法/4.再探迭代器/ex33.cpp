/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-16 17:36:04
 * @LastEditTime: 2024-11-16 17:55:38
 * @Description: 编写程序，接受三个参数：一个输入文件和两个输出文件的文件名。
 * 输入文件保存的应该是整数。使用 istream_iterator 读取输入文件。
 * 使用ostream_iterator 将奇数写入第一个输出文件，每个值之后都跟一个空格。
 * 将偶数写入第二个输出文件，每个值都独占一行。
 *
 */

#include <fstream>
#include <iostream>
#include <iterator>


int main(int argc, const char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: ./program numbers.txt odd.txt even.txt" << std::endl;
        return 1;
    }

    std::ifstream fin(argv[1]);
    std::ofstream odd_fin(argv[2]);
    std::ofstream even_fin(argv[3]);
    if (!fin || !odd_fin || !even_fin)
    {
        std::cerr << "Can't open file" << std::endl;
        return 1;
    }

    std::istream_iterator<int> in_iter(fin), eof;
    while (in_iter != eof)
    {
        int buf = *in_iter;

        if (buf % 2 != 0)
            odd_fin << buf << " ";
        else
            even_fin << buf << " ";

        ++in_iter;
    }

    return 0;
}

#include <iostream>

/** 
 * 多行注释测试
 * 
 * 注释界定符可以跨越程序中的多行，但这并不是必须的。
 * 当注释界定符跨越多行时，最好能显式指出其 内部的程序行都属于多行注释的一部分。
 * 我们所采用的风格是，注释内的每行都以一个星号开头，从而指出整个范围都是多行注释的一部分。
 * 
 * 一个注释不能嵌套在另一个注释之内。
 * 因为当编译器碰见 *斜线 时会自动认为注释结束而导致该层注释外的外层注释失效。
 */
int main()
{
    // 单行注释测试
    // 打印 Hello World
    std::cout << "Hello World" << std::endl;

    return 0;
}
/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-08 16:59:56
 * @LastEditTime: 2024-11-09 13:11:23
 * @Description:
 *
 */


#include <iostream>
#include <stack>
#include <string>

int main(int argc, const char **argv)
{
    std::string str("This is (pezy).");
    std::stack<char> stack;
    auto left = str.find('(');
    auto right = str.find(')');

    if (left != std::string::npos && right != std::string::npos && left < right)
    {
        for (size_t i = left + 1; i < right; ++i)
            stack.push(str[i]);

        std::string repstr;
        while (!stack.empty())
        {
            repstr += stack.top();
            stack.pop();
        }

        // 替换括号内容
        str.replace(left + 1, right - left - 1, repstr);
    }
    std::cout << str << std::endl;

    return 0;
}

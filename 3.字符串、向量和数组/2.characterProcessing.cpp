#include <iostream>
#include <string>
#include <cctype>
using namespace std;

/**
 * 处理string对象中的字符
 * 
 * cctype头文件中定义了一组标准库函数处理这部分工作:
 * isalnum (c)  当c是字母或数字时为真
 * isalpha (c)  当c是字母时为真
 * iscntrl (c)  当c是控制字符时为真
 * isdigit (c)  当c是数字时为真
 * isgraph (c)  当c不是空格但可打印时为真
 * islower (c)  当c是小写字母时为真
 * isprint (c)  当c是可打印字符时为真（即c是空格或c具有可视形式）
 * ispunct (c)  当c是标点符号时为真（即c不是控制字符、数字、字母、可打印空白中的 一种）
 * isspace (c)  当c是空白时为真(即c是空格、横向制表符、纵向制表符、回车符、换行 符、进纸符中的一种)
 * isupper (c)  当c是大写字母时为真 
 * isxdigit (c）当c是十六进制数字时为真
 * tolower (c)  如果c是大写字母，输出对应的小写字母：否则原样输出c
 * toupper (c)  如果c是小写字母，输出对应的大写字母；否则原样输出c
 * 
 */

int main()
{
    /**
     * 基于范围的for语句
     * 
     * 语法形式:
     * for (declaration : expression)
     *     statament
     * 其中，expression 部分是一个对象，用于表示一个序列。
     * declaration 部分负责定义一个变 量，该变量将被用于访问序列中的基础元素。
     * 每次迭代，declaration 部分的变量会被初始 化为expression 部分的下一个元素值。
     * 
     */
    string str = "Some string";
    for (auto c : str)
        cout << c << endl;

    // 统计字符串中的标点数量
    string sentences;
    decltype(sentences.size()) punct_cnt = 0;
    getline(cin, sentences);
    for (auto c : sentences)
        if (ispunct(c))
            punct_cnt++;
    cout << punct_cnt << " punctuation characters in: " << sentences << endl;

    // 使用索引访问string对象中的字符
    for (auto c : sentences)
        if (!sentences.empty())
            sentences[1] = toupper(sentences[1]);
    cout << sentences << endl; // HEllo World!

    // 使用下标执行迭代
        // 依次处理s中的字符直至我们处理完全部字符或者遇到一个空白
    for (decltype(sentences.size()) i = 0;
         i != sentences.size() && !isspace(sentences[i]); i++)
         sentences[i] = toupper(sentences[i]);
    cout << sentences << endl; // HELLO World!

    // 使用下标执行随机访问
    const string hexdigits = "0123456789ABCDEF";
    cout << "请输入 0~15 范围内的数字, 用空格分隔, 点击回车键输入完成: " << endl;
    string result;
    string::size_type n;
    while (cin >> n)
    {
        if (n < hexdigits.size())
            result += hexdigits[n];
    }
    cout << "Ur hex number is: 0x" << result << endl;

    return 0;
}
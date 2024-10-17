#include <iostream>
#include <initializer_list>
using namespace std;


/**
 * 处理命令行选项
 * 
 * int main(int argc, char *argv[]){}
 * // 等价于
 * int main(int argc, char** argv){}
 * 
 * 第二个形参 argv 是一个数组，它的元素是指向C风格字符串的指针;
 * 第一个形参 argc 表示数组中字符串的数量。
 * 
 * 当使用 argv 中的实参时，一定要记得可选的实参从 argv[1] 开始；
 * argv[0] 保存程序的名字，而非用户输入。
 */

/*

ex 6.25
编写一个 main 函数，令其接受两个实参。把实参的内容连接成一个 string 对象并输出

int main(int argc, char** argv)
{
    if (argc == 1)
    {
        cout << "请输入两个参数后运行程序" << endl;
        return 1;
    }

    string s1 = argv[1], s2 = argv[2];
    cout << "参数拼接结果: " << s1 + s2 << endl;

    return 0;
}

*/

/** 编写一个函数，它的参数是initializer list<int>类型的对象，函数的功能是计算列表中所有元素的和 */
int sum(initializer_list<int> il)
{
    int sum = 0;

    for (auto i : il)
        sum += i;

    return sum;
}



int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        cout << "请输入参数后运行程序" << endl;
        return 1;
    }

    string s;

    for (int i = 1; i < argc; i++)
       s += string(argv[i]) + " ";
    cout << s << endl;
    
    /** ex 6.27
     * 
     * 编写一个函数，它的参数是initializer list<int>类型的对象，
     * 函数的功能是计算列表中所有元素的和。
     */
    initializer_list<int> il{1, 2, 3, 4, 6, 7, 8, 99, 28};
    cout << sum(il) << endl;

    return 0;
}
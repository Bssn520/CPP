#include <iostream>
#include <vector>
#include <string>

using namespace std;
/**
 * 和大多数语言一样，C++提供了条件执行语句、重复执行相同代码的循环语句和用于中断当前控制流的跳转语句。
 * 
 */

int main()
{
    /**
     * 1. 空语句
     * 
     * 空语句是最简单的语句, 空语句中只有一个单独的分号。
     * 
     * 常见情况: 当循环的全部工作在条件部分就可以完成时，我们通常会用到空语句。
     */
    // 循环读取用户输入, 直至输入不为真或用户输入 q 退出
//  while (cin >> s && s != 'q')
        ;   // 空语句

    /**
     * 复合语句
     * 
     * 复合语句是指用花括号括起来的(可能为空的)语句和声明的序列，复合语句也被称为块。
     * 一个块就是一个作用域。块不以分号作为结束。
     * 
     * 空块: 内部没有任何语句的一对花括号，空块的作用等价于空语句。
     */
    

    /**
     * 2. 语句作用域
     * 
     * 可以在if、switch、while 和 for 语句的控制结构内定义变量。
     * 定义在控制结构当中的变量只在相应语句的内部可见，一旦语句结束，变量也就超出其作用范围了。
     * 
     */


    /**
     * 3. 条件语句
     * 
     * C++提供了两种按条件执行的语句:
     * if语句: 根据条件决定控制流；
     * switch: 计算一个表达式的值, 然后根据这个值从几条执行路径中选择一条。
     * 
     */

    /**
     * if 语句
     * 
     * if
     * 
     * if else
     * 
     * 嵌套 if
     * 
     * 悬垂 else: 
     * 当一个if语向嵌套在另一个i语句内部时，很可能if 分支会多于else 分支。
     * 就C++而言, 它规定 e1se 与离它最近的尚未匹配的if匹配，从而消除了程序的二义性。
     * 此时应该使用花括号控制执行路径。
     */

    vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
    int grade = 0;
    cout <<  "请输入待查询成绩(输入-1退出): ";

    // 成绩分级程序
    while (cin >> grade)
    {
        // 如果用户输入-1则退出循环
        if (grade == -1)
            break;
        
        string letterGrade;
        if (grade < 60)
        {
            letterGrade = scores[0];
        }
        else
        {
            letterGrade = scores[(grade - 50) / 10];

            if (grade != 100)
            {
                if (grade % 10 > 7)
                    letterGrade += "+";
                else if (grade % 10 < 3)
                    letterGrade += "-";
            }
        }
        cout << "分级: " << letterGrade << endl;
    }

    // 用条件运算符改写
    cout <<  "请输入待查询成绩(输入-1退出): ";
    while (cin >> grade)
    {
        // 如果用户输入-1则退出循环
        if (grade == -1)
            break;
        
        string letterGrade = (grade < 60) ? scores[0] : scores[(grade - 50) / 10];

        letterGrade += (grade == 100 || grade < 60)
                        ? ""
                        : (grade % 10 > 7) ? "+" : (grade % 10 < 3) ? "-" : "";
        cout << "分级: " << letterGrade << endl;
    }
    
    /**
     * switch语句
     * 
     * switch 语句提供了一条便利的途径使得我们能够在若干固定选项中做出选择。
     * 
     * case标签必须是整形常量表达式。
     * 
     * default标签: 如果没有任何一个 case 标签能匹配上switch表达式的值，程序将执行紧跟在 default 标签后面的语句。
     * 
     */
    unsigned vowelCnt = 0;
    char cc;
    cout <<  "请输入待统计字符(输入q退出): ";
    while (cin >> cc)
    {
        // 如果用户输入 q 则退出循环
        if (cc == 'q')
            break;

        switch (cc)
        {
            /**
             * 与下面这种形式是等价的:
             * case 'a': case 'e': case 'i': case 'o': case 'u':
             *     ++vowelCnt;
             *     break;
             */
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                ++vowelCnt;
                break;
            default:
                cout << "无匹配" << endl;
                break;
        }
    }
    cout << "统计值: " << vowelCnt << endl;

    /**
     * switch内部的变量的定义
     * 
     * 如果跳过的switch分之内含有变量的定义怎么办?
     * 答案是：如果在某处一个带有初值的变量位于作用域之外，在另一处该变量位于作用域之内，则从前一处跳转到后一处的行为是非法行为。
     * 
     * 错误:
     * 因为程序的执行流程可能绕开下面的初始化语句，所以该switc语句不合法
     * case true:
     *      string file_name;        // 错误: 绕过了一个隐式初始化的变量
     *      int ival = 0;            // 错误: 绕过了一个显式初始化的变量
     *      int jval;                // 正确: 因为jval没有初始化
     *      break;
     * case false:
     *      // 正确: javl虽然在作用域内，但是它没有被初始化
     *      jval = next_num();      // 正确: 给jval赋一个值
     *      if (file_name.empty())  // file_name在作用域内，但是没有被初始化
     * 
     * 如果要为某个case分支定义并初始化一个变量，应该将定义写在块内:
     * case true:
     *      {
     *          // 正确: 声明位于语句块内部
     *          string file_name = get_file_name()
     *      }        
     *      break;
     * case false:
     *      if (file_name.empty()); // 错误: file_name不在作用域内
     * 
     */

    /**
     * ex 5.9:
     * 
     * 编写一段程序，使用一系列i王语句统计从 cin 读入的文本中有多少元音字母。
     */
    char ch;
    unsigned vowelCnt2 = 0;
    cout <<  "请输入待统计字符(输入q退出): ";

    while (cin >> ch)
    {
        if (ch == 'q')
        {
            cout << "退出循环" << endl;
            break;
        }
        if (ch == 'a')
        {
            ++vowelCnt2;
            continue;
        }
        if (ch == 'e')
        {
            ++vowelCnt2;
            continue;
        }
        if (ch == 'i')
        {
            ++vowelCnt2;
            continue;
        }
        if (ch == 'o')
        {
            ++vowelCnt2;
            continue;
        }
        if (ch == 'u')
        {
            ++vowelCnt2;
            continue;
        }
    }
    cout << "统计值: " << vowelCnt2 << endl;

    /**
     * ex 5.10
     * 
     * 既统计小写字母也统计大写字母
     */
    unsigned vowelCnt3 = 0;
    char c3;
    cout <<  "请输入待统计字符(输入q退出): ";
    while (cin >> c3)
    {
        // 如果用户输入 q 则退出循环
        if (c3 == 'q')
            break;

        switch (c3)
        {
            /**
             * 与下面这种形式是等价的:
             * case 'a': case 'e': case 'i': case 'o': case 'u':
             *     ++vowelCnt;
             *     break;
             */
            case 'a':
            case 'A':
                ++vowelCnt3;
                break;
            case 'e':
            case 'E':
                ++vowelCnt3;
                break;
            case 'i':
            case 'I':
                ++vowelCnt3;
                break;
            case 'o':
            case 'O':
                ++vowelCnt3;
                break;
            case 'u':
            case 'U':
                ++vowelCnt3;
                break;
            default:
                cout << "无匹配" << endl;
                break;
        }
    }
    cout << "统计值: " << vowelCnt3 << endl;
    
    /**
     * ex 5.11
     * 
     * 修改统计元音字母的程序，使其也能统计空格、制表符和换行符的数量。
     */
    unsigned vowelCnt4 = 0, specialCnt = 0;
    char c4;
    cout <<  "请输入待统计字符(输入q退出): ";
    while (cin >> noskipws >> c4)
    {
        // 如果用户输入 q 则退出循环
        if (c4 == 'q')
            break;

        switch (c4)
        {
            /**
             * 与下面这种形式是等价的:
             * case 'a': case 'e': case 'i': case 'o': case 'u':
             *     ++vowelCnt;
             *     break;
             */
            case 'a':
            case 'A':
                ++vowelCnt4;
                break;
            case 'e':
            case 'E':
                ++vowelCnt4;
                break;
            case 'i':
            case 'I':
                ++vowelCnt4;
                break;
            case 'o':
            case 'O':
                ++vowelCnt4;
                break;
            case 'u':
            case 'U':
                ++vowelCnt4;
                break;
            case '\t':
            case '\v':
            case '\n':
                ++specialCnt;
                break;
            default:
                cout << "无匹配" << endl;
                break;
        }
    }
    cout << "元音字母统计值: " << vowelCnt4 << endl
         << "制表 空格 换行 统计值: " << specialCnt << endl;
    
    /**
     * ex 5.12
     * 
     * 修改统计元音字母的程序，使其能统计以下含有两个字符的字符序列的数量: ff, fl, fi
     */
    unsigned ffCnt = 0, flCnt = 0, fiCnt = 0;
    char c, preChar = '\0';
    cout <<  "请输入待统计字符(输入q退出): ";
    while (cin.get(c))
    {
        if (c == 'q')
            break;

        switch (c)
        {
            case 'f':
                if (preChar == 'f')
                    ++ffCnt;
                break;
            case 'l':
                if (preChar == 'f')
                    ++flCnt;
                break;
            case 'i':
                if (preChar == 'f')
                    ++fiCnt;
                break;
        }
        preChar = c;
    }
    cout << "ff count: " << ffCnt << endl
         << "fl count: " << flCnt << endl
         << "fi count: " << fiCnt << endl;

    return 0;
}
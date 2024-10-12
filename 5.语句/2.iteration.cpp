#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <stdexcept>
using namespace std;






int main()
{
    /**
     * ex 5.14
     * 
     * 输入若干个字符串，并统计出连续出现次数最多的字符串。
     */
    string s, pres, max_s;
    unsigned cnt = 1, maxCnt = 1;
    cout << "输入若干个字符串，并统计出连续出现次数最多的字符串(q退出): " << endl;
    while (cin >> s)
    {
        if (s == "q")
            break;

        if (s == pres)
            ++cnt;
        else
        {
            if (cnt > maxCnt)
            {
                maxCnt = cnt;
                max_s = pres;
            }
            cnt = 1;
        }
        pres = s;
    }
    if (cnt > maxCnt)
    {
        maxCnt = cnt;
        max_s = pres;
    }
    (maxCnt > 1) ? (cout << max_s << ":" << maxCnt << endl) : (cout << "no repeat" << endl);


    /**
     * for 循环
     * 
     * for (init-statemen; condition; expersion)
     *      statement;
     * 
     */

    /**
     * 传统for语句的执行流程
     * 
     * for (decltype(s.size()) index = 0;
     *      index != s.size() && !isspace(s[index]); ++index)
     *      s[index] = toupper(s[index]);
     * 
     * 1. 循环开始，先执行一次 init-statement, 此时 index被初始化为0；
     * 2. 接下来判断condition，如果 index 不等于 s.size()而且在s[index]位置的字符不是空白，则执行for循环体内的内容。
     * 否则，终止循环。如果第一次迭代时条件就为假，for循环体一次也不会执行。
     * 3. 如果条件为真，执行循环体。此例中，for循环体将s[index]位置的字符改写成大写形式。
     * 4. 最后执行expression。此例中，将index的值加1。
     * 
     */

    /**
     * for语句头中的多重定义
     * 
     * init-statement可以定义多个对象。但是只能有一条声明语句，所以，所有变量的基础类型必须相同。
     * for (decltype(v.size()) i = 0, sz = v.size(); i != sz; ++i)
     *      v.push_back(v[i]);
     * 
     */

    /**
     * 省略for语句头的某些部分
     * 
     * for 语句能省略掉 init-statement, condition 和 expression中的任何一个(或者全部)。
     * 
     * 省略 init-statement: 无需初始化。
     * 省略 condition: 等价于在条件部分写了一个true, 此时在循环体内必须有语句负责退出循环。
     * 省略 expression: 在这样的循环中就要求条件部分或者循环体必须改变迭代变量的值。
     * vector<int> v;
     * for (int i; cin >> i;)
     *      v.push_back(i);
     */

    /**
     * ex 5.17
     * 
     * 假设有两个包含整数的 vector 对象，编写一段程序，检验其中一个 vector 对象是否是另一个的前缀。
     */
    vector<int> iv0{3, 7, 9};
    vector<int> iv1{0, 1, 1, 2};
    vector<int> iv2{0, 1, 1, 2, 3, 5, 8};

    for (decltype(iv1.size()) i = 0, sz1 = iv1.size(), sz2 = iv2.size();
                    i != sz1 && i != sz2; ++i)
    {
        if (iv1[i] != iv2[i])
        {
            cout << "false" << endl;
            break;
        }
    }
    cout << "true" << endl;
    

    /**
     * 范围for语句
     * 
     * for (declaration : expression)
     *      statement;
     * 
     * expression 表示的必须是一个序列，比如用花括号括起来的初始值列表、数组 或者 vector、string 等类型的对象，这些对象的共同特点是拥有能返回迭代器的begin 和 end 成员。
     * 
     * 每次迭代都会重新定义循环控制变量，并将其初始化成序列中的下一个值，之后才会执行statement。
     * 
     * 不能通过范围 for 语句增加 vector 对象（或者其他容器）的元素:
     * 在范围for语句内，预存了end()的值，一旦在序列中添加或删除元素，end函数的值就可能变得无效。
     */


    /**
     * do while 语句
     * 
     * do while 语句和while 语句非常相似，唯一的区别是，do while 语句先执行循环体后检查条件,
     * 不管条件的值如何，我们都至少执行一次循环。
     * 
     * 注意:
     * 在do 语句中，求 condition 的值之前首先执行一次 statement,condition 不能为空。
     * 如果 condition 的值为假，循环终止；否则，重复循环过程。
     * condition 使用的变量必须定义在循环体之外:
     * 错误:
     * do
     * {
     *      int ival = get_response();
     * } while (ival);  // 错误：condition使用的变量必须定义在循环体外
     * 
     * 
     */
    string rsp;
    do
    {
        cout << "please enter two numbers: ";
        int val1 = 0, val2 = 0;
        cin >> val1 >> val2;
        cout << "The sum of " << val1 << " and " << val2
            << " = " << val1 + val2 << "\n\n"
            << "More? Enter yes or no: ";
        cin >> rsp;
    } while (!rsp.empty() && rsp[0] != 'n');    // 注意不能在变量声明放在条件部分
    

    /**
     * 跳转语句
     * 
     * 跳转语句中断当前的执行过程。
     * 
     * 1. break
     * 2. continue
     * 3. goto
     * 4. return
     * 
     */

    /**
     * 1. break
     * 
     * break 语句负责终止离它最近的while、do while、for 或switch 语句，并从这些语句之后的第一条语句开始继续执行。
     * 
     * break 语句只能出现在迭代语句或者 switch 语句内部（包括嵌套在此类循环里的 语句或块的内部）。break 语句的作用范围仅限于最近的循环或者 switch。
     * 
     */

    /**
     * 2. continue
     * 
     * continue 语句（continue statement）终止最近的循环中的当前迭代并立即开始下一次迭代。
     * continue 语句只能出现在 for、while 和do while 循环的内部，或者嵌套在此类循环里的语句或块的内部。
     * 和 break 语句类似的是，出现在嵌套循环中的 continue 语句也仅作用于离它最近的循环。
     * 和 break 语句不同的是，只有当switch 语句嵌套在迭代语句内部时， 才能在 switch 里使用 continue。
     * 
     */

    /**
     * 3. goto
     * 
     * goto 语句的作用是从goto语句无条件跳转到同一函数内的另一条语句。
     * 
     * 语法形式:
     * goto label;
     * 其中，label是用于标识一条语句的标示符。
     * 
     * 带标签语句 是一种特殊的语句:
     * end: return;
     * 
     */


    /**
     * try语句块和异常处理
     * 
     * 在C++语言中，异常处理包括:
     * 1. throw 表达式, 异常检测部分使用throw表达式来表示它遇到了无法处理的问题。我们说throw引发了异常。
     * 2. try语句块，异常处理部分使用try语句块处理异常。try语句块以关键字try开始，并以一个或多个catch子句结束。
     * try语句块中代码抛出的异常通常会被某个catch子句处理。因为catch子句处理异常，所以它们也被称作异常处理代码。
     * 3. 一套 异常类, 用于在throw表达式和相关的catch子句之间传递异常的具体信息。
     * 
     */

    /**
     * <stdexcept> 定义的异常类
     * 
     * exception            最常见的问题
     * runtime_error        只有在运行时才能检测出的问题
     * range_error          运行时错误: 生成的结果超出了有意义的值域范围
     * overflow_error       运行时错误: 计算上溢
     * underflow_error      运行时错误: 计算下溢
     * logic_error          程序逻辑错误
     * domain_error         逻辑错误: 参数对应的结果值不存在
     * invalid_argument     逻辑错误: 无效参数
     * length_error         逻辑错误: 试图创建一个超出该类型最大长度的对象
     * out_of_range         逻辑错误: 使用一个超出有效范围的值
     * 
     */

    /**
     * throw 表达式
     * 
     * 类型 runtime_error是标准库异常类型的一种，定义在stdexcept头文件中。
     * 使用时必须初始化runtime_error的对象，提供给它一个string对象或C风格字符串。
     * 
     */
    int i1 = 0, i2 = 0;
    cout << "请输入两个相等的数: ";
    cin >> i1 >> i2;
    if (i1 != i2)
        throw runtime_error("错误: 两个数必须相等!");
    cout << "成功输入数据" << endl;

    /**
     * try语句块
     * 
     */
    int i3 = 0, i4 = 0;
    cout << "请输入两个相等的数: ";
    try
    {
        cin >> i3 >> i4;
        if (i3 != i4)
            throw runtime_error("错误: 两个数必须相等!");
    }
    catch(runtime_error e)
    {
        cerr << e.what() << '\n';
    }
    cout << "成功输入数据" << endl;




    /**
     * ex 5.25
     * 
     */
    double x = 0, y = 0;
    while (cin >> x >> y)
    {
        try
        {
            // 如果输入非法
            if (y == 0)
                throw runtime_error("错误: 第二个数不能为0");
            // 输入合法
            cout << "两数之商为: " << (x / y) << endl;
        }
        catch(runtime_error err)
        {
            // 捕获错误并询问用户是否继续
            cerr << err.what() << '\n'
                 << "再次输入? 输入 y 或 n: ";
            
            char c;
            cin >> c;
            if (!cin || c == 'n')   // 如果用户输入 'n' 则退出循环
                break;
        }
    }

    return 0;
}
#include <iostream>
#include <string>
using std::string;
using std::cerr;
using std::endl;

/**
 * 本节我们介绍三种函数相关的语言特性，这些特性对大多数程序都有用，它们分别是： 
 * 1. 默认实参
 * 2. 内联函数
 * 3. constexpr 函数
 * 4. 以及在程序调试过程中常用的一些功能。
 */


/**
 * 1. 默认实参
 * 
 * 某些函数有这样一种形参，在函数的很多次调用中它们都被赋予一个相同的值。
 * 此时，我们把这个反复出现的值称为函数的默认实参（default argument）。
 * 调用含有默认实参的函数时，可以包含该实参，也可以省略该实参。
 * 
 * typedef string::size_type sz;
 * string screen(sz ht = 24, sz wid = 80, char bg = ' ');
 * 
 * 我们可以使用 0, 1, 2, 3个实参调用该函数:
 * string window;                   
 * window = screen();               // 等价于 screen(24, 80, ' ')
 * window = screen(66);             // 等价于 screen(66, 80, ' ')
 * window = screen(66, 256);        // 等价于...
 * window = screen(66, 256, '#');   // 等价于...
 * 
 * window = screen(, , '?');        // 错误：只能省略尾部的实参
 * // '?'对应的十六进制数是Ox3F，也就是十进制数的63，所以该调用把值63传给了形参height
 * window = screen('?');            // 等价于调用screen('?', 80, ' ');
 * 
 */

/**
 * 默认实参声明
 * 
 * 通常，应该在函数声明中指定默认实参，并将该声明放在合适的头文件中。
 * 
 * 假如给定:
 * string screen(sz, sz, char = ' ');
 * // 我们不能修改一个已经存在的默认值:
 * string screen(sz, sz, char = '?');       // 错误: 重复声明
 * // 但是可一添加默认实参:
 * string screen(sz = 24, sz = 80, char);   // 正确: 添加默认实参
 * 
 */

/**
 * 默认实参初始值
 * 
 * 局部变量不能作为默认实参。除此之外，只要表达式的类型能转换成形参所需的类型，该表达式就能作为默认实参。
 * 
 * // wd, def, ht 的声明必须出现在函数之外
 * sz wd = 80;
 * char def = ' ';
 * sz ht();
 * string screen(sz = ht(), sz = wd, char = def);
 * string window = screen();    // 等价于 screen(ht(), 80, ' ');
 * 
 * void f2()
 * {
 *      def = '*';
 *      sz wd = 100;
 *      window = screen();
 * }
 * 
 * 我们在函数f2内部改变了 def 的值，所以对 screen 的调用将会传递这个更新过的值。 
 * 另一方面，虽然我们的函数还声明了一个局部变量用于隐藏外层的 wd，但是该局部变量与传递给 screen 的默认实参没有任何关系。
 * 
 */


/**
 * 2. 内联函数和constexpr函数
 * 
 * 内联函数可避免函数调用的开销。
 * 
 * 对于函数:
 * const string &shorterString(const string &s1, const string &s2)
 * {
 *      return s1.size() <= s2.size() ? s1 : s2;
 * }
 * 
 * 如果将上述函数改为内联函数, cout << shorterString(s1, s2) << endl 将被展开为:
 * cout << (s1.size() <= s2.size() ? s1 : s2) << endl;
 * 
 * 在 shorterstring 函数的返回类型前面加上关键字 inline，这样就可以将它声明成内联函数了：
 * inline const string &shorterString(const string &s1, const string &s2)
 * {
 *      return s1.size() <= s2.size() ? s1 : s2;
 * }
 * 
 * 内联说明只是向编译器发出的一个请求，编译器可以选择忽略这个请求。
 * 一般来说，内联机制用于优化规模较小、流程直接、频繁调用的函数。
 * 很多编译器都不支持内联递归函数，而且一个75行的函数也不大可能在调用点内联地展开。
 * 
 */

/**
 * constexpr 函数
 * 
 * constexpr 函数是指能用于常量表达式的函数。定义 constexpr 函数的方法与其他函数类似，不过要遵循几项约定：
 * 1. 函数的返回类型及所有形参的类型都得是字面值类型
 * 2. 函数体中必须 有且只有一条return语句
 * 
 * 
 */


/**
 * 3. 调试
 * 
 * 为了方便有选择地执行调试代码。程序可以包含一些用于调试的代码，但是这些代码只在开发程序时使用。当应用程序编写完成准备发布时，要先屏蔽掉调试代码。
 * 这种方法用到两项预处理功能：assert 和 NDEBUG。
 * 
 */

/**
 * assert预处理宏
 * 
 * assert是一种预处理宏。使用一个表达式作为它的条件:
 * assert(expr);
 * 首先对expr求值, 如果表达式为假(0), assert输出信息并终止程序的执行; 如果表达式为真(非0), assert什么也不做。
 * 
 * assert宏定义在 cassert 头文件中。预处理名字由预处理器而非编译器管理，因此我们应该使用assert而不是std::assert, 也不需要为assert提供using声明。
 * 
 * assert宏常用于检查 "不能发生" 的条件。例如，一个对输入文本进行操作的程序可能要求所有给定单词的长度都大于某个阈值。
 * 此时，程序可以包含一条如下语句: assert(word.size() > shreshold);
 * 
 */

/**
 * NDEBUG 预处理变量
 * 
 * assert的行为依赖于一个名为 NDEBUG 的预处理变量的状态。如果定义了 NDEBUG 则assert什么也不做。默认状态下没有定义 NDEBUG，此时assert将执行运行时检查。
 * 所以，我们可以使用一个 #define 语句定义 NDEBUG 从而关闭调试状态:
 * g++ -std=c++11 main.cpp -o main -D NDEBUG
 * 
 */

/**
 * 程序调试变量
 * 
 */
#define THRESHOLD 3
void debugTest(string s)
{
    if (s.size() < THRESHOLD)
    {
        cerr << "Error: " << __FILE__
             << " : in function " << __func__
             << " at line " << __LINE__ << endl
             << "    Compiled on " << __DATE__
             << " at " << __TIME__ << endl
             << "    Word read was \"" << s
             << "\": Length too short" << endl;
    }
}


/**
 * 函数匹配
 * 
 * void f();
 * void f(int);
 * void f(int, int);
 * void f(double, double = 3.14);
 * f(5.6);      // 调用 void f(double, double);
 * 
 * 1. 确定候选函数
 * 条件: 
 * (1). 与被调用函数同名
 * (2). 其声明在调用点可见
 * 在上面的例子中, 有4个名为 f 的候选函数。
 * 
 * 2. 确定可行函数
 * 条件:
 * (1). 其形参数量与本次调用提供的实参数量相等
 * (2). 每个实参的类型与对应的形参类型相同, 或者能转换成形参的类型
 * 在上面的例子中，可见 可行函数有 f(int) 与 f(double, double)
 * 
 * 3. 寻找最佳匹配
 * 
 * 在这一过程中，逐一检查函数调用提供的实参，寻找形参类型与实参类型最匹配的那个可行函数。
 * 
 * 在上面的例子中, 调用只提供了一个（显式的）实参，它的类型是 double。
 * 如果调用 f(int），实参将不得不从double 转换成int。另一个可行函数 f(double,double) 则与实参精确匹配。
 * 精确匹配比需要类型转换的匹配更好，编译器把 f(5.6) 解析成对含有两个 double 形参的函数的调用，并使用默认值填补我们未提供的第二个实参。
 * 
 */

/**
 * 实参类型转换
 * 
 * 为了确定最佳匹配，编译器将实参类型到形参类型的转换划分成几个等级，具体排序如下所示：
 * 1. 精确匹配
 *      (1). 实参类型和形参类型相同
 *      (2). 实参从数组类型或函数类型转换成对应的指针类型
 *      (3). 向实参添加项层 const 或者从实参中删除顶层 const
 * 2. 通过 const 转换实现的匹配
 * 3. 通过类型提升实现的匹配
 * 4. 通过算术类型转换或指针转换实现的匹配
 * 5. 通过类类型转换实现的匹配
 * 
 * 
 * 需要类型提升和算术类型转换的匹配
 * 
 * void ff(int);
 * void ff(short);
 * ff('a');     // char 提升为int, 调用 ff(int)
 * 'a' 转换为 int 属于 "通过类型提升实现的匹配"
 * 
 * void manip(long);
 * void manip(float);
 * manip(3.14);     // 错误：二义性调用
 * 字面值3.14的类型是 double，它既能转换成 1ong也能转换成f1oat。因为存在两种可能的算数类型转换，所以该调用具有二义性。
 * 
 * 
 * 函数匹配和 const 实参
 * 
 * 如果重载函数的区别在于它们的引用类型的形参是否引用了 const，或者指针类型形参是否指向 const，则当调用发生时编译器通过实参是否是常量来决定选择哪个函数：
 * Record lookup(Account&);         // 函数的参数是Account的引用
 * Record lookup(const Account&);   // 函数的参数是一个常量引用
 * const Account a;
 * Account b;
 * 
 * lookup(a);                       // 调用 lookup(const Account&);
 * lookup(b);                       // 调用 lookup(Account&);
 * 
 */


int main(int argc, char* agrv[])
{
    // 程序调试变量函数测试
    string s("he");
    debugTest(s);

    return 0;
}

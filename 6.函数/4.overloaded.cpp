#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

/**
 * 函数重载
 * 
 * 如果同一作用域内的几个函数名字相同但形参列表不同，我们称之为重载函数。
 * 重载函数接受的形参类型不一样，但是执行的操作非常类似。当调用这些函数时，编译器会根据传递的实参类型推断想要的是哪个函数。
 * 
 */

/**
 * 定义重载函数
 * 
 * 要求:
 * 1. 对于重载的函数来说，在形参数量或形参类型上有所不同。
 * 2. 不允许两个函数除了返回类型外其他所有要素都相同。
 * 
 */

/**
 * 判断两个形参的类型是否相异
 * 
 * 1. 省略了形参名字
 * Record lookup(const Account &acct);
 * Record lookup(const Account&);       // 与上面那条函数声明是等价的
 * 
 * 2. 使用了别名
 * typedef Phone Telno;
 * Record lookup(const Phone&);
 * Record lookup(cosnt Telno&);         // 与上面那条函数声明是等价的
 * 
 */

/**
 * 重载和const形参
 * 
 * 顶层const不影响传入函数的对象, 一个拥有顶层const的形参无法和另一个没有顶层const的形参分开来:
 * Record lookup(Phone);
 * Record lookup(const Phone);      // 与上面那条函数声明是等价的
 * 
 * Record lookup(Phone*);
 * Record loopup(Phone* const);     // 与上面那条函数声明是等价的
 * 
 * 如果形参时某种类型的指针或引用, 则通过区分其指向的是常量对象还是非常量对象来实现函数重载，此时的const是底层的:
 * Record lookup(Account&);             // 函数作用于Account的引用
 * Record lookup(const Account&);       // 新函数，作用于常量引用
 * 
 * Record lookup(Account*);             // 新函数，作用于指向Account的指针
 * Record lookup(const Account*);       // 新函数，作用于指向常量的指针
 * 
 */

/**
 * const_cast和重载
 * 
 * const_cast<new_type>(expression), 使用 const_cast 来移除或添加 const 限定符。
 * 
 * 
 * 
 * 
 */
const string &shorterString(const string &s1, const string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}

string &shorterString(string &s1, string &s2)
{
    auto &r = shorterString(const_cast<const string&>(s1),
                            const_cast<const string&>(s2));
    return const_cast<string&>(r);
}

/**
 * 调用重载的函数
 * 
 * 定义了一组重载函数后，我们需要以合理的实参调用它们。
 * 函数匹配（function matching）是指一个过程，在这个过程中我们把函数调用与一组重载函数中的某一个关联起来，函数匹配也叫做重载确定（overload resolution）。
 * 编译器首先将调用的实参与重载集 合中每一个函数的形参进行比较，然后根据比较的结果决定到底调用哪个函数。
 * 
 * 现在我们需要掌握的是，当调用重载函数时有三种可能的结果：
 * 1. 编译器找到一个与实参最佳匹配 （best match）的函数，并生成调用该函数的代码。
 * 2. 找不到任何一个函数与调用的实参匹配，此时编译器发出无匹配（no match）的错误信息。
 * 3. 有多于一个函数可以匹配，但是每一个都不是明显的最佳选择。此时也将发生错误， 称为二义性调用。
 * 
 */

/**
 * 重载与作用域
 * 
 * 如果我们在内层作用域中声明名字，它将隐藏外层作用域中声明的同名实体。在不同的作用域中无法重载函数名：
 * 
 * string read();
 * void print(const string &);
 * void print(double);      // 重载print函数
 * void fooBar(int ival)
 * {
 *      bool read = false;  // 新作用域: 隐藏了外层的read函数
 *      string s = read();  // 错误: read是一个布尔值，而非函数
 *      void print(int);    // 新作用域：隐藏了之前的print
 *      print("Value: ");   // 错误：print(const string &)被隐藏掉了
 *      print(ival);        // 正确：当前print(int)可见
 *      print(3.14);        // 正确: 调用print(int); print(double)被隐藏掉了
 * }
 * 
 * 在fooBar内声明的 print(int)隐藏了之前两个print函数, 因此只有print(int)是可用的。
 * 
 * 当我们调用print函数时，编译器首先寻找对该函数名的声明，找到的是接受int 值的那个局部声明。
 * 一旦在当前作用域中找到了所需的名字，编译器就会忽略掉外层作用域中的同名实体。剩下的工作就是检查函数调用是否有效了。
 * 
 * 在C++语言中，名字查找发生在类型检查之前。
 */
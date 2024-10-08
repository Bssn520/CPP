#include <iostream>
using namespace std;

/**
 * 表达式
 * 
 * 表达式由一个或多个运算对象（operand）组成，对表达式求值将得到一个结果（result）。
 * 字面值和变量是最简单的表达式（expression），其结果就是字面值和变量的值。
 * 把一个运 算符（operator）和一个或多个运算对象组合起来可以生成较复杂的表达式。
 */

/**
 * 1. 基本概念
 * 
 * 作用于一个运算对象的运算符是一元运算符，如取地址符（&）和解引用符（*）；
 * 作用于两个运算 对象的运算符是二元运算符，如相等运算符（==）和乘法运算符（*）。
 * 
 * (1). 重载运算符
 * C++语言定义了运算符作用于内置类型和复合类型的运算对象时所执行的操作。
 * 当运算符作用于类类型的运算对象时，用户可以自行定义其含义。
 * 因为这种自定义的过程事实上是为已存在的运算符赋予了另外一层含义，所以称之为重载运算符。
 * (2). 左值和右值
 * 
 */

/**
 * 1. 逻辑和关系运算符
 * 
 * 逻辑与运算符     &&
 * 逻辑或运算符     ||
 * 
 * 对于逻辑与运算符（&&）来说，当且仅当两个运算对象都为真时结果真；
 * 对于逻辑与运算符来说，当且仅当左侧运算对象为真时才对右侧运算对象求值。
 * 
 * 对于逻辑或运算符（||）来说，只要两个运算对象中的一个为真结果就为真。
 * 对于逻辑或运算符来说，当且仅当左侧运算对象为假时才对右侧运算对象求值。
 * 
 * 
 * 2. 递增递减运算符
 * 
 * 递增和递减运算符有两种形式：
 * 前置版本和后置版本。前置形式的运算符首先将运算对象加1（或减1），然后将改变后的对象作为求值结果。
 * 后置版本也会将运算对象加1（或减 1），但是求值结果是运算对象改变之前那个值的副本。
 * 
 * 前置版本的递增运算符避免了不必要的工作，它把值加1后直接返回改变了的运算对象。
 * 与之相比，后置版本需要将原始值存储下来以便于返回这个未修改的内容。
 * 如果我们不需要修改前的值，那么后置版本的操作就是一种浪费。
 * 
 * 建议：除非必须，否则不用递增递减运算符的后置版本。
 * 
 * 
 * 3. 条件运算符
 * 
 * cond ? expr1 : expr2;
 * 条件运算符的执行过程是：首先求cond 的值，如果条件为真对 expr1 求值 并返回该值，否则对 expr2 求值并返回该值。
 * 
 * 
 * 4. 位运算符
 * 运算符    功能         用法
 * ～       位求反      ~ expr
 * <<       左移        expr1 << expr2
 * >>       右移        expr1 >> expr2
 * &        位与        expr1 & expr2
 * ^        位异或      expr1 ^ expr2
 * |        位或        expr1 | expr2
 * 
 * 移位运算符的优先级不高不低, 比算数运算符低，比关系运算符、赋值运算符和条件运算符的优先级高。
 * cout << "hi" << "there" << endl;
 * 等价于
 * ((cout << "hi") << "there") << endl;
 * 
 * cout << (10 < 42); 不可写作 cout << 10 < 42;
 * 
 * 
 * 5. sizeof()运算符
 * 
 * sizeof 运算符返回一条表达式或一个类型名字所占的字节数。sizeof 运算符满足右结合律，其所得的值是一个 size_t类型。
 * 
 * sizeof(type);
 * sizeof expr;     // 返回表达式结果类型的大小。
 * 
 * 在sizeof 的运算对象中解引用一个无效指针仍然是一种安全的行为，因为指针实际上并没有被真正使用。
 * sizeof 不需要真的解引用指针也能知道它所指对象的类型。
 * 
 * 对 char 或者类型为 char 的表达式执行 sizeof 运算，结果得1。 
 * 对引用类型执行 sizeof 运算得到被引用对象所占空间的大小。 
 * 对指针执行 sizeof运算得到指针本身所占空间的大小。
 * 对解引用指针执行 sizeof 运算得到指针指向的对象所占空间的大小，指针不需有效。
 * 对数组执行 sizeof运算得到整个数组所占空间的大小，等价于对数组中所有的元 素各执行一次 sizeof运算并将所得结果求和。注意，sizeof 运算不会把数组转换成指针来处理。
 * 对 string对象或 vector 对象执行 sizeof 运算只返回该类型固定部分的大小，不会计算对象中的元素占用了多少空间。
 * 
 * 
 * 6. 逗号运算符
 * 
 * 对于逗号运算符来说，首先对左侧的表达式求值，然后将求值结果丢弃掉。
 * 逗号运算符真正的结果是右侧表达式的值。如果右侧运算对象是左值，那么最终的求值结果也是左值。
 * 
 * 
 * 7. 显式转换
 * 
 * (1). C 风格转换
 * (type)expression
 * type(expression)
 * 
 * (2). static_cast
 * static_cast<type>(expression)
 * 
 * (3). dynamic_cast
 * dynamic_cast<type>(expression)
 * 
 * (4). const_cast
 * const_cast<type>(expression)
 * 
 * (5). reinterpret_cast
 * reinterpret_cast<type>(expression)
 * 
 * 显式转换的选择:
 * 使用 static_cast 来进行安全的类型转换（基本数据类型之间、类层次结构之间）。
 * 使用 dynamic_cast 来进行类层次中指针或引用的安全转换。
 * 使用 const_cast 来移除或添加 const 限定符。
 * 使用 reinterpret_cast 来进行完全不相关类型之间的转换，但要小心其风险。
 * 避免使用 C 风格转换和函数风格转换，因为它们没有提供类型检查机制，不易维护和理解。
 * 
 */



int main()
{
    cout << 5+10*20/2 << endl;

    int i1 = 0, i2 = 0, j1, j2;
    j1 = ++i1;  // 返回改变后的对象的值
    j2 = i2++;  // 返回对象改变前的那个值的副本
    cout << "前置: " << j1 << endl  // 1
        << "后置: " << j2 << endl;  // 0

    
    /** 
     * ex 4.21:
     * 
     * 编写一段程序，使用条件运算符从 vector<int>中找到哪些元素的值是奇数，然后将这些奇数值翻倍。
     */

    vector<int> iv{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto &i : iv)
    {
        i = (i % 2) ? (i * 2) : i;
    }

    /**
     * ex 4.22:
     * 
     * 将成绩划分为 high(>=90) low pass(>=75 && >90 ) pass(<75 && >=60) fail(<60)
     */
    int score = 78;
    string level = (score >= 90) ? "high"
                                : (score >= 75) ? "low pass"
                                : (score >= 60) ? "pass" : "fail";
    cout << level << endl;
    
    /**
     * 位运算
     * 
     */
    unsigned long ul1 = 3, ul2 = 7;     // 二进制 ul1: 011; ul2: 111
    cout << "位与: " << (ul1 & ul2) << endl     // 二进制: 011
        << "位或: " << (ul1 | ul2) << endl      // 二进制: 111
        << "异或: " << (ul1 ^ ul2) << endl     // 二进制: 100
        << "左移2位: " << (ul1 << 2) << endl;      // 二进制: 1100

    /**
     * sizeof 运算符
     * 
     */
    // void
    cout << "void nullptr_t " << sizeof(nullptr_t) << " bytes" << endl << endl;

    // char
    cout << "char " << sizeof(char) << " bytes" << endl;
    cout << "wchar_t " << sizeof(wchar_t) << " bytes" << endl;
    cout << "char16_t " << sizeof(char16_t) << " bytes" << endl;
    cout << "char32_t " << sizeof(char32_t) << " bytes" << endl << endl;

    // boolean
    cout << "bool " << sizeof(bool) << " bytes" << endl;

    // int
    cout << "short " << sizeof(short) << " bytes" << endl;
    cout << "int " << sizeof(int) << " bytes" << endl;
    cout << "long " << sizeof(long) << " bytes" << endl;
    cout << "long long " << sizeof(long long) << " bytes" << endl << endl;

    // float
    cout << "float " << sizeof(float) << " bytes" << endl;
    cout << "double " << sizeof(double) << " bytes" << endl;
    cout << "long double " << sizeof(long double) << " bytes" << endl << endl;

    // Fixed width integers
    cout << "int8_t " << sizeof(int8_t) << " bytes" << endl;
    cout << "uint8_t " << sizeof(uint8_t) << " bytes" << endl;
    cout << "int16_t " << sizeof(int16_t) << " bytes" << endl;
    cout << "uint16_t " << sizeof(uint16_t) << " bytes" << endl;
    cout << "int32_t " << sizeof(int32_t) << " bytes" << endl;
    cout << "uint32_t " << sizeof(uint32_t) << " bytes" << endl;
    cout << "int64_t " << sizeof(int64_t) << " bytes" << endl;
    cout << "uint64_t " << sizeof(uint64_t) << " bytes" << endl << endl;

    // size_t
    cout << "size_t " << sizeof(size_t) << " bytes" << endl << endl;


    /**
     * ex 4.29
     * 
     */
    int x[10]; int* p = x;
    cout << sizeof(x)/sizeof(*x) << endl;   // 40/4 数组所占的字节数/数组类型int所占的字节数，就是数组的个数；
    cout << sizeof(p)/sizeof(*p) << endl;   // 8/4 指针所占的字节数/int所占的字节数。

    /**
     * ex 4.30
     * 
     */
//  sizeof x + y;       等价于  (sizeof x) + y;
//  sizeof p->mem[1];   等价于  sizeof(p->mem[i]);
//  sizeof a < b;       等价于  (sizeof a) < b;
//  sizeof f();         等价于  sizeof(f())




    return 0;
}
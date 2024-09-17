#include <iostream>
using namespace std;

int main()
{
    /**
     * 类型别名
     * 1. typedef
     * 2. using 别名声明
     */
    // 1. 传统的 typedef
    typedef double wages; // wages是double的同义词
    typedef wages base, *p; // base是double的同义词，p是double*的同义词
    // 2. using
    using ldouble = long double; // ldouble 是 long double的同义词
    // 类型别名指代复合类型
    typedef char* pstr; // pstr 是类型 char* 的别名
    const pstr str = 0; // str 是指向char的常量指针
    const pstr* ps; // ps是一个二级指针，指向一个指向char的常量指针


    /**
     * auto类型说明符
     * 
     * C++11 新标准引入了 auto 类型说明符，用它就能让编译器替我们去分析表达式所属的类型。
     */
    int val1 = 3;
    double val2 = 0.141593;
    auto sum = val1 + val2;
    printf("Value of sum: %f\nSize of sum: %lu\n", sum, sizeof(sum)); // 8
    // 使用auto在一条语句中声明多个变量。
    // 因为一条声明语句只能有一个基本数据类型，所以该语句中所有变量的初始基本数据类型都必须一样:
    auto i = 0, *p2 = &i; // 正确: i是整数, p是整形指针
//  auto sz = 0, pi = 3.14; // 错误: sz和pi的类型不一致

    /**
     * 复合类型、常量和auto
     * 
     * 编译器推断出来的 auto 类型有时候和初始值的类型并不完全一样，
     * 编译器会适当地 改变结果类型使其更符合初始化规则。
     * 
     * auto一般会忽略掉顶层const，保留底层const
     */
    int i = 0;
    const int ci = i, &cr = ci;
    auto b = ci; // b 是一个整数(ci的顶层const特性被忽略掉了)
    auto c = cr; // c 是一个整数(cr是ci的别名，ci本身是一个顶层const)
    auto d = &i; // d 是一个整形指针
    auto e = &ci; // e 是一个指向整数常量的指针(对常量对象取地址是一种底层const)
    // 如果希望推断出的auto类型是一个顶层const，需要明确指出:
    const auto f = ci; // ci的推演类型是int, f是const int

    // 可以将引用的类型设为auto, 此时原来的初始化规则仍然适用:
    auto &g = ci; // g是一个整形常量引用，绑定到ci
//  auto &h = 42; // 错误: 不能将非常量引用绑定字面值
    const auto &j = 42; //正确: 可以为常量引用绑定字面值

    // 符号&和*只从属于某个声明符，而非基本数据类型的一部分，因此初始值必须是同一种类型：
    auto k = ci, &l = i; // k是整数，l是整形引用
    auto &m = ci, *p = &ci; // m是对整形常量的引用, p是指向整形常量的指针
//  auto &n = i, *p3 - &ci; // 错误: i的类型是int而&ci的类型是const int

    const int i2 = 42;
    auto j2 = i2;
    const auto &k = i2;
    auto *p4 = &i2;
    const auto j3 = i2, &k = i2;


    /**
     * decltype 类型指示符
     * decltype，它的作用是选择并返回操作数的数据类型。
     * 在此过程中，编译器分析表达式 并得到它的类型，却不实际计算表达式的值：
     * 
     * decltype(f()) sum = x; // sum的类型就是函数f的返回类型
     * 
     * 编译器并不实际调用函数f，而是使用当调用发生时f的返回值类型作为sum的类型。
     * 换句话说，编译器为 sum 指定的类型是什么呢？就是假如f被调用的话将会返回的那个类型。
     */
    // 如果 decltype 使用的表达式是一个变量，
    // 则 decltype 返回该变量的类型（包括顶层 const 和引用在内）：
    const int ci5 = 0, &cj5 = ci5;
    decltype(ci5) x = 0; // x 的类型是 const int
    decltype(cj5) y = x; // y 的类型是 const int&, y绑定到变量x
//  decltype(cj5) z; // 错误: z是一个引用, 必须初始化

    /**
     * decltype()和引用
     * 
     * 因为r是一个引用，因此 decltype（r）的结果是引用类型。如果想让结果类型是r所指 的类型，
     * 可以把r作为表达式的一部分，如r+0，显然这个表达式的结果将是一个具体值 而非一个引用。
     * 
     * 另一方面，如果表达式的内容是解引用操作，则 decltype 将得到引用类型。
     * 正如我们所熟悉的那样，解引用指针可以得到指针所指的对象，而且还能给这个对象赋值。
     * 因此，decltype （*p）的结果类型就是 int&，而非int。
     * 
     * 记：decltype（（variable））（注意是双层括号）的结果永远是引用，
     * 而 decltype（variable）结果只有当variable 本身就是一个引用时才是 引用。
     * 
     * 赋值是会产生引用的一类典型表达式，引用的类型就是左值的类型。
     * 也就是说，如果i是int，则表达式i=x的类型是int&。
     * 
     */
    int i6 = 42, *p6 = &i, &r6 = i;
    decltype(r6 + 0) b; // 正确: 加法的结果是int,因此 b 是一个未初始化的的int
//  decltype(*p6) c; // 错误：c是int&，必须初始化

    // decltype 的表达式如果是加上了括号的变量，结果将是引用
//  decltype((i6)) d; // 错误：d是 int&，必须初始化
    decltype(i) e; // 正确：e是一个（未初始化的）int

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

/**
 * return 语句终止当前正在执行的函数并将控制权返回到调用该函数的地方。
 * 
 * return 语句有两种形式:
 * return;
 * return expression;
 * 
 */

/**
 * 1. 无返回值的函数
 * 
 * 没有返回值的return语句只能用在返回类型是void的函数中。返回void的函数不要求必须有return语句，因为在这类函数的最后一句会隐式的执行return。
 * 
 * void类型函数也能使用 return expression 形式, 不过返回的必须是另一个返回void的函数。
 * 强行令 void 函数返回其他类型的表达式将产生编译错误。
 * 
 */
void swap(int &v1, int &v2)
{
    if (v1 == v2)
        return;
    
    int tmp = v2;
    v2 = v1;
    v1 = tmp;
    // 此处无需显式的return语句
}

/**
 * 2. 有返回值的函数
 * 
 * 只要函数的类型不是void，则该函数的每条return语句必须返回一个值。返回值的类型必须与函数的返回类型相同，或能够隐式的转换成函数的返回类型。
 * 
 */

/**
 * 值是如何被返回的
 * 
 * 返回一个值的方式和初始化一个变量或形参的方式完全一样: 返回的值用于初始化调用点的一个临时量，该临时量就是函数调用的结果。
 * 
 */
/** 该函数的返回类型是string，意味着返回值将被拷贝到调用点 */
string make_plural(size_t ctr, const string &word,
                                const string &ending)
{
    return (ctr > 1) ? (word + ending) : word;
}
/** 如果函数返回引用，则该引用仅是它所引对象的一个别名 */
const string &shorterString(const string &s1, const string &s2)
{
    return s1.size() >= s2.size() ? s2 : s1;
}

/**
 * 不要返回局部对象的引用或指针
 * 
 * 函数完成后, 它所占用的存储空间也随之被释放。因此，函数终止意味着局部变量的引用将不再指向有效的内存区域。
 * 
 */

/**
 * 引用返回左值
 * 
 * 函数的返回类型决定函数调用是否是左值。调用一个返回引用类型的函数将得到左值，其他返回类型得到右值。
 */
char &get_val(string &str, string::size_type ix)
{
    return str[ix];
}

/**
 * 列表初始化返回值
 * 
 * C++11 新标准规定，函数可以返回花括号包围的值的列表。类似于其他返回结果，此处的列表也用来对表示函数返回的临时量进行初始化。
 * 如果列表为空，临时量执行值初始化；否则，返回的值由函数的返回类型决定。
 * 
 * vectro<string> process()
 * {
 *      // ...
 *      // expected actual 是string对象
 *      if (expected.empty())
 *          return {};
 *      else if (expected == actual)
 *          return {"functionX", "okay"};
 *      else
 *          return {"functionX", expected, actual};
 * }
 * 
 */

/**
 * 3. main函数的返回值
 * 
 * 如果main函数结尾处没有return语句，编译器将隐式地插入一条返回 0 的return语句。
 * main函数的返回值可以看做是状态指示器。返回 0 表示执行成功，返回其他值表示执行失败，其中非0值的具体含义视机器而定。
 * 为了使返回值与机器无关, cstdlib 定义了两个宏:
 * return EXIT_SUCCESS;     // 程序执行成功
 * return EXIT_FAILURE;     // 程序执行失败
 * 
 */


/**
 * 4. 返回数组指针
 * 
 * 因为数组不能被拷贝，所以函数不能返回数组，只能返回数组的指针或引用。
 * 
 * typedef int arrT[10];    // arrT是类型别名，表示含有10个整数的数组
 * using arrT = int[10];    // arrT的等价声明
 * arrT* func(int i);       // func 返回一个指向含有10个整数的数组的指针
 * 
 */

/**
 * 声明一个返回数组指针的函数
 * 
 * 返回数组指针的函数形式:
 * Type (*func(parameter_list))[dimension]
 * Type: 元素的类型
 * dimension: 数组的大小
 * (*func(parameter_list))两端的括号必须存在，如果没有这对括号，函数的返回类型将是指针的数组。
 * 解读:
 * int (*func(int i))[10];
 * 1. func(int i)               表示调用func函数时需要一个int类型实参。
 * 2. (*func(int i))            意味着我们可以对函数的返回结果进行解引用操作。
 * 3. (*func(int i))[10]        表示解引用func的调用将得到一个大小为10的数组。
 * 4. int (*func(int i))[10]    表示数组中的元素是 int 类型
 * 
 */

/**
 * 简化复杂函数的声明: 使用尾置返回类型 
 * 
 * 使用 尾置返回类型 可以简化上述 func 声明的方法。任何函数的定义都能使用尾置返回，但是这种形式对于返回类型比较复杂的函数最有效，比如返回类型是数组的指针或者数组的引用。
 * 
 * 尾置返回类型跟在形参列表后面并以一个>符号开头，在本应该出现返回类型的地方放置一个 auto：
 * auto func(int i) -> int(*)[10];
 * 因为我们把函数的返回类型放在了形参列表之后，所以可以清楚地看到 func函数返回的是一个指针，并且该指针指向了含有10个整数的数组。
 * 
 */

/**
 * 简化复杂函数的声明: 使用 decltype 
 * 
 * 还有一种情况，如果我们知道函数返回的指针将指向哪个数组，就可以使用 decltype 关键字声明返回类型。
 * 
 * int odd[] = {1, 3, 5, 7, 9};
 * int even[] = {0, 2, 4, 6 ,8};
 * // 返回一个指针，该指针指向含有5个整数的数组
 * decltype(odd) *arrPtr(int i)
 * {
 *      return (i % 2) ? &odd : &even;  // 返回一个指向数组的指针
 * }
 * arrPtr 使用关键字 decltype 表示它的返回类型是个指针，并且该指针所指的对象与 odd 的类型一致。
 * 因为 odd 是数组，所以 arrPtr返回一个指向含有5个整数的数组的指针。
 * 有一个地方需要注意：decltype 并不负责把数组类型转换成对应的指针，所以 decltype 的结果是个数组，要想表示 arrPtr 返回指针还必须在函数声明时加一个 * 符号。
 * 
 */

/**
 * ex 6.36
 * 
 * 编写一个函数的声明，使其返回数组的引用并且该数组包含10个 string 对象。
 * 
 * string (&func(string s))[10];
 * 
 */

/**
 * ex 6.37
 * 
 * 为上一题的函数再写三个声明，一个使用类型别名，另一个使用尾置返回类型，最后一个使用 decltype 关键字。
 * 
 * using ARRS = string[10];
 * ARRS &func(string s);
 * 
 * auto func(string s) -> string (&)[10];
 * 
 * string arr[10];
 * decltype(arr) &func(string s);
 */

int main(int argc, char* argv[])
{
    /** 引用返回左值的函数测试 */
    string s("a value");
    cout << s << endl;      // a value
    get_val(s, 0) = 'A';    // 将 s[0] 的值改为 A
    cout << s << endl;      // A value

    return 0;
}
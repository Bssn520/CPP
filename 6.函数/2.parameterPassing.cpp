#include <iostream>
#include <string>
using namespace std;

/**
 * 参数传递
 * 
 * 和其他变量一样，形参的类型决定了形参和实参交互的方式。如果形参是引用类型，它将绑定到对用的实参上；否则，将实参的值拷贝后赋值给形参。
 * 1. 当形参是引用类型时，我们说它对应的的实参被 引用传递 或者函数被 传引用调用。
 * 和其他函数一样，引用形参也是它绑定的对象的别名；也就是说，引用形参是它对应的实参的别名。
 * 2. 当实参的值被拷贝给形参时，形参和实参是两个相互独立的对象。
 * 这样的实参被称作 值传递 或者函数被 传值调用 。
 * 
 */

/** 该函数接受一个指针，然后将指针所指的值置为0 */
void resetPointer(int* p)
{
    *p = 0;
}

/** 该函数接受一个引用，然后将引用对象的值置为0 */
void resetQuote(int &p)
{
    p = 0;
}

/** 使用指针交换两个整数的值 */
void exchange(int* i, int* j)
{
    int tmp = *i;
    *i = *j;
    *j = tmp;
}

/** 判断string对象中是否含有大写字母 */
bool includeUpper(const string &s)
{
    for (auto c : s)
    {
        if (isupper(c))
            return true;
    }

    return false;
}

/** 把string 对象全都改成小写形式 */
void toLower(string &s)
{
    for (auto &c : s)
    {
        c = tolower(c);
    }
}

/** ex 6.21 比大小 */
int compare(const int &n1, int const *n2)
{
    return n1 > *n2 ? n1 : *n2;
}

/** ex 6.22 交换两个 int指针 */
void swapIntp(int** p1, int** p2)
{
    int* pTmp = *p1;
    *p1 = *p2;
    *p2 = pTmp;
}
/** 利用引用完成 ex 6.22 交换两个 int指针 */
void swapIntp2(int *&p1, int *&p2)
{
    int* tmp = p1;
    p1 = p2;
    p2 = tmp;
}


int main()
{
    /**
     * 传值参数
     * 
     * 当初始化一个非引用类型的变量时，初始值被拷贝给变量。传值参数的机理完全一样，函数对形参做的所有操作都不会影响实参。
     * 
     */

    /**
     * 指针形参
     * 
     * 指针的行为和其他非引用类型一样。
     * 当指针执行拷贝操作时，拷贝的是指针的值。拷贝后，两个指针是不同的指针。
     * 
     */
    int a = 42, b = 32;
    resetPointer(&a);
    cout << "a = " << a << endl;    // a = 0
    resetQuote(b);
    cout << "b = " << b << endl;    // a = 0

    /**
     * ex 6.10
     * 
     * 使用指针交换两个整数的值
     */
    int i = 10, j = 20;
    exchange(&i, &j);
    cout << "i = " << i << "; j = " << j << endl; // i = 20; j = 10

    /**
     * 传引用参数
     * 
     * 拷贝大的类类型对象或者容器对象比较低效，甚至有的类类型（包括IO 类型在内）根本就不支持拷贝操作。
     * 当某种类型不支持拷贝操作时，函数只能通过引用形参访问该类型的对象。
     * 
     * 注: 如果函数无须改变引用形参的值，最好将其声明为常量引用。
     * 
     */

    /**
     * const形参和实参
     * 
     * 和其他初始化过程一样，当用实参初始化形参时会忽略掉顶层 const。换句话说，形参的顶层 const 被忽略掉了。当形参有项层 const 时，传给它常量对象或者非常量对象都是可以的。
     * void fcn (const int i) {}
     * 调用 fcn 函数时，既可以传入 const int 也可以传入int。忽略掉形参的顶层 const 可能产生意想不到的结果:
     * void fcn (const int i) {} // fcn能够读取i，但是不能向主写值
     * void fcn (int i) {}  // 错误：重复定义了 fcn（int）
     * 在C++语言中，允许我们定义若干具有相同名字的函数，不过前提是不同函数的形参列表应该有明显的区别。
     * 因为顶层 const 被忽略掉了，所以在上面的代码中传入两个 fcn 函数的参数可以完全一样。
     * 因此第二个 fcn 是错误的，尽管形式上有差异，但实际上它的形参和第一个fcn的形参没什么不同。
     * 
     */

    /**
     * ex 6.17
     * 
     * 编写一个函数，判断 string 对象中是否含有大写字母。
     * 编写另一个函数， 把string 对象全都改成小写形式。
     * 
     */

    string s("abcdABCD");

    includeUpper(s);
    cout << (includeUpper(s) ? "include upper letter" : "not include upper letter") << endl;

	cout << s << endl;
	toLower(s);
	cout << s << endl;

    /**
     * ex 6.18
     * 
     * bool compare(matrix &m1, matrix &m2);
     * vector<int>::iterator change_val(int i, vector<int>::iterator it);
     * 
     */


    /**
     * 数组形参
     * 
     * 当我们为函数传递一个数组时，实际上传递的是指向数组首元素的指针。
     * 下面三个函数是等价的:
     * void print(const int*);
     * void print(const int[]);
     * void print(const int[10]);
     * 当编译器处理对 print 函数的调用时，只检查传入的参数是否是 const int* 类型。
     * 
     */

    /**
     * 1. 使用标记指定数组长度
     * 
     * 管理数组实参的第一种技术是，类似C风格字符串在最后一个字符后面跟着一个空字符。函数在处理C风格字符串时遇到空字符停止。
     * void print(const char* cp)
     * {
     *      if (cp)
     *          while (*cp)
     *              cout << *cp++;
     * }
     * 这种方法适用于那些有明显结束标记且该标记不会与普通数据混淆的情况，
     * 但是对于像 int 这样所有取值都是合法值的数据就不太有效了。
     */

    /**
     * 2. 使用标准库规范管理数组
     * 
     * 管理数组实参的第二种技术是传递指向数组首元素和尾后元素的指针。
     * 
     * void print(const int* beg, const int* end)
     * {
     *      while (beg != end)
     *          cout << *beg++ << endl;
     * }
     */

    /**
     * 3. 显式传递一个表示数组大小的形参
     * 
     * void print(const int ia[], size_t size)
     * {
     *      for (size_t i = 0;  != size; i++)
     *          cout << ia[i] << endl;
     * }
     * 
     */

    /**
     * 数组形参和const
     * 
     * 当函数不需要对数组元素执行写操作时，数组形参应该是指向const的指针。
     * 
     */

    /**
     * 数组引用形参
     * 
     * void print(int (&arr)[10])
     * {
     *      for (auto elem : arr)
     *          cout << elem << endl;
     * }
     * 
     * int &arr[10]     // 错误: 将arr声明成了引用的数组
     * int (&arr)[10]   // 正确; arr是具有10个整数的整形数组的引用
     * 这一用法也无形中限制了 print 函数的可用性，我们只能将函数作用于大小为10的数组。
     * 
     */

    /**
     * 传递多维数组
     * 
     * void  print(int (*matrix)[10], int rowSize);
     * // 等价于
     * void print(int matrix[][10], int rowSize);
     * 
     * int *matrix[10];     // 10个指针构成的数组
     * int (*matrix)[10];   // 指向含有10个整数的数组的指针
     * 
     */

    /**
     * ex 6.21
     * 
     * 编写一个函数，令其接受两个参数：一个是int 型的数，另一个是int指针。
     * 函数比较 int 的值和指针所指的值，返回较大的那个。
     * 
     */
    int n1 = 24, n2 = 45;
    cout << compare(n1, &n2) << endl;   // 45

    /**
     * ex 6.22
     * 
     * 编写一个函数，令其交换两个 int指针。
     */
    int n3 = 24, n4 = 48;
    int *n3p = &n3, *n4p = &n4;
    cout << "*n3p = " << *n3p << "  "
         << "*n4p = " << *n4p << endl;  // *n3p = 24  *n4p = 48
    swapIntp2(n3p, n4p);
    cout << "*n3p = " << *n3p << "  "
         << "*n4p = " << *n4p << endl;  // *n3p = 48  *n4p = 24

    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
using namespace std;

/**
 * 数组
 * 
 * 数组是一种类似于标准库类型 vector 的数据结构，但是在性能和灵活性的权衡上又与 vector 有所不同。
 * 与 vector 相似的地方是，数组也是存放类型相同的对象的容器，这些对象本身没有名字，需要通过其所在位置访问。
 * 与 vector 不同的地方是，数组的大小确定不变，不能随意向数组中增加元素。
 * 因为数组的大小固定，因此对某些特殊的应用来说程序的运行时性能较好，但是相应地也损失了一些灵活性。
 * 
 */

int main()
{

    /** 
     * 定义和初始化内置数组
     * 
     * 数组的声明形如 a[d] 其中 a 是数组的名字，d 是数组的维度。
     * 维度说明了数组中元素的个数，因此必须大于0。
     * 编译的时候维度应该是已知的。也就是说，维度必须是一个常量表达式。
     * “常量表达式（const expression）是指值不会改变并且在编译过程就能得到计算结果的表达式。”
     * 
     * 定义数组的时候必须指定数组的类型，不允许用 auto关键字由初始值的列表推断类型。
     * 另外和 vector一样，数组的元素应为对象，因此不存在引用的数组。
     * 
     */
    unsigned cnt = 42;              // 不是常量表达式
    constexpr unsigned sz = 42;     // 常量表达式
    int arr[10];                    // 含有10个整数的数组
    int* parr[sz];                  // 含有42个整形指针的数组
    string bad[cnt];                // 错误: cnt 不是常量表达式
//  string strs[get_size()];        // 当get_size 是constexpr时正确；否则错误

    /**
     * 显式初始化数组元素
     * 
     * 对数组进行列表初始化时，允许忽略数组的维度。
     * 如果未在声明时指明维度，编译器会根据初始值数量计算并推测出来；
     * 如果指明了维度，那么初始值的总数量不应该超过指定的大小，如果维度比提供的初始值数量大，
     * 则用提供的初始值初始化靠前的元素，剩下的元素被初始化成默认值。
     * 
     */
    const unsigned sz2 = 3;
    int ial[sz2] = {0, 1, 2};       // 含有3个元素的数组
    int a2[] = {0, 1, 2};           // 维度是3的数组
    int a3[5] = {0, 1, 2};          // 等价于a3[] = {0, 1, 2, 0, 0}
    string a4[3] = {"hi", "bye"};   // 等价于 a4[] = {"hi", "bye", ""}
//  int a5[2] = {0, 1, 2};          // 错误: 初始值过多

    /**
     * 字符数组的特殊性
     * 
     * 注意空字符"\0"
     */
    char a1[] = {'c', '+', '+'};        // 列表初始化，没有空字符
    char a22[] = {'c', '+', '+', '\0'};  // 列表初始化，含有显式的空白字符
    char a32[] = "c++";                  // 自动添加表示字符串结束的空字符
//  const char a4[6] = "Daniel";        // 错误: 没有空间可存放空字符

    /**
     * 不允许拷贝和赋值
     * 
     * 不能将数组的内容拷贝给其他数组作为初始值，也不能用数组为其他数组赋值。
     */
    int a[] = {0, 1, 2};
//  int a2[] = a;       // 错误: 不允许使用一个数组初始化另一个数组
//  a2 = a;             // 错误: 不能把一个数组直接赋值给另一个数组

    /**
     * 理解复杂的数组声明
     * 
     * 和vector一样，数组能存放大多数类型的对象。例如，可以定义一个存放指针的数组。
     * 又因为数组本身就是对象，所以允许定义数组的指针及数组的引用。
     * 在这几种情况中，定义存放指针的数组比较简单和直接，但是定义数组的指针或数组的引用就稍微复杂一点了。
     * 
     * 由内向外的顺序可帮 助我们更好地理解 Parray 的含义：
     * 首先是圆括号括起来的部分，*Parray 意味着 Parray 是个指针，
     * 接下来观察右边，可知道Parray 是个指向大小为10的数组的指针，
     * 最后观察左边，知道数组中的元素是int。
     * 这样最终的含义就明白无误了，Parray是 个指针，它指向一个 int 数组，数组中包含10个元素。
     * 同理，（&arrRef）表示 arrRef 是一个引用，它引用的对象是一个大小为10的数组，数组中元素的类型是int。
     * 
     * 要想理解数组声明的含义，最好的办法是从数组的名字开始按照由内向外的顺序阅读。
     */
    int* ptrs[10];              // ptrs是含有10个整形指针的数组
//  int& refs[10] = /* ? */;    // 错误: 不存在引用的数组
    int (*Parray)[10] = &arr;   // Parray指向一个含有10个整数的数组
    int (&arrRef)[10] = arr;    // arrRef 引用一个含有10个整数的数组
    int *(&arry)[10] = ptrs;    // arry是数组的引用，该数组含有10个指针

    /**
     * ex 3.27:
     * 
     * 假设txt size 是一个无参数的函数，它的返回值是int。请回答下列哪个定义是非法的？为什么？
     */
    unsigned buf_size = 1024;
//  int ia[buf_size];               // 非法, buf_size 是一个运行时变量
  int ia2[4 * 7 - 14];              // 合法, 是一个编译时常量
//  int ia3[txt_size()];            // 非法, 是一个函数调用, 可能在运行时才知道结果
//  char st[11] = "fundamental";    // 非法, 没有给空字符"\0"预留位置

    /**
     * ex 3.28:
     * 
     * 下列数组中元素的值是什么？
     * string sa［10];
     * int ia［10];
     * int main()
     * {
     *      string sa2[10];
     *      int ia2[10];
     * ｝
     * 
     * sa: 空字符串
     * ia: 0
     * sa2: 空字符串
     * ia2: 不确定
     * 
     */

    /**
     * 访问数组元素
     * 
     * 数组的元素也能使用范围for语句或下标来访问。
     * 在使用数组下标时，通常将其定义为size_t类型。
     * size_t是一种机器相关的无符号类型，它被设计的足够大以便能够表示内存中任意对象的大小。
     * 在cstddef头文件中定义了size_t类型, 这个文件是C标准库 stddef.h 头文件的C++语言版本。
     * 
     */
    unsigned scores[11] = {};
    unsigned grade;
    while (cin >> grade)
    {
        if (grade <= 100)
        {
            scores[grade/10]++; // 将当前分数段的统计值加1
        }
    }

    for (auto i : scores)       // 对于scores 中的每个计数值
        cout << i << " ";       // 输出当前的计数值
    cout << endl;

    /**
     * ex 3.31:
     * 
     * 编写一段程序，定义一个含有10个 int 的数组，令每个元素的值就是其下标值。
     * 
     */
    constexpr size_t length = 10;
    int arr2[length] = {};
    for (size_t i = 0; i < length; i++)
    {
        arr2[i] = i;
    }

    for (auto i : arr2)
        cout << i << " ";
    cout << endl;

    /**
     * ex 3.32:
     * 将上一题刚刚创建的数组拷贝给另外一个数组。利用 vector 重写程序，实现类似的功能。
     * 
     */
    int ia[10];
    for (size_t i = 0; i < 10; i++) ia[i] = i;

    // 将 ia 拷贝给 ia2
    int ia23[10];
    for (size_t i = 0; i < 10; i++) ia23[i] = ia[i];
    
    // 利用vector重写
    vector<int> iv1;
    for (decltype(iv1.size()) i = 0; i < 10; i++)
    {
        iv1.push_back(i);
    }

    // 将iv1拷贝给iv2
    vector<int> iv2(iv1);
    for(auto e : iv2)
        cout << e << " ";
    cout << endl;

    return 0;
}
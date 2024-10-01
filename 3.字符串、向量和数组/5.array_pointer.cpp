#include <iostream>
#include <string>
#include <vector>
#include <cstddef>      // size_t 类型
#include <iterator>     // 迭代器 begin() end()
using namespace std;

/* 比较两数组是否相等 */
bool areArraysEqual(int* arr1, int size1, int* arr2, int size2);

/**
 * 指针和数组
 * 
 * 通常情况下，使用取地址符来获取指向某个对象的指针，取地址符可以用于任何对象。
 * 数组的元素也是对象，对数组使用下标运算符得到该数组指定位置的元素。
 * 因此像其他对象一样，对数组的元素使用取地址符就能得到指向该元素的指针。
 * 
 */

int main()
{
    string nums[] = {"one", "two", "three"};    // 数组的元素是string对象
    string* p = &nums[0];                       // p指向nums的第一个元素

    /** 
     * 在很多用到数组名字的地方，编译器会自动地将其替换为一个指向数组首元素的指针 
     * 
     * 在大多数表达式中，使用数组类型的对象其实是使用一个指向该数组首元素的指针。
     */
    string* p2 = nums;      // 等价于 p2 = &nums[0]

    // 当使用数组作为一个auto变量的初始值时，推断得到的类型是指针而非数组
    int ia[] = {0, 1, 2};
    auto ia2(ia);   // 等价于 auto ia2[&ia[0]], 故显然 ia2 是一个整形指针, 指向ia的第一个元素
//  ia2 = 42;   // 错误: ia2是一个指针, 不能用int值给指针赋值

    // 当使用decltype(ia)时上述转换不会发生:
    decltype(ia) ia3 = {1, 3, 5};   // ia3 是一个含有3个整数的数组
    ia3[2] = 67;    // 正确

    /**
     * 指针也是迭代器
     * 
     * vector 和 string 的迭代器支持的运算，数组的指针全部支持。
     */
    // 使用递增运算符将指向数组元素的指针向前移动到下一个位置上：
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int* parr = arr;
    cout << *parr << endl;  // 0
    parr++;
    cout << *parr << endl; // 1

    // 利用指针遍历数组
    int* e = &arr[10];  // 拿到尾后指针(指向arr尾元素的下一位置的指针)
    for (int* i = arr; i != e; i++)
        cout << *i << " ";  // 0 1 2 3 4 5 6 7 8 9
    cout << endl;

    // 标准库函数 begin() & end()
    int arr22[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int* beg = begin(arr22);     // 指向arr2首元素的指针
    int* last = end(arr22);      // 指向arr尾元素的下一位置的指针

    // 找到数组中的第一个负数
    int arr3[] = {0, 1, 2, 3,4 , 5, 6, 7, -1, 9};
    int* pbeg = begin(arr3);
    int* pend = end(arr3);
    while (pbeg != pend && *pbeg >= 0)
        pbeg++;
    cout << "首个负数: " << *pbeg << endl; // -1

    /**
     * 指针运算
     * 
     */
    /** 
     * 1. 指针加减整数值 
     * 
     * 加法: 给（从）一个指针加上（减去）某整数值，结果仍是指针。
     * 新指针指向的元素与原来的指针相比前进了（后退了）该整数值个位置.
     * 
     * 减法: 和迭代器一样，两个指针相减的结果是它们之间的距离。参与运算的两个指针必须指 向同一个数组当中的元素。
     * 两个指针相减的结果的类型是一种名力 ptrdiff _t 的标准库类型，
     * 和 size t一样，ptrdiff _t也是一种定义在 cstddef 头文件中的机器相关的类型。
     * 因为差值可能为负值，所以ptrdiff_t 是一种带符号类型。
     * 
     * 比较: 只要两个指针指向同一个数组的元素，或者指向该数组的尾元素的下一位置，就能利用关系运算符对其进行较。
     * 尽管作用可能不是特别明显，但必须说明的是，指针运算同样适用于空指针和所指对象并非数组的指针。
     * 在后一种情况下，两个指针必须指向同一个对象或该对象的下一位置。
     * 如果p是空指针，允许给P加上或减去一个值为0的整型常量表达式。两个空指针也允许彼此相减，结果当然是0。
     * 
     */

    // 加法
    constexpr size_t sz = 5;
    int arr4[sz] = {1, 2, 3, 4, 5};
    int* ip = arr4;     // 此时指向首元素 1
    int* ip2 = ip + 4;  // 移动4个位置，指向 5
    cout << *ip2 << endl;   // 5

    // 减法
    auto n = end(arr4) - begin(arr4);
    cout << n << endl;  // 5

    // 比较
    int* b = arr4, *t = arr4 + sz;
    while (b < t)
        b++;
    // 如果两个指针分别指向不相关的对象，则不能比较它们:
    int i = 0, sz5 = 42;
    int* p5 = &i, *e5 = &sz5;
//  if (p5 < e5) {};    // 未定义的: p 和 e 无关，因此比较毫无意义。
    
    /**
     * 解引用和指针运算的交互
     * 
     * 指针加上一个整数所得的结果还是一个指针。假设结果指针指向了一个元素，则允许的解引用该结果指针。
     */
    int ia6[] = {0, 2, 4, 6, 8};
    int last2 = *(ia6 + 4);      // 正确: last2被初始化成8，也就是ia6[4]的值

    /**
     * 下标和指针
     * 
     * 如前所述，在很多情况下使用数组的名字其实用的是一个指向数组首元素的指针。
     * 一个典型的例子是当对数组使用下标运算符时，编译器会自动执行上述转换操作。
     * 
     */
    int ia7[] = {0, 2, 4, 6, 8};
    int i7 = ia7[2]; // ia7转换成指向数组首元素的指针, ia[2] 得到 (ia + 2) 所指的元素
    int* p7 = ia7;    // p指向ia7的首元素
    i7 = *(p7 + 2);   // 等价于 i = ia[2]

    int k = p7[-2];     // p[-2]是ia7[0]表示的那个元素
    cout << k << endl;  // 0

    /**
     * ex 3.34:
     * 
     * 假定p1和p2指向同一个数组中的元素，则下面程序的功能是什么？什么情况下该程序是非法的？
     * p1 += p2 - p1;
     * 答: 意为将p1移动（p2-p1）个位置；p1或p2是非法的，该程序就是非法的。
     */

    /**
     * ex 3.35:
     * 
     * 编写一段程序，利用指针将数组中的元素置为0。
     */
    int array[] = {0, 2, 4, 6, 8};
    for (int i = 0, *parray = array; i < 5; i++)
    {
        *parray = 0;
        parray++;
    }
    for (int i = 0; i < 5; i++) cout << array[i] << " ";
    cout << endl;   // 0 0 0 0 0

    /**
     * ex 3.36:
     * 
     * 编写程序, 比较两个数组是否相等。再写一个程序, 比较两个vector对象是否相等。
     */
    int arr1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int arr2[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    if (areArraysEqual(arr1, 9, arr2, 9))
        cout << "相等" << endl;
    else
        cout << "不相等" << endl;
    
    // 比较vector对象
    vector<int> iv1{1, 2, 3};
    vector<int> iv2{1, 2, 3, 4};
    if (iv1 == iv2)
        cout << "相等" << endl;
    else
        cout << "不相等" << endl;

    return 0;
}

/* 比较两数组是否相等 */
bool areArraysEqual(int* arr1, int size1, int* arr2, int size2)
{
    // 先判断数组长度是否相等
    if (size1 != size2)
        return false;
    // 比较数组中的每一个元素是否相等
    for (int i = 0; i < size1; i++)
    {
        if (arr1[i] != arr2[i])
            return false;
    }

    return true; // 所有元素相等，则返回 true
}
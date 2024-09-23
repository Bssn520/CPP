#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cstdlib>
#include <ctime>
using namespace std;

/**
 * 迭代器
 * 
 * 迭代器提供了对对象的间接访问，就迭代器而言，其对象是容器中的元素或者 string 对象中的字符。
 * 使用迭代器可以访问某个元素，迭代器也能从一个元素移动到另外一个元素。
 * 迭代器有有效和无效之分，这一点和指针差不多。
 * 有效的选代器或者指向某个元素，或者指向容器中尾元素的下一位置；其他所有情况都属于无效。
 * 
 */

int main()
{
    /**
     * 迭代器运算符
     * 
     * *iter            返回迭代器iter所指元素的引用
     * iter->mem        解引用iter并获取该元素的名为mem成员，等价于 (*iter).mem
     * ++iter           令iter指示容器中的下一个元素
     * --iter           令iter指示容器中的上一个元素
     * iter1 == iter2   判断两个迭代器是否相等(不相等), 如果两个迭代器指示的是同一个元素
     * iter1 != iter2   或者它们是同一个容器的尾后迭代器，则相等；反之，不相等
     * 
     */
    string s("some string");
    if (s.begin() != s.end())
    {
        auto it = s.begin();
        *it = toupper(*it);
    }
    cout << s << endl; // Some string

    /**
     * 将迭代器从一个元素移动到另一个元素 
     * 
     * 迭代器使用递增递减运算符来从一个元素移动到下一个元素。
     * 
     * 注意: 因为 end 返回的选代器并不实际指示某个元素，所以不能对其进行递增或解引用的操作。
     */
    for (auto it = s.begin(); 
        it != s.end() && !isspace(*it); it++)
    {
        *it = toupper(*it);
    }
    cout << s << endl; // SOME string

    /**
     * 迭代器类型
     * 
     * 一般来说，我们无需知道迭代器的精确类型。
     * 实际上，拥有迭代器的标准库类型使用 iterator 和 const_iterator 来表示迭代器的类型：
     * vector<int>::iterator it;          // it能读写 vector<int>的元素 
     * string::iterator it2;              // it2 能读写 string 对象中的字符 
     * vector<int>::const_iterator it3;   // it3 只能读元素，不能写元素 
     * string::const_iterator it4;        // it4 只能读字符，不能写字符
     * 
     * const_iterator 和常量指针差不多，能读取但不能修改它所指的元素值。相反，iterator 的对象可读可写。
     * 如果 vector 对象或string 对象是一个常量，只能使用 const_iterator；
     * 如果 vector 对象或 string 对象不是常量， 那么既能使用 iterator 也能使用 const_iterator
     * 
     */

    /**
     * begin 和 end 运算符
     * 
     * begin 和 end 返回的具体类型由对象是否是常量决定，
     * 如果对象是常量，begin 和 end 返回 const_iterator; 否则返回 iterator
     */
    vector<int> v;
    const vector<int> cv;
    auto it1 = v.begin();   // iterator
    auto it2 = cv.begin();  // const_iterator

    // cbegin() cend()
    // 不论 vector 对象（或string 对象）本身是否是常量，返回值都是 const_iterator。
    auto it3 = v.cbegin();

    /**
     * 结合解引用和成员访问操作
     * 
     * 为了简化 解引用结合成员操作 这种操作, C++ 定义了箭头运算符(->)。
     * 箭头运算符结合了解引用和成员访问的操作，it->mem 和 (*it).mem 表达的意思相同。
     * 
     */
    vector<string> sentences;
    string text;
    for (int i = 0; i < 3; i++)
    {
        getline(cin, text);
        sentences.push_back(text);
    }
    // 依次输出text 的每一行直至遇到第一个空白行为止。
    for (auto it = sentences.cbegin();
        it != sentences.cend() && !it->empty(); it++)
        cout << *it << endl;
    
    /**
     * 某些对 vector 对象的操作会使迭代器失效
     * 
     * 虽然 vector 对象可以动态地增长，但是也会有一些副作用。
     * 已知的一个限制是不能在范围 Eor 循环中向 vector 对象添加元素。
     * 另外一个限制是任何一种可能改变 vector 对象容量的操作，
     * 比如 push_back，都会使该 vector 对象的迭代器失效。
     */


    /**
     * ex 3.23
     * 
     * 编写一段程序，创建一个含有10个整数的vector对象，然后使用迭代器将所有元素的值都变成原来的两倍。
     * 输出 vector 对象的内容，检验程序是否正确。
     */
    vector<int> nums2;
    for (int i = 0; i != 10; i++)
    {
        nums2.push_back(i);
    }

    for (auto it = nums2.begin();
        it != nums2.end(); it++)
    {
        *it = *it * 2;
    }

    for (auto n : nums2)
        cout << n << " ";
    cout << endl; // 0 2 4 6 8 10 12 14 16 18


    /**
     * 迭代器运算
     * 
     * 可以令选代器和一个整数值相加（或相減），其返回值是向前（或向后）移动了若干个位置的迭代器。
     * 
     * auto mid = vi.begin() + vi.size() / 2; // 计算得到最接近vi 中间元素的一个迭代器
     * 
     */
    // 定义int容器
    vector<int> nums;
    
    // 向容器中添加随机数
    srand(time(NULL)); // 初始化随机数种子
    for (int i = 0; i < 100; i++)
    {
        int n = rand() % 1000;
        nums.push_back(n);
    }

    // 排序 nums 以进行二分查找
    sort(nums.begin(), nums.end());
    // 输出排序后的数组
    cout << "Sorted nums: ";
    for (const auto& n : nums) {
        cout << n << " ";
    }
    cout << endl;


    // 在排序后初始化 beg、end 和 mid
    auto beg = nums.begin(), end = nums.end();
    auto mid = nums.begin() + (end - beg)/2;

    // 当还有元素尚未检查并且我们还没有找到goal时执行循环
    int goal;
    cin >> goal; // 获取用户输入的查找值

    while (mid != end && *mid != goal)
    {
        if (goal < *mid)            // 我们要找的元素在前半部分吗?
            end = mid;              // 如果在，则忽略掉后半部分元素
        else                        // 我们要找的元素在后半部分
            beg = mid + 1;          // 则忽略掉前半部分的元素
        mid = beg + (end - beg)/2;  // 计算得到新的中间点
    }


    // 打印结果
    if (mid != end && *mid == goal)
        cout << "Found: " << goal << " at position " << (mid - nums.begin() + 1) << endl;
    else
        cout << "Not found" << endl;        

    return 0;
}
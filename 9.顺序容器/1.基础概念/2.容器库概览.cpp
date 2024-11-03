/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-02 15:31:40
 * @LastEditTime: 2024-11-03 20:31:22
 * @Description: 容器库概览
 * 
 */

/*

容器库概览

容器类型上的操作形成了一种层    // 某些操作是所有容器类型都提  // 另外一些操作仅针对顺序容器、关联容器或无序    // 还有一些操作只适用于一小部分容器

容器操作:
类型别名

别名	含义
iterator	此容器类型的迭代器类型
const_iterator	可以读取元素，但不能修改元素的迭代器类型
size_type	无符号整数类型，足够保存此种容器类型最大可能容器的大小
difference_type	带符号整数类型，足够保存两个迭代器之间的距离
value_type	元素类型
reference	元素的左值类型，通常与 value_type& 含义相同
const_reference	元素的 const 左值类型（即 const value_type&）

构造函数

默认构造函数：C c;  // 构造空容器（array 类型参见第 301 页）
拷贝构造：C c1(c2); // 构造 c1 为 c2 的拷贝
范围构造：C c(b, e);    // 构造 c，将迭代器 b 和 e 指定范围内的元素拷贝到 c 中（array 不支持）
列表初始化：C c{a, b, c...};    // 通过初始化列表构造 c

赋值与交换

赋值：
c1 = c2;    // 将 c1 中的元素替换为 c2 中的元素
c1 = {a, b, c...};  // 将 c1 中的元素替换为初始化列表中的元素（array 不支持）
交换：
a.swap(b); 或 swap(a, b);   // 交换 a 和 b 的元素

大小相关操作

获取大小：c.size(); // 获取 c 中元素的数目（不支持 forward_list）
获取最大大小：c.max_size(); // c 可保存的最大元素数目
是否为空：c.empty();    // 若 c 中存储了元素，返回 false，否则返回 true

添加/删除元素（array 不支持）

插入元素：c.insert(args);   // 将 args 中的元素拷贝到 c 中
构造元素：c.emplace(inits); // 使用 inits 构造 c 中的一个元素
删除元素：c.erase(args);    // 删除 args 指定的元素
清空容器：c.clear();    // 删除 c 中的所有元素，返回 void

关系运算符

相等运算符：==, !=  // 所有容器都支持相等和不等运算符
关系运算符：< <= > >=  // 无序关联容器不支持关系运算符

获取迭代器

普通迭代器：
c.begin(), c.end(); // 返回指向 c 的首元素和尾元素之后位置的迭代器
c.cbegin(), c.cend();   // 返回 const_iterator 类型的迭代器
反向迭代器（不支持 forward_list）：
c.rbegin(), c.rend();   // 返回指向 c 的尾元素和首元素之前位置的反向迭代器
c.crbegin(), c.crend(); // 返回 const_reverse_iterator 类型的反向迭代器

// 定义一个 1ist 对象，其元素类型是 int 的deque
list<deque<int> > list_deque;

*/

/*

1. 迭代器

一个迭代器范围由一对迭代器表示，两个迭代器分别指向同一个容器中的元素或者是尾元素之后的位置。

这种元素范围被称左闭合区间:
[begin, end)
表示范围自 begin 开始，于 end 之前结束。迭代器 begin 和 end 必须指向相同的容器。 end 可以与begin 指向相同的位置，但不能指向 begin 之前的位置。

使用左闭合范围蕴含的编程假定:
- 如果begin与 end 相等，则范围为空
- 如果begin 与 end 不等，则范围至少包含一个元素，且begin 指向该范围中的第一个元素
- 我们可以对begin递增若干次，使得 begin == end

while (begin != end) {
    *begin = val;
    ++begin;
}

ex 06:
std::list 是一个双向链表容器，不支持随机访问迭代器，因此不能直接用 < 比较两个迭代器。< 比较符通常只能用于支持随机访问的容器。

容器类型成员:
通过类型别名，我们可以在不了解容器中元素类型的情况下使用它。如果需要元素类型，可以使用容器的value_type。如果需要元素类型的一个引用，可以使用 reference 或 const_reference
// iter 是通过 1ist<string>定义的一个迭代器类型
list<string>::iterator iter;
// count 是通过 vector<int>定义的一个 difference_type 类型
vector<int>::difference_type count;

简单例子:
    std::list<std::string> words = {"apple", "banana", "cherry"};
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // 使用 value_type 声明元素类型变量
    std::list<std::string>::value_type fruit = "orange";  // 等同于 std::string fruit = "orange";
    words.push_back(fruit);  // 将新元素添加到 list 中
    std::cout << "Last fruit in list: " << words.back() << std::endl;

    // 使用 reference 声明元素的引用
    std::list<std::string>::reference first_fruit = words.front();
    first_fruit = "grape";  // 修改第一个元素的值
    std::cout << "First fruit in list after modification: " << words.front() << std::endl;

    // 使用 const_reference 声明常量引用
    std::list<std::string>::const_reference last_fruit = words.back();
    std::cout << "Last fruit in list (read-only): " << last_fruit << std::endl;

    // 使用 difference_type 计算两个迭代器之间的距离
    std::vector<int>::difference_type count = numbers.end() - numbers.begin();
    std::cout << "Number of elements in vector: " << count << std::endl;

    // size_type类型
    // size_type 是 std::vector 定义的无符号整数类型，专门用于表示容器的大小或索引
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    for (std::vector<int>::size_type i = 0; i < numbers.size(); ++i) {
        std::cout << "Element at index " << i << ": " << numbers[i] << std::endl;
    }

begin 和 end 成员:
begin end
cbegin cend


容器定义和初始化

常见初始化方式对比:
初始化方式	         示例	                                    适用场景
默认构造	        std::vector<int> vec;	                创建空容器
指定大小和初始值	  std::vector<int> vec(5, 10);	         指定大小和默认初始值
初始列表初始化	     std::vector<int> vec = {1, 2, 3};	     简便地指定初始元素
拷贝构造	        std::vector<int> vec2(vec1);	        创建容器副本
移动构造	        std::vector<int> vec3(std::move(vec1));	通过移动节省资源
迭代器范围初始化	 std::vector<int> vec(list.begin(), list.end()); 不同容器间的转换


ex 11:
对6种创建和初始化 vector 对象的方法，每一种都给出一个实例。解释每个vector包含什么值。

vector<int> v1;  //v1为空
vector<int> v2 = v1;  //v2为空
vector<int> v3(v2);  //v3为空
vector<int> v4(10);  //10个0
vector<int> v5(10,1);  //10个1
vector<int> v6{1,2,3};  //1 2 3
vector<int> v7 = {1,2,3};  //1 2 3
vector<int> v8(v7.begin(),v7.end());  //1 2 3

ex 12:
对于接受一个容器创建其拷贝的构造函数，和接受两个迭代器创建拷贝的构造函数，解释它们的不同。

两个容器的类型及其元素必须匹配； 传递迭代器参数来拷贝一个范围时，就不要求容器类型相同了，只要能将要拷贝的元素转换。

ex 13:
如何从一个list初始化一个vector？从一个vector又该如何创建？编写代码验证你的答案。

使用迭代器范围初始化 std::vector 时，编译器会自动转换数据类型（如果目标类型可以从源类型构造或转换）。
其他初始化方式不会进行隐式类型转换。

*/


/*
赋值和 swap

c1 = c2;        // 将c1的内容替换为c2中元素的拷贝
c1 = {a,b,c};   // 赋值后，c1 大小 3
第一个赋值运算后，左边容器将与右边容器相等。如果两个容器原来大小不同，赋值运算后两者的大小都与右边容器的原大小相同;
第二个赋值运算后，c1的size 变力3，即花括号列表中值的数目。

与内置数组不同，标准库array类型运行赋值。赋值号左右两边的运算对象必须具有相同的类型:
array<int, 10> a1 = {0,1,2,3,4,5,6.7,8,9};
array<int, 10> a2 = {0};    // 所有元素值均为0
a1 = a2;                    // 替换 a1 中的值
a2 = {0};                   // 错误: 不能将一个花括号列表赋予数组

下表列出的与赋值相关的运算符可用于所有容器。赋值运算符将其左边容器中的全部元素替换为右边容器中元素的拷贝：
c1 = c2             将c1 中的元素替换为c2 中元素的拷贝。c1 和 c2必须具有相同的类型
c = {a, b, c...}    将 c1 中元素替换初始化列表中元素的拷贝（array 不适用）
swap(c1, c2)        交换c1和c2中的元素： c1和c2必须具有相同的类型。swap通常比从c2向c1拷贝元素快得多
c1.swap(c2)         与上一行等价
assign 操作不适用于关联容器和 array
seq.assign(b, e)    将seg中的元素替换为迭代器b和e所表示的范围中的元素。迭代器b和e不能指向seq中的元素
seq.assign(il)      将 seg 中的元素替换为初始化列表il中的元素
seq.assign(n, t)    将seg中的元素替换为n个值为t的元素
注意:
赋值相关运算会导致指向左边容器内部的迭代器、引用和指针失效。而 swap 操作将容器内容交换不会导致指向容器的选代器、引用和指针失效（容器类型力 array 和 string 的情况除外）。

使用 assign (仅顺序容器)

顺序容器（array除外）还定义了一个名为 assign 的成员，允许我们从一个不同但相容的类型赋值，或者从容器的一个子序列赋值。
assign 操作用参数所指定的元素（的拷贝）替换左边容器中的所有元素。

用 assgin实现将一个 vector 中的一段 char *值赋予一个 list 中的 string：
list<string> names;
vector<const char*> oldstyle;
names = oldStyle;   // 错误：容器类型不匹配
// 正确：可以将 const char*转换为 string
names.assign(oldStyle.cbegin(), oldStyle.cend());

assign 的第二个版本接受一个整型值和一个元素值。它用指定数目且具有相同给定值的元素替换容器中原有的元素：
// 等价于 slistl.clear()；
// 后跟 slistl.insert（slistl.begin()，10， "Hiya！"）； 
list<string> slist1(1); // 1个元素，为空 string 
slist1.assign(10， "Hiya！"); // 10个元素，每个都是 “Hiya！”

使用 swap

swap 操作交换两个相同类型容器的内容。调用swap 之后，两个容器中的元素将会交换:
vector<string> svec1(10);
vector<string> svec2(24);
swap(svec1, svec2);
调用 swap 后，svec1 将包含24个 string元素，svec2 将包含10个 string。
除 array外，swap 不对任何元素进行拷贝、删除或插入操作，因此可以保证 在常数时间内完成。

swap 操作之后，指向容器的迭代器、引用和指针都不会失效 (除 string 外)
假定 iter 在 swap 之前指向 svec1[3]的string, 在swap 之后它指向 svec2［3］的元素。与其他容器不同，对一个 string调用 swap 会导致迭代器、引用和指针失效。

与其他容器不同，swap 两个 array 会真正交换它们的元素。


容器大小操作

成员 size 返回容器中元素的数目;
empty 当 size 为 0 时返回布尔值true, 否则返回 false;
mac_size 返回一个大于或等于该类型容器所能容纳的最大元素数的值。
注意: forward_list 支持 max_size 和 empty，但不支持 size。

关系运算符

每个容器类型都支持相等运算符(== 或 !=): 除了无序关联容器外的所有容器都支持关系运算符(> >= < <=)。
关系运算符左右两边的运算对象必须是相同类型的容器，且必须保存相同类型的元素。

比较两个容器实际上是进行元素的逐对比较:
如果两个容器具有相同大小且所有元素都两两对应相等，则这两个容器相等：否则两个容器不等。 
如果两个容器大小不同，但较小容器中每个元素都等于较大容器中的对应元素，则较小容器小于较大容器。 
如果两个容器都不是另一个容器的前缀子序列，则它们的比较结果取决于第一个不相等的元素的比较结果。

容器的关系运算符使用元素的关系运算符完成比较:
只有当其元素类型也定义了相应的比较运算符时，我们才可以使用关系运算符来比较两个容器。
容器的相等运算符实际上是使用元素的==运算符实现比较的，而其他关系运算符是使用元素的<运算符。
如果元素类型不支持所需运算符，那么保存这种元素的容器就不能使用相应的关系运算。
例如，我们在第7章中定义的 sales_data 类型并未定义=和<运算。 因此，就不能比较两个保存Sales_data 元素的容器。

ex 15:
编写程序，判定两个 vector<int>是否相等:
vector<int> v1{1,2,3};
vector<int> v2{1,2};

std::cout << boolalpha << v1==v2 << std::endl;

ex 16:
重写上一题的程序，比较一个 list<int> 中的元素和一个 vector<int> 中的元素:
vector<int> v1{1,2,3};
list<int> l1{1,2};

// 使用临时对象，创建一个匿名的 vector<int>，直接将其传递给 == 运算符进行比较。这个匿名的 vector<int> 在表达式结束后会被销毁。
std::cout << boolalpha << (vector<int>(l1.begin(), l1.end()) == v1) << std::endl;

ex 17:
假定c1 和c2 是两个容器，下面的比较操作有何限制（如果有的话）？
    if (c1 < c2)
答: c1和c2不能是无序容器，且容器类型要相同，最后，元素类型要支持运算符。

*/

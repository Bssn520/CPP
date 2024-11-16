/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-09 20:12:36
 * @LastEditTime: 2024-11-16 15:06:29
 * @Description:
 *
 */

/*
定制操作

1. 向算法传递函数

谓词

谓词是一个可以调用的表达式，其返回结果是一个能用作条件的值。
标准库算法所使用的谓词分为两类: 一元谓词(意味着它们只接受单一参数)、二元谓词(意味着它们有两个参数)。

sort 的重载版本, 按string长度来进行排序:
// 比较函数，用来按长度排序单词
bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}
// 按长度由短至长排序 words
sort(words.begin(), words.end(), isSorter);

排序算法

在我们将 words 按大小重排的同时，还希望具有相同长度的元素按字典序排列。为了保持相同长度的单词按字典序排列，可以使用 stable_sort 算法。这种稳定排序算法维持相等元素的原有顺序。

elimDups(words); // 将 words 按字典序重排，并消除重复单词
// 按长度重新排序，长度相同的单词维持字典序
stable_sort(words.begin(), words.end(), isShorter);
for (const auto &s : words)
    cout << s << " ";
cout << endl;

假定在此调用前words 是按字典序排列的，则调用之后，words 会按元素大小排序，而长度相同的单词会保持字典序。


2. lambda 表达式

我们可以向一个算法传递任何类别的可调用对象。对于一个对象或一个表达式，如果可以对其使用调用运算符，则称它为可调用的。

可调用对象除了函数、函数指针外，还有 重载了函数调用符的类 以及 lambda 表达式。

一个 lambda 表达式表示一个可调用的代码单元。可以将其理解为一个未命名的内联函数。
与函数类似，一个 lambda 表达式具有一个返回类型，一个参数列表，一个函数体。
但与函数不同，lambda 可能定义在函数内部。

[capture list] (parameter list) -> return type { function body }
capture list(捕获列表) 是一个lambda所在函数中定义的局部变量的列表(通常为空);
return type, parameter list, function body 与任何函数一样。但是不同的是，lambda必须使用尾置返回。

可以忽略参数列表和返回类型，但必须永远包含捕获列表和函数体:
auto f = [] { return 42; };
调用:
cout << f() << endl; // 打印 42

注意: 如果 lambda 的函数体包含任何单一 return 语句之外的内容，且未指定返回类型，则返回void

向 lambda 传递参数

与普通函数类似，调用 lambda 时给定的实参被用来初始化 lambda 的形参。
但与普通函数不同，lambda 不能有默认参数。

stable_sort(words.begin(), words.end(),
            [](const string &a, const string &b)
                { return a.size() < b.size(); });

使用捕获列表

// 捕获 lambda 所在函数内的 sz 变量
[sz](const string &a)
    { return a.size() >= sz; };

注意: 一个 lambda 只有在其捕获列表中捕获一个它所在函数中的局部变量，才能在函数体中使用该变量。

调用 find_if

// 这里对find_if 的调用返回一个迭代器，指向第一个长度不小于给定参数sz 的元素。
// 如果这样的元素不存在，则返回 words.end() 的一个拷贝。
auto wc = find_if(words.begin(), words.end(),
            [sz](const string &a)
                { return a.size() >= sz; });

for_each 算法
for_each 接受一个可调用的对象，并对输入序列中的每个元素调用此对象。

// 打印长度大于等于给定值的单词，每个单词后接一个空格
for_each(wc, words.end(),
         [](const string &s) { cout << s << " "; });
cout << endl;

注意: 只需要对lambda 所在函数中定义的变量使用捕获列表。lambda 可以直接使用定义在当前函数外的变量。


3. lambda 捕获和返回

当定义一个 lambda 时，编译器生成一个与 lambda 对应的新的(未命名的)类类型。
当向一个函数传递一个 lambda 时，同时定义了一个新类型和该类型的一个对象: 传递的参数就是此编译器生成的类类型的未命名对象。
类似的，当使用auto定义一个用 lambda 初始化的变量时，定义了一个从 lambda 生成的类型的对象。

值捕获

被捕获变量的值是在lambda 创建时拷贝，因此随后对其修改不会影响到lambda 内对应的值:
    size_t v1 = 42;
    auto f = [v1]
    { return v1; };

    v1 = 0;
    auto j = f();
    std::cout << j << std::endl; // 42; f 保存了我们创建它时v1的拷贝

引用捕获

    size_t v1 = 42;
    auto f = [v1]
    { return v1; };

    auto f2 = [&v1]
    { return v1; };

    v1 = 0;
    auto j = f();
    std::cout << j << std::endl; // 42; f 保存了我们创建它时v1的拷贝
    auto j2 = f2();
    std::cout << j2 << std::endl; // 0; f2 保存了v1的引用，而非拷贝

注意:
如果采用引用方式捕获一个变量，就必须确保被引用的对象在 lambda 执行的时候是存在的。
lambda 捕获的都是局部变量，这些变量在函数结束后变销毁了。

隐式捕获

[=](){};    // 告知编译器采用值捕获方式
[&](){};    // 采用引用捕获方式

还能混合使用隐式捕获或者显式捕获:
[=, &c](){};    // 使用 "=" 表示使用隐式值捕获；但对 c 采用显式引用捕获
[&, c](){};     // 使用 "&" 表示使用隐式引用捕获；但对 c 采用显式值捕获

lambda 捕获列表:
[]      // 空捕获列表。lambda 不能使用所在函数中的变量。一个 lambda 只有捕获变量后才能使用它们

[names]     // names 是一个逗号分隔的名字列表，这些名字都是lambda 所在函数的局部变量。默认情况下，捕获列表中的变量都被拷贝。名字前如果使用了＆，则采用引用捕获方式

[&]     // 隐式捕获列表，采用引用捕获方式。lambda 体中所使用的来自所在函数的实体都采用引用方式使用
[=]     // 隐式捕获列表，采用值捕获方式。lambda 体将拷贝所使用的来自所在函数的实体的值

[&, identifier_list]    // identifier_list 是一个逗号分隔的列表，包含0个或多个来自所在函数的变量。这些变量采用值捕获方式，而任何隐式捕获的变量都采用引用方式捕获。identifier_list 中的名字前面不能使用&

[=, identifier_list]    // identifier_list 中的变量都采用引用方式捕获，而任何隐式捕获的变量都采用值方式捕获。identifier_list 中的名字不能包括 this，且这些名字之前必须使用＆

可变 lambda

默认情况下，对于一个值被拷贝的变量，lambda不会改变其值。
如果我们希望能改变一个被捕获的变量的值，必须在参数列表首加上关键字 mutable。
    size_t v2 = 42;
    auto f3 = [v2]() mutable
    { return ++v2; };
    v2 = 0;
    std::cout << f3() << std::endl; // 43

指定 lambda 返回类型

当lambda体内的语句多于一句时，必须指定返回类型，否则按 void 处理，被推断为返回void的lambda不能返回值

transform 函数用于将指定序列中的元素更改为其绝对值:
transform(vi.begin(), vi.end(), vi.begin(),
            [](int i) -> int
            { if (i < 0) return -i; else return i; });


4. 参数绑定

标准库 bind 函数

bool check_size(const string &s, string::size_type sz)
{
    return s.size() >= sz;
}

可以使用 bind 函数来解决向 check_size 传递一个长度参数的问题。
bind 函数接受一个可调用对象，生成一个新的可调用对象来 “适应” 原对象的参数列表。

auto newCallable = bind(callable, arg_list);
newCallable 本身是一个可调用对象，arg_list 是一个逗号分隔的参数列表，对应给定的callable 的参数。
即，当我们调用newCallable 时，newCallable会调用callable，并传递给它arg_list中的参数。

绑定 check_size 的 sz 参数

auto check6 = bind(check_size, _1, 6);
此bind调用只有一个占位符，表示check6只接受一个单一参数。

因此，原来的lambda表达式:
auto wc = find_if(words.begin(), words.end(),
            [sz](const string &a) { });
可以改写为:
auto wc = find_if(words.begin(), words.end(),
            bind(check_size, _1, sz));

使用 placeholders 名字

名字 _n 都定义在 std::placeholders::_1...中，可以声明:
using namespace std::placeholders;

bind 的参数

auto g = bind(f, a, b, _2, c, _1);
传递给 g 的参数会按位置绑定到占位符。因此当当调用 g 时，其第一个参数被传递给f作为最后一个参数，第二个参数被传递给f作为第三个参数。

用 bind 重排参数顺序

按单词长度由短至长排序:
sort(words.begin(), words.end(), isShorter);
按单词长度由长至短排序:
sort(words.begin(), words.end(), bind(isShorter, _2, _1));

绑定引用参数

默认情况下，bind 的非占位符参数被拷贝到bind返回的可调用对象中。
ostream &print(ostream &os, const string &s, char c)
{
    return os << s << c;
}

错误，不能直接用 bind 来代替对 os 的捕获:
for_each(words.begin(), words.end(), bind(print, os, _1, ' ')); // 错误

正确的方法，使用 ref 函数:
for_each(words.begin(), words.end(), bind(print, ref(os), _1, ' '));
函数 ref 返回一个对象，包含给定的引用，此对象是可拷贝的。另外还有一个 cref 函数，生成一个保存 const引用的类。


*/


#include <cstddef>
#include <iostream>
int main(int argc, const char **argv)
{
    size_t v1 = 42;
    auto f = [v1]
    { return v1; };

    auto f2 = [&v1]
    { return v1; };

    v1 = 0;
    auto j = f();
    std::cout << j << std::endl; // 42; f 保存了我们创建它时v1的拷贝
    auto j2 = f2();
    std::cout << j2 << std::endl; // 0; f2 保存了v1的引用，而非拷贝

    size_t v2 = 42;
    auto f3 = [v2]() mutable
    { return ++v2; };
    v2 = 0;
    std::cout << f3() << std::endl; // 43


    return 0;
}

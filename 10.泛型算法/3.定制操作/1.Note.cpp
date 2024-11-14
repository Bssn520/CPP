/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-09 20:12:36
 * @LastEditTime: 2024-11-14 15:55:14
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


*/

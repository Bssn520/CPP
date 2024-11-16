/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-16 15:36:26
 * @LastEditTime: 2024-11-16 18:12:45
 * @Description:
 *
 */

/*
再探迭代器

除了为每个容器定义的迭代器外，标准库还在头文件中定义了额外几种迭代器:
- 插入迭代器     // 这些迭代器被绑定到一个容器上，用来向容器内插入元素
- 流迭代器      // 这些迭代器被绑定到输入或输出流上
- 反向迭代器    // 这种迭代器向后而不是向前移动。(除了 forward_list 之外的标准库容器都支持)
- 移动迭代器    // 用于移动元素

1. 插入迭代器

it = t          在it指定的位置插入值 t。如果c是it绑定的容器，依赖于插入迭代器的不同种类，此赋值会分别调用 c.push_back(t), c.push_front(t), c.insert(t, p), 其中 p 为传递给 inserter 的迭代器位置。
it++, ++it, *it 这些操作虽然存在，但不会对 it 做任何事。每个操作都返回 it

插入器有三种类型，差异在于元素插入的位置:
back_inserter   // 创建一个使用 push_back 的迭代器
front_inserter  // 创建一个使用 push_front 的迭代器
inserter        // 创建一个使用 insert 的迭代器。此函数接受第二个参数，这个参数必须是一个指向给定容器的迭代器。元素将被插入到给定迭代器所表示的元素之前。

当调用 inserter(c, iter)时，我们得到一个迭代器，使用它时，会将元素插入到iter原来所指元素之前的位置:
*it = val;
其效果等价于：
it = c.insert(it, val);
++it;

front_inserter会将元素插入到首部，结果是插入后的顺序与原来元素的顺序恰恰相反。


2. iostream 迭代器

istream_iterator操作:
istream_iterator<T> in(is);     // in 从输入流 is 读取类型为 T 的值
istream_iterator<T> end;        // 读取类型为 T 的值的 istream_iterator 迭代器，表示尾后位置
in1 == in2      // in1 和 in2 必须读取相同类型。如果它们都是尾后迭代器，或绑定到相同的输入，则两者相等
in1 != in2      // 同上
*in             // 返回从流中读取的值
in->mem         // 与 (*in).mem 等价
++in, in++      // 使用元素类型所定义的 >> 运算符从输入流中读取下一个值。与往常一样，前置版本返回一个指向递增后迭代器的引用，后置版本返回旧值。

ostream_iterator操作:
ostream_iterator<T> out(os);        // out 将类型为 T 的值写到输出流 os 中
ostream_iterator<T> out(os, d);     // out 将类型为 T 的值写到输出流 os 中, 每个值后面都输出一个 d, d 指向一个空字符结尾的字符数组。
out = val;          // 用 << 运算符将 val 写入到 out 所绑定的ostream 中。val的类型必须与 out 可写的类型兼容。
++out, out++, *out // 这些运算符是存在的，但不对out 做任何事情。每个运算符都返回out

ostream_iterator<int> out_iter(cout, " ");
for (auto e : vec)
    *out_iter++ = e;    // 赋值语句将元素写到 cout
cout << endl;

可以通过调用 copy 来打印容器内元素:
copy(vec.cbegin(), vec.cend(), out_iter);
cout << endl;

使用流迭代器处理类类型

我们可以为任何定义了输入运算符（>>）的类型创建istream_iterator 对象。
类似的，只要类型有输出运算符（<<），我们就可以其定义 ostream_iterator。


3. 反向迭代器

反向迭代器就是在容器中从尾元素向首元素反向移动的迭代器。
对于反向迭代器，递增（以及递减）操作的含义会颠倒过来。
递增一个反向迭代器（++it）会移动到前一个元素；递减一个迭代器（--it）会移动到下一个元素。

对于普通迭代器:
begin 返回一个指向容器首元素的迭代器，end 返回一个指向尾元素之后位置的迭代器。
对应反向迭代器:
rbegin 返回一个指向尾元素的迭代器，rend 返回一个指向容器首元素之前位置的迭代器。

sort(vec.begin(), vec.end()); // 按正常序从小到大排序
sort(vec.rbegin(), vec.rend()); // 按逆序排序：将最小元素放在 vec的末尾

注意: 使用反向迭代器要使用 递减运算符


*/

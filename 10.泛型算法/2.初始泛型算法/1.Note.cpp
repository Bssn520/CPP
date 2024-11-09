/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-09 16:14:09
 * @LastEditTime: 2024-11-09 19:36:19
 * @Description:
 *
 */

/*
1. 只读算法

只读算法只会读取其输入范围内的元素，而从不改变元素。比如 find count。
另一个只读算法 accumulate, 定义在头文件 numeric中。其接受三个参数，前两个指出了需要求和元素的范围，第三个参数是和的初值:
// 对vec 中的元素求和，和的初值是0
int sum = accumulate(vec.cbegin(), vec.cend(), 0);

算法和元素类型

accumulate 将第三个参数作为求和起点，这蕴含着一个编程假定：将元素类型加到和的类型上的操作必须是可行的。
// 错误：const char*上没有定义+运算符
string sum = accumlate(v,begin(), v.end(), "");
原因在于，如果我们传递了一个字符串字面值，用于保存和的对象的类型将是 const char*。如前所述，此类型决定了使用哪个+运算符。由于 const char*并没有+运算符，此调用将产生编译错误。

操作两个序列的算法

另一个只读算法是 equal ，用于确定两个序列是否保存相同的值。它将第一个序列中的每个元素与第二个序列中的对应元素进行比较，如果所有元素都对应相等，则返回 true；否则，返回 false。

equal(v.cbegin(), v.cend(), v2.cbegin());
equal 基于一个非常重要的假设：它假定第二个序列至少与第一个序列一样长。
此算法要处理第一个序列中的每个元素，它假定每个元素在第二个序列中都有一个与之对
应的元素。

ex04:
假定v 是一个 vector<double>，那么调用 accumulate(v.cbegin()，v.cend()，0); 有何错误（如果存在的话）？
结果默认是int类型的，精度会降低。

ex05:
在本节对名册 （roster）调用equa1 的例子中，如果两个名册中保存的都是C风格字符串而不是string，会发生什么？
equal会比较指针地址，而不是字符串值，比较的结果与string类型的不一致。

*/


/*
2. 写容器元素的算法

一些算法将新值赋予序列中的元素。当我们使用这类算法时，必须注意确保序列原大小至少不小于我们要求算法写入的元素数目。记住，算法不会执行容器操作，因此它们自身不可能改变容器的大小。

fill 函数接受一对迭代器表示一个范围，还接受一个值作为第三个参数。fill 将给定的值赋予输入序列中的每个元素。
// 将每个元素重置为 0
fill(vec.begin(), vec.end(), 0);
// 将容器的一个子序列设置为 10
fill(vec.begin(), vec.begin() + vec.size()/2, 10);

函数fill_n接受一个单迭代器、一个计数值和一个值。它将给定值赋予迭代器指向的元素开始的指定个元素：
fill_n(dest, n, val);

注意：我们传递的目标输入序列应该是有效的。

back_inserter

back_inserter 接受一个指向容器的引用，返回一个与该容器绑定的插入迭代器。
当我们通过此迭代器赋值时，赋值运算符会调用 push_back 将一个具有给定值的元素添加到容器中：
vector<int> vec;
auto it = back_inserter(vec);   // 通过它赋值会将元素添加到 vec中
*it = 42;   // vec 中现在有一个元素，值为42

fill_n(back_inserter(vec), 10, 0);  // back_inserter 创建一个插入选代器，添加10个元素到 vec


拷贝算法

拷贝（copy）算法是另一个向目的位置迭代器指向的输出序列中的元素写入数据的算法。此算法接受三个迭代器，前两个表示一个输入范围，第三个表示目的序列的起始位置。

int a1[] = {0,1,2,3,4,5,6};
int a2[sizeof(a1)/sizeof(*a1)];
// ret 指向拷贝到a2的尾元素之后的位置
auto ret = copy(begin(a1), end(a1), a2);    // 把 a1 的内容拷贝给 a2

replace 算法读入一个序列，并将其中所有等于给定值的元素都改为另一个值。
replace(v.begin(), v.end(), 0, 42); // 将所有值为0的元素改为42
如果我们希望保留原序列不变，可以调用 replace_copy, 此算法接受额外第三个迭代器参数，指出调整后序列的保存位置：
replace_copy(v.cbegin(), v.cend(), back_inserter(ivec), 0, 42);

*/

/*
重排容器元素的算法

sort 函数
sort函数会重排输入序列中的元素，使之有序，它是利用元素类型的 < 运算符来实现排序的。
sort(vec.begin(), vec.end());

unique 函数
unique函数会重排vector, 使得重复的元素出现在vector的末尾部分，该函数会返回一个指向不重复值范围末尾的迭代器(也就是重复区域的开头)。

*/

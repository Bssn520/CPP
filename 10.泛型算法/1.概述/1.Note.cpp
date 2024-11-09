/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-09 15:54:03
 * @LastEditTime: 2024-11-09 16:06:15
 * @Description: 泛型算法概述
 *
 */

/*
泛型算法概述

大多数算法都定义在头文件 algorithm 中。标准库还在头文件 numeric 中定义了一组数值泛型算法。

一般情况下，这些算法并不直接操作容器，而是遍历由两个迭代器指定的一个元素范围来进行操作。
ex:
auto result = find(vec.cbegin(), vec.cend(), val);
cout << "The value " << value
     << (result == vec.end() ? " 不存在" : " 存在") << endl;
传递给 find 的前两个参数是表示元素范围的迭代器，第三个参数是一个值。find
将范围中每个元素与给定值进行比较。它返回指向第一个等于给定值的元素的迭代器。

由于 find 操作的是迭代器，因此我们可以用同样的 find 函数在任何容器中查找值。


*/

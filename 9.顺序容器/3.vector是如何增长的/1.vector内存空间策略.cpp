/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-05 09:48:40
 * @LastEditTime: 2024-11-05 17:04:03
 * @Description: vector内存分配策略及操作函数
 *
 */
/*
vector对象是如何增长的

vector 和 string类型提供了一些成员函数，允许我们与它的实现中内存分配部分互动。
capacity 操作告诉我们容器在不扩张内存空间的情况下可以容纳多少个元素。
reserve 操作允许我们通知容器它应该准备保存多少个元素。

            容器大小管理操作:
c.shrink_to_fit()   // 请将 capacity() 减少为与size()相同大小
c.capacity()        // 不重新分配内存的情况下，c能容纳的元素最大数
c.reserve(n)        // 分配至少能容纳 n 个元素的内存空间
注意:
shrink_to_fit 只适用于 vector string deque;
capacity, reserve 只适用于 vector 和 string;
reserve 并不改变容器中元素的数量，它仅影响vector预先分配的多大的内存空间。

reserve(调用 reserve 永远也不会减少容器占用的内存空间):
只有当需要的空间 > 当前容量时，reserve调用才会改变 vector容量。
如果需求大小 <= 当前容量，reserve什么也不做。容器并不会退回内存空间。

resize:
resize 成员函数只改变容器中元素的数目，而不是容器的容量。我们同样不能使用 resize
来减少容器预留的内存空间。

capacity 和 size:
容器的size 是指它已经保存的元素的数目；而
capacity则是在不分配新的内存空间的前提下它最多可以保存多少元素。

shrink_to_fit:
可以调用 shrink_to_fit 来要求 vector 将超出当前大小的多余内存退回给系统：
ivec.shrink_to_fit(); // 要求归还内存

注意: 调用 shrink_to_fit 只是一个请求，标准库并不保证退还内存。


虽然不同的实现可以采用不同的分配策略，但所有实现都应遵循一个原则：确保用push_back
向vector 添加元素的操作有高效率。 从技术角度说，就是通过在一个初始为空的 vector
上调用n次push back来创建一个n个元素的 vector，所花费的时间不能超过n的常数倍。

*/

#include <iostream>
#include <vector>

int main(int argc, const char **argv)
{
    std::vector<int> iv;
    std::cout << "size: " << iv.size() << " "
              << "capacity: " << iv.capacity() << std::endl;

    for (int i = 0; i != 100; ++i)
    {
        iv.push_back(i);
        std::cout << "size: " << iv.size() << " "
                  << "capacity: " << iv.capacity() << std::endl;
    }

    iv.shrink_to_fit();
    std::cout << "size: " << iv.size() << " "
              << "capacity: " << iv.capacity() << std::endl;

    return 0;
}

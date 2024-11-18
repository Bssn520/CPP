/*
关联容器操作

关联容器额外的类型别名:
key_type        // 此容器类型的关键字类型
mapped_type     // 每个关键字关联的类型；只适用于map
value_type      // 对于 set，与key_type相同；对于map，为 pair<const key_type, mapped_type>

对一个关联容器的迭代器进行解引用操作得到的是一个类型为容器的 value_type的值的引用。
对map而言, value_type 是一个 pair类型, 其first成员保存const的关键字，second成员保存值。

set的迭代器是 const的。

由于 map 的key, 以及 set的迭代器都是const，这也就意味着，很多泛型算法里对容器进行操作的算法都会失效，应该使用关联容器专用的算法。


2. 添加元素

向 map 添加元素:
c.insert(v)         // v 是 value_type 类型的对象; args 用来构造一个元素
c.emplace(args)     // 对于map 和 set只有当元素的关键字不在c中时才插入(或构造)元素。
c.insert(b, e)      // b, e是迭代器，表示一个c::value_type类型值的范围；il是这种值的花括号列表
c.insert(il)
c.insert(p, v)      // 类似 insert(v)(或 emplace(args）），但将迭代器 p 作为一个提示，指出从哪里开始搜索新元素应该存储的位置。返回一个迭代器，指向具有给定关键字的元素
c.emplace(p, args)  // 同上

检测 insert 的返回值
insert 或 emplace 的返回值依赖于容器的类型和参数。
对于不包含重复关键字的容器，添加单一元素的 insert 和 emplace 返回一个 pair,
该 pair 的 first 为一个迭代器，指向具有给定关键字的元素;
second 是一个 bool 值，指出元素插入成功失败与否(通过检查关键字是否已经存在)。


3. 删除元素

c.erase(k)  // 从 c 中删除每个关键字为 k 的元素。返回一个 size_type值，表示删除的元素的数量。
c.erase(p)  // 删除迭代器 p 所指向的元素。返回一个指向 p 之后元素的迭代器。
c.erase(b, e)   // 删除一个序列中的元素，返回 e


4. map 的下标操作

map 的下标运算符接受一个索引(一个关键字)，返回与该关键字相关联的值。当该关键字不存在时，创建一个元素并插入到 map。

map unordered_map 的下标操作:
c[k]        // 返回关键字为 k 的元素；如果不存在，则创建并进行值初始化
c.at[k]     // 访问关键字为 k 的元素，带参数检查；若不存在 k ，抛出 out_of_range异常


5. 访问元素

在一个关联容器中查找元素的操作:
注意: lower_bound, upper_bound 不适用于无序容器；下标和 at操作只适用于非const的map 和 unordered_map
c.find(k)   // 若存在，返回该元素的迭代器; 否则返回尾后迭代器
c.count(k)  // 返回关键字等于 k 的元素的数量
c.lower_bound(k)    // 返回一个迭代器，指向第一个关键字 不小于  k 的元素
c.upper_bound(k)    // 返回一个迭代器，指向第一个关键字 不大于  k 的元素
c.equal_range(k)    // 返回一个迭代器 pair，表示关键字等于k的元素的范围。若k不存在，pair 的两个成员均等于 c.end()

对于 map 使用 find 来代替下标操作
区别在于在关键字不存在时，是否需要创建它。

在 multimap, multiset 中查找元素的三个方法:
理论基础: 如果一个 multimap, multiset中有多个元素具有给定关键字，则这些元素在容器中会相邻存储。
(1):
    std::string search_item("author");
    auto entries = authors.count(search_item);
    auto iter = authors.find(search_item);
    while (entries)
    {
        std::cout << iter->second << std::endl;
        ++iter;
        --entries;
    }

(2):
使用 lower_bound, upper_bound查找重复关键字
    for (auto beg = authors.lower_bound(search_item),
              end = authors.upper_bound(search_item);
         beg != end; ++beg)
        std::cout << beg->second << endl;

(3):
equal_range 函数
本质上与前一个使用 upper bound 和 1ower_bound 的程序是一样的。不同之处就是，
没有用局部变量beg 和 end 来保存元素范围，而是使用了 equal_range 返回的 pair,
此pair 的 first 成员保存的迭代器与lower_bound 返回的迭代器是一样的，second 保存的迭代器与 upper
_bound 的返回值是一样的。

pos.first 等价于 beg，pos.second 等价于 end。
    for (auto pos = authors.equal_range(search_item);
         pos.first != pos.second; ++pos.first)
        std::cout << pos.first->second << endl;

*/

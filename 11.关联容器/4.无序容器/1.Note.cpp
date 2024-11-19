/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-18 21:18:30
 * @LastEditTime: 2024-11-19 11:02:46
 * @Description:
 *
 */

/*
无序关联容器

无序容器不使用比较运算符来组织元素，而是使用 哈希函数 和关键字类型的 == 运算符。

1. 使用无序容器

unordered_map, unordered_set 也支持 map, set 的操作(find, insert等)，无序容器也有允许重复关键字的版本。
因此，通常可以使用无序容器替换对应的有序容器，反之亦然。但是由于元素顺序不同，所以输出结果也会不同。

    std::unordered_map<std::string, size_t> word_count;
    std::string word;

    while (std::cin >> word)
    {
        if (word == "q")
            break;

        ++word_count[word];
    }

    for (const auto &w : word_count)
    {
        std::cout << w.first << " occous " << w.second
                  << ((w.second > 1) ? " times" : " time") << std::endl;
    }

2. 管理桶

无序容器在存储上组织为一组桶，每个桶包含零个或多个元素。
无序容器使用哈希函数将元素映射到桶，为了访问一个元素，容器首先计算元素的哈希值，它指出应该搜索哪个桶。
容器将具有相同哈希值的元素保存在相同的桶内。
如果容器允许重复关键字，所有具有相同关键字的元素都会在同一个桶。

无序容器管理操作:
桶接口
c.bucket_count()        // 正在使用的桶的数目
c.max_bucket_count()    // 容器能容纳的最多的桶的数量
c.bucket_size()         // 第 n 个桶中有多少个元素
c.bucket(k)             // 关键字为 k 的元素在哪个桶
桶迭代
local_iterator          // 可以用来访问桶中元素的迭代器类型
const_local_iterator    // 桶迭代器的const版本
c.begin(n), c.end(n)    // 桶 n 的首元素迭代器和尾后迭代器
c.cbegin(n), c.end(n)   // 与上面两个函数类似，但返回const版本
哈希策略
c.load_factor()         // 每个桶的平均元素数量，返回 float 值
c.max_load_factor()     // c 试图维护的平均桶大小，返回 float。c 会在需要时添加新桶，以使得 local_factor <= max_load_factor
c.rehash(n)             // 重组存储，使得 bucket_count >= n
c.reserve(n)            // 重组存储，使得 c 可以保存 n 个元素不必 rehash

*/

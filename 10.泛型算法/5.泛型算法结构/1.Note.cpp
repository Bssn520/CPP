/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-16 18:40:52
 * @LastEditTime: 2024-11-16 19:10:22
 * @Description:
 *
 */


/*
5类迭代器

输入迭代器      // 只读，不写；单遍扫描，只能递增
输出迭代器      // 只写，不读；单遍扫描，只能递增
前向迭代器      // 可读写；多遍扫描，只能递增
双向迭代器      // 可读写；多遍扫描，可递增递减
随机访问迭代器   // 可读写，多遍扫描，支持全部迭代器运算

2. 算法形参模式

alg(beg, end, other args);
alg(beg, end, dest, other args);
alg(beg, end, beg2, other args);
alg(beg, end, beg, end2, other args);

3. 算法命名规范

一些算法使用重载形式传递一个谓词:
unique(beg, end);
unique(beg, end, comp);

_if 版本的算法:
接受一个元素值的算法通常有另一个不同名的（不是重载的）版本，该版本接受一个谓词代替元素值。接受谓词参数的算法都有附加的 _if 前缀:
find(beg, end, val);        // 查找输入范围中val 第一次出现的位置
find_if(beg, end, pred);    // 查找第一个令pred 为真的元素

区分拷贝元素的版本与不拷贝元素的版本:

reverse(beg, end);              // 反转输入范围中元素的顺序
reverse_copy(beg, end, dest);   // 将元素按逆序拷贝到 dest

ex 41, 仅根据算法和参数的名字，描述下面每个标准库算法执行什么操作：
replace(beg, end, old_val, new_val);
replace_if(beg, end, pred, new_val);
replace_copy(beg, end, dest, old_val, new_val);
replace_copy_if(beg, end, dest, pred, new_val);
答:
replace(beg, end, old_val, new_val); // 在beg与end之间，如果是old_val则替换为new_val
replace_if(beg, end, pred, new_val); // 在beg与end之间，如果满足谓词条件则替换为new_val
replace_copy(beg, end, dest, old_val, new_val); // 在beg与end之间，如果是old_val则替换为new_val，不改变原始值，将结果复制到dest
replace_copy_if(beg, end, dest, pred, new_val); // 在beg与end之间，如果满足谓词条件则替换为new_val，不改变原始值，将结果复制到dest

特定容器算法:

list, forward_list 成员函数版本的算法:
lst.merge(lst2)         // 将来自 lst2的元素合并入1st。lst 和 lst2 都必须是有序的。
lst.merge(lst2, comp)   // 元素将从lst2中删除。在合并之后，lst2变为空。第一个版本使用<运算符；第二个版本使用给定的比较操作
lst.remove(val)         // 调用 erase 删除掉与给定值相等（==）或令一元谓词为真的每个元素
lst.remove_if(pred)     // 同上
lst.reverse()           // 反转 lst 中元素的顺序
lst.sort()              // 使用＜或给定比较操作排序元素
lst.sort(comp)          // 同上
lst.unique()            // 调用 erase 删除同一个值的连续拷贝。第一个版本使用==；第二个版本使用给定的二元谓词
lst.unique(pred)        // 同上

splice 成员
链表类型还定义了 splice 算法。此算法是链表数据结构所特有的。

list, forward_list 的splice成员函数的参数:
lst.splice(args) 或 flst.splice_after(args)

(p, lst2)           // p 是一个指向 1st 中元素的迭代器，或一个指向 flst 首前位置的迭代器。
函数将 lst2 的所有元素移动到 lst 中 p 之前的位置或是flst 中 p之后的位置。
将元素从 lst2中删除。lst2的类型必须与lst或flst 相同，且不能是同一个链表。

(p, lst2, p2)       // p2 是一个指向 lst2 中位置的有效的迭代器。将 p2指向的元素移动到 lst 中，或将 p2之后的元素移动到flst中。lst2可以是与 lst 或flst 相同的链表。

(p, lst2, b, e)     // b 和e 必须表示 lst2 中的合法范围。将给定范围中的元素从 lst2 移动到 lst 或flst。lst2 与 lst（或flst）可以是相同的链表，但p 不能指向给定范围中元素。

*/

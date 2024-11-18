/*
关联容器概述

1. 定义关联容器

值初始化

map<string, size_t> word_count; // 空容器
// 列表初始化
set<string> exclude = {...};
map<string, string> authors = { {"name1", "lastName1"},
                                {"name2", "lastName2"} };

初始化 multimap 和 multiset

vector<int> ivec;
for (vector<int>::size_type i = 0; i != 10; ++i)
{
    ivec.push_back(i);
    ivec.push_back(i);  // 每个数重复保存一次
}
set<int> iset(ivec.cbegin(), ivec.cend());
multiset<int> miset(ivec.cbegin(), ivec.cend());
cout << ivec.size() << endl; // 20
cout << iset.size() << endl; // 10
cout << miset.size() << endl; // 20

2. 关键字类型的要求

对于有序容器: map, multimap, set, multiset, 关键字类型必须定义元素比较的方法。默认情况下，标准库使用 < 运算符来比较两个关键字。

我们可以向算法提供一个我们自定义的比较操作，用来代替默认的 < 运算符， 所提供的操作必须是 严格弱序,可以将其看为 "小于等于", 具备以下性质:
两个关键字不能同时“小于等于”对方；如果k1 “小于等于”k2，那么k2绝不能“小于等于”k1。
如果k1“小于等于”k2，且k2“小于等于”k3，那么k1 必须 “小于等于”k3。
如果存在两个关键字，任何一个都不“小于等于”另一个，那么我们称这两个关键字是“等价”的。如果k1 “等价于”k2，且k2“等价于”k3，那么k1必须“等价于”k3。

对应 Saled_data 类型，并不支持 < 运算符，我们如何定义 Sales_data的multisrt呢?

compareIsbn 函数在 Sales_data 对象的 ISBN 成员上定义了一个严格弱序:
bool compareIsbn(const Sales_data &data1, const Sales_data data2)
{
    return data1.isbn() < data2.isbn();
}
为了使用自定义的操作，在定义multiset时提供两个类型:
(1). 关键字类型 Sales_data
(2). 比较操作类型，应该是一种函数指针
如下, 用 compareIsbn来初始化bookstore对象，效果是当向bookstore添加元素时，会自动根据自定义操作结果进行排序:
multiset<Sales_data, decltype(compareIsbn)*> bookstore(compareIsbn);


3. pair类型

pair的操作:
pair<T1, T2> p;     // p 是一个pair，两个类型分别是 T1, T2, 并进行了值初始化
pair<T1, T2> p(v1, v2)      // p是一个成员类型为T1 和T2的 pair; first 和second 成员分别用v1 和v2进行初始化
pair<T1, T2> p = {v1, v2};  // 等价于 p(v1, v2)
make_pair(v1, v2);  // 返回一个用 v1, v2 初始化的pair。pair的类型根据 v1, v2 进行推断

p.first     // 返回 p 的名为first的(公有)数据成员
p.second    // 返回 p 的名为second的(公有)数据成员
p1 relop p2 // 关系运算

p1 == p2    // 当 first 和 second 成员分别相等时，两个pair相等。
p1 != p2

创建pair对象的函数

pair<string, int> process(vector<string> &v)
{
    // ...处理 v
    if (!v.empty())
        return {v.back(), v.back().size()}; // 列表初始化
    else
        return pair<string, int>(); // 隐式构造返回值
}




*/

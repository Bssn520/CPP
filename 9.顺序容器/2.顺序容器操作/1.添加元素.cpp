/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-04 13:50:16
 * @LastEditTime: 2024-11-04 14:39:50
 * @Description: 向顺序容器内添加元素
 * 
 */


/*
向顺序容器内添加元素

这些操作会改变容器的大小；array 不支持这些操作。
forward_1ist 有自己专有版本的 insert 和 emplace
forward_1ist 不支持push_back 和 emplace_back
vector 和 string不支持 push_front 和 emplace_front

c.push_back(t)          // 在c的尾部创建一个值为t或由 args创建的元素。返回 void
c.emplace_back(args)    // 同上

c.push_front(t)         // 在c的头部创建一个值为t或由 args创建的元素。返回void
c.emplace_front(args)   // 同上

c.insert(p,t)           // 在迭代器P 指向的元素之前创建一个值为t或由 args 创建的元素。返回指向新添加的元素的迭代器
c.emplace(p,args)       // 同上

c.insert(p,n,t)         // 在迭代器p指向的元素之前插入n个值为t的元素。返回指向新添加的第一个元素的迭代器；若n为O，则返回 p

c.insert(p,b,e)         // 将迭代器b和e指定的范围内的元素插入到迭代器p指向的元素之前。b和e 不能指向。中的元素。返回指向新添加的第一个元素的迭代器：若范围为空，则返回p

c.insert(p,il)          // i1 是一个花括号包围的元素值列表。将这些给定值插入到迭代器p指向的元素之前。返回指向新添加的第一个元素的迭代器; 若列表为空，则返回p

注意: 向一个 vector、string或 deque 插入元素会使所有指向容器的选代器、引用和指针失效。

*/

/*
使用 push_back

push_back 将一个元素追加到一个容器的尾部。除 array forward_list之外，每个顺序容器都支持push_back。

对 string 对象进行 push_back("word") 等价于 s += "word";

*/

/*
使用 push_front

list, forward_list, deque 容器还支持 push_front 将元素插入到容器头部。

list<int> ilist;
for (int i = 0; i != 4; i++)
{
    ilist.push_front(i);
}
此循环将元素 0、1、2、3添加到ilist 头部。每个元素都插入到1ist 的新的开始位置。

*/

/*
在容器中的特定位置添加元素

insert 成员提供了更一般的添加功能，它允许我们在容器中任意位置插入0或多个元素。
vector, deque, list, string 都支持 insert 成员。forward_list提供了特殊版本的insert。

每个 insert 函数都接受一个迭代器作为其第一个参数, 将元素插入到迭代器所指定的位置之前。
slist.insert(iter, "hello"); // 将 "hello" 添加到iter之前的位置

vector<string> svec;
list<string> slist;
// 等价于调用 slist.push_front("hello");
slist.insert(slist.begin(), "hello");

// vector不支持 push_front, 但我们可以使用insert
// 警告：插入到 vector 末尾之外的任何位置都可能很慢，不建议这么干
svec.insert(svec.begin(), "hello");

*/

/*
插入范围内元素

除了第一个迭代器参数之外，insert 函数还可以接受更多的参数。
svec.insert(svec.end(), 10, "word");
这行代码将10个元素插入到svec 的末尾，并将所有元素都初始化次 string "word"

接受一对迭代器或一个初始化列表的 insert 版本将给定范围中的元素插入到指定位置之前：
vector<string> v = {"quasi", "simba", "frollo", "scar"};
// 将v的最后两个元素添加到 slist的开始位置
slist.insert(slist.begin(), v.end() - 2, v.end()); // 插到 slist 的开头
slist.insert(slist.end(), {"word1", "word2", "three"});
// 运行时错误：选代器表示要拷贝的范围，不能指向与目的位置相同的容器
slist.insert(slist.begin(), slist.begin(), slist.end());

在新标准下，接受元素个数或范围的 insert版本返回指向第一个新加入元素的迭代器。
（在旧版本的标准库中，这些操作返回 void。）
如果范围为空，不插入任何元素，insert 操作会将第一个参数返回。

*/

/*
使用 insert 的返回值

通过使用insert 的返回值，可以在容器中一个特定位置反复插入元素：
list<string> lst;
auto iter = lst.begin();
while (cin >> word)
    iter = lst.insert(iter, word);  // 等价于调用 push_front

*/

/*
使用 emplace 操作

新标准引人了 emplace_front, emplace, emplace_back 三个新成员，这些操作构造而不是拷贝元素。
这些操作分别对应 push_front, insert, push_back, 允许我们将元素放置在容器头部、一个指定位置之前或容器尾部。

emplace 函数在容器中直接构造元素。传递给 emplace函数的参数必须与元素类型的构造函数相匹配。
当我们调用一个 emplace 成员函数时，则是将参数传递给元素类型的构造函数。emplace 成员使用这些参数在容器管理的内存空间中直接构造元素。

// 假定 c保存Sales_data 元素
// 会调用 Sales_data在容器的指定内存空间内直接构造 Sales_data
c.emplace_back("822-2882292933", 25, 15.99);
// 错误：没有接受三个参数的 push_back版本
c.push_back("822-2882292933", 25, 15.99);
// 正确：创建一个临时的Sales_data 对象传递给 push_back
c.push_back(Sales_data("822-2882292933", 25, 15.99));

emplace 函数的参数根据元素类型而变化，参数必须与元素类型的构造函数相匹配：
// iter 指向 c中一个元素，其中保存了 Sales_ _data 元素
c.emplace_back();   // 使用 Sales_data的默认构造函数
c.emplace(iter, "999-9999999999");  // 使用 Sales_data(string)
c.emplace_front("822-2882292933", 25, 15.99);   // 使用接受3个参数的构造函数

*/
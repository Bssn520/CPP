/*
动态内存

动态分配的对象的生存期与它们在哪里创建是无关的，只有当被显式的释放时，这些对象才会销毁。

除了静态内存和栈内存，每个程序还拥有一个内存池。这部分内存被称作自由空间或堆。
程序用堆来存储动态分配的对象，即那些在程序运行时分配的对象。

1. 动态内存与智能指针

智能指针的行为类似于常规指针，区别在于它负责自动释放所指向的对象。
标准库提供的两种智能指针主要区别在于管理底层指针的方式:
shared_ptr: 允许多个指针指向同一个对象。
unique_ptr: “独占”所指向的对象。
标准库还定义了一个名为 weak_ptr 的伴随类，指向 shared_ptr 所管理的对象。

shared_ptr 和 unique_ptr 都支持的操作:
shared_ptr<T> sp    // 空智能指针，可以指向类型为 T 的对象
unique_ptr<T> up
P       // 将 p 用作一个条件判断，若 p 指向一个对象，则为 true
*p      // 解引用 p，获得它所指向的对象
p->mem      // 等价于 (*p).mem
p.get()     // 返回 p 中保存的指针。
swap(p, q)  // 交换 p 和 q 中的指针
p.swap(q)

shared_ptr 特有的操作:
make_shared<T> (args)   // 返回一个 shared_ptr, 指向一个动态分配的类型为 T 的对象。使用 args 初始化此对象
shared_ptr<T> p(q)      // p 是 shared_ptr q 的拷贝, 此操作会递增 q 的计数器。q 中的指针必须能转换成 T*
p = q       // p 和 q 都是 shared_ptr，所保存的指针必须能相互转换。此操作会递减 p 的引用计数，递增 q 的引用计数；若 p 的引用计数变为 0，则将其管理的原内存释放
p.unique()  // 若 p.use_count() 为 1，返回 true；否则返回 false
p.use_count()   // 返回与 p 共享对象的智能指针数量；可能很慢，主要用于调试

make_shared 操作:
此函数在动态内存中分配一个对象并初始化它，返回指向此对象的 shared_ptr。
指向一个值为42的int的shared_ptr:
shared_ptr<int> p3 = make_shared<int>(42);
指向一个值为"9999999999"的string:
shared_ptr<string> p4 = make_shared<string>(10, "9");
指向一个值初始化的int:
shared_ptr<int> p5 = make_shared<int>();
make_shared 用参数来构造给定类型的对象(构造函数)。

shared_ptr 的拷贝与赋值

可以认为每一个 shared_ptr 都有一个关联的计数器，通常称之为引用计数。
无论何时我们拷贝一个 shared_ptr ，计数器都会递增。
比如，当用一个shared_ptr初始化另一个shared_ptr，或将它作为参数传递给一个函数以及作为函数的返回值时，它所关联的计数器就会递增。
当给shared_ptr赋予一个新值或是shared_ptr被销毁时，计数器就会递减。

一旦一个shared_ptr的计数器变为0，它就会自动释放自己所管理的对象:
auto r = make_shared<int>(42);
r = q;  // 递增 q 所指向对象的引用计数；递减 r 原来指向对象的引用计数；r 原来指向的对象已没有引用者，会自动释放

shared_ptr 自动销毁所管理的对象......
当指向一个对象的最后一个shared_ptr被销毁时，shared_ptr类会自动通过 析构函数 销毁此对象；
类似于构造函数，每个类都有一个析构函数，析构函数控制对象销毁时做什么操作。
shared_ptr的析构函数会递减它所指向的对象的引用计数。如果变为0，shared_ptr的析构函数就会销毁对象，并释放内存。

......shared_ptr还会自动释放相关联的内存
std::shared_ptr<int> use_factor()
{
    std::shared_ptr<int> p = std::make_shared<int>();

    return p;   // 返回 p 时，引用计数进行了递增操作
}   // p 离开了作用域，但它所指向的内存不会被释放

使用了动态生存期的资源的类

程序使用动态内存出于以下三种原因之一:
1. 程序不知道自己需要使用多少对象
2. 程序不知道所需对象的准确类型
3. 程序需要在多个对象间共享数据

当一个vector被销毁时，其中的元素也都被销毁。
但某些时候，我们希望对象间的不同拷贝共享相同的元素。即，当我们拷贝一个对象时，原对象及其拷贝应该引用相同的底层元素。

定义 strBlob 类


2. 直接管理内存

C++语言定义了两个运算符来分配和释放动态内存:
new: 在动态内存中为对象分配空间并返回一个指向该对象的指针。
delete: 接受一个动态对象的指针，销毁该对象，并释放与之关联的内存。

相较于智能指针，使用 new, delete 元素符管理内存容易出错。

使用 new 动态分配和初始化对象

在自由空间分配的内存是无名的，因此 new 无法为其分配的对象命名，而是返回一个指向该对象的指针。
此new 表达式在自由空间构造一个 int 型对象，并返回指向该对象的指针:
int *pi = new int; // pi 指向一个动态分配的、未初始化的无名对象

默认情况下，动态分配的对象是默认初始化的，这意味着内置类型或组合类型的对象的值是未定义的，类类型对象将使用默认构造函数进行初始化。

也可以使用直接初始化方式:
string* ps = new string(10, "9");
int* pi = new int(1024);
vector<int> *pv = new vector<int>{0,1,2,3};

对动态分配的对象进行值初始化:
string *ps1 = new string; // 默认初始化为空string
string *ps2 = new string(); // 值初始化为空string
int *pi1 = new int; // 默认初始化，*pi1的值未定义
int *pi2 = new int(); // 值初始化为0

使用 auto 进行初始化:
auto p1 = new auto(obj);    // p 指向一个与 obj 类型相同的对象，该对象用 obj 进行初始化
auto p2 = new auto(a, b, c);    // 错误: 括号中只能有单个初始化器

动态分配的 const 对象

const int *pci = new const int(1024);
const string *pcs = new string;

内存耗尽

new表达式失败时，会抛出 std::bad_alloc 类型的异常，可以向 new 传递额外的参数来阻止其抛出异常:
int *p1 = new int;  // 如果分配失败，new 抛出 std::bad_alloc
int *p2 = new (nothrow) int;    // 如果分配失败，new 返回一个空指针

释放动态内存

传递给 delete 的指针必须指向动态分配的内存，或者是一个空指针，释放一块非 new 分配的内存，或者多次释放相同的指针，其行为是未定义的。

delete 之后重置指针值

空悬指针，即，指向一块曾经保存数据对象但现在已经无效的内存的指针。

可以通过在指针即将要离开其作用域之前释放掉它所关联的内存。这样，在指针关联的内存被释放掉之后，就没有机会继续使用指针了。
如果需要继续保留指针，可以在 delete 后将 nullptr 赋予给指针，这样就清楚地指出指针不指向任何对象。

int* p(new int(42));    // p 指向动态内存
auto q = p;     // p 和 q 指向相同的内存
delete p;       // 释放内存后，p 和 q 均变为无效
p = nullptr;    // 指出 p 不再绑定到任何对象


3. shared_ptr 和 new 结合使用

定义和改变 shared_ptr 的其他方法:
shared_ptr<T> p(q)      // p 管理内置指针 q 所指向的对象；q 必须指向new分配的内存，且能转换为 T* 类型
shared_ptr<T> p(u)      // p 从 unique_ptr 那里接管对象的所有权；将 u 置为空
shared_ptr<T> p(q, d)   // p 接管了内置指针 q 所指向的对象的所有权。q 必须能转换为 T* 类型。p 将使用可调用对象 d 来代替 delete
shared_ptr<T> p(p2, d)  // p 是 shared_ptr p2 的拷贝，唯一的区别是, p 将用 d 来代替 delete
p.reset()       // 若 p 是唯一指向其对象的 shared_ptr, reset 会释放此对象
p.reset(q)      // 若传递了可选的参数内置指针 q，会令 p 指向 q，否则会将 p 置为空
p.reset(q, d)   // 若还传递了参数d，将会调用d而不是 delete 来释放 q

不要混合使用普通指针和智能指针......
由于我们无法知道对象何时被释放，所以使用一个内置指针来访问一个智能指针所负责的对象是很危险的。
..... 不要使用 get 初始化另一个智能指针或为智能指针赋值
智能指针类型的 get 函数返回一个内置指针，指向智能指针管理的对象。
注意：使用 get 返回的指针的代码不能 delete 此指针。
shared_ptr<int> p(new int(42)); // 引用计数为 1
int *q = p.get();   // 正确，但要注意，不能让 q 管理的指针被释放
{   // 新程序块
    shared_ptr<int>(q);
}   // 程序块结束，q 被销毁，它指向的内存被释放
int foo = *p; // 未定义: p 指向的内存已经被释放了

其他 shared_ptr 操作

使用 reset 来将一个新的指针赋予一个 shared_ptr:
p = new int(1024);      // 错误: 不能将一个指针赋予 shared_ptr
p.reset(new int(1024)); // 正确: p 指向一个新对象


4. 智能指针和异常

智能指针和哑类

正确使用智能指针的基本规范：
(1). 不使用相同的内置指针值初始化(或reset)多个智能指针。
(2). 不 delete get() 返回的指针。
(3). 不使用 get() 初始化或 reset 另一个智能指针。
(4). 如果使用了 get() 返回的指针，应当记住在最后一个对应的智能指针销毁后，指针就变为无效了。
(5). 如果使用智能指针管理的资源不是 new 分配的内存，记住传递给它一个删除器。


5. unique_ptr

一个 unique_ptr “拥有”它所指向的对象。与 shared_ptr 不同，某个时刻只能有一个 unique_ptr 指向一个给定的对象。当 unique_ptr 被销毁时，它所指向的对象也被销毁。

定义 unique_ptr 时，需要将其绑定到一个 new 返回的指针上。初始化 unique_ptr 必须采用直接初始化形式:
unique_ptr<double> p1;
unique_ptr<int> p2(new int(42));

由于一个 unique_ptr 拥有它指向的对象，因此 unique_ptr 不支持普通的拷贝或赋值:
unique_ptr<string> p1(new string("something"));
unique_ptr<string> p2(p1); // 错误：unique_ptr 不支持拷贝
unique_ptr<string> p3;
p3 = p2;    // 错误: unique_ptr 不支持赋值

unique_ptr 操作:
unique_ptr<T> u1        空 unique_ptr ，可以指向类型为 T 的对象。u1 使用 delete 来释放指针
unique_ptr<T, D> u2     同上，不过 u2 使用类型为 D 的可调用对象来释放指针
unique_ptr<T, D> u(d)   空 unique_ptr，指向类型为 T 的对象，用类型为 D 的对象 d 代替 delete
u = nullptr     释放 u 指向的对象，将 u 置为空
u = release()   u 放弃对指针的控制权，返回指针，并将 u 置为空
u = reset()     释放 u 指向的对象
u = reset(q)    如果提供了内置指针 q，令 u 指向这个对象；否则将 u 置为空
u = reset(nullptr)

虽然 unique_ptr 不支持拷贝或赋值，但可以通过调用 release 或 reset 将指针的所有权从一个(非const)unique_ptr转移给另一个 unique:
将所有权从 p1 转移给 p2:
unique_ptr<string> p2(p1.release());    // release 将 p1 置为空
unique_ptr<string> p3(new string("Text"));
将所有权从 p3 转移给 p2
p2.reset(p3.release());

传递 unique_ptr 参数和返回 unique_ptr
不能拷贝 unique_ptr 的规则有一个例外：我们可以拷贝或赋值一个将要被销毁的unique_ptr。
unique_ptr<int> clone(int p)
{
    正确: 从 int* 创建一个 unique_ptr<int>:
    return unique_ptr<int>(mew int(p));
}
还可以返回一个局部对象的拷贝:
unique_ptr<int> clone(int p)
{
    unique_ptr<int> ret(new int(p));
    // ...
    return ret;
}
对于上面两段代码，编译器都知道要返回的对象将要被销毁。在此情况下，编译器执行一种特珠的“拷贝”。

向 unique_ptr 传递删除器

p 指向一个类型为 objT 的对象，并使用一个类型为 delT 的对象释放 objT 对象
unique_ptr<ObjT, delT> p(new ObjT, fcn); // 会调用一个名为 fcn 的 delT 类型对象


6. weak_ptr

weak ptr是一种不控制所指向对象生存期的智能指针，它指向由一个 shared_ptr 所管理的对象。
将 weak_ptr 绑定到 shared_ptr 不会改变 shared_ptr 的引用计数。

weak_ptr:
weak_ptr<T> w       空 weak_ptr 可以指向类型为 T 的对象
weak_ptr<T> w(sp)   与 sahred_ptr sp 指向相同对象的weak_ptr。T 必须能转换为 sp 指向的类型
w = p           p 是一个 shared_ptr 或 weak_ptr。赋值后 w 与 p 共享对象
w.reset()       将 w 置为空
w.use_count()   与 w 共享对象的 shared_ptr 的数量
w.expired()     若 w.use_count() 为 0，返回 true，否则返回 false
w.lock()        如果 expired 为true，返回一个空 shared_ptr；否则返回一个指向 w 的对象的 shared_ptr

要使用一个 shared_ptr 来初始化 weak_ptr:
auto p = make_shared<int>(42);
weak_ptr<int> wp(p); // wp 弱共享 p; p 的引用计数未改变

由于对象可能不存在，我们不能使用 weak_ptr 直接访问对象，必须调用 lock, lock 会检查 weak_ptr 指向的对象是否仍然存在，如果存在返回一个指向共享对象的 shared_ptr; 否则返回一个空的 shared_ptr:
if (shared_ptr<int> np = wp.lock) // 如果 np 不为空则条件成立
{
    ...
}

核查指针类




*/

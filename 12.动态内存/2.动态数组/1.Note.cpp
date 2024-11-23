/*
动态数组

1. new 和数组

int *pia = new int[get_size()]; // 分配 get_size 个int, pia 指向第一个 int

分配一个数组会得到一个元素类型的指针
当使用 new 分配一个数组时，我们得到的是一个数组元素类型的指针，而非一个数组类型的对象。

初始化动态分配对象的数组

默认情况下，new 分配的对象都是默认初始化的，可以在大小后跟一对空括号来进行值初始化:
int *pia = new int[10]; // 10 个未初始化的int
int *pia2 = new int[10](); // 10 个值初始化为 0 的int
int *pia3 = new int[3](1, 2, 3); // 使用列表初始化

new int[0]; // 是合法的

释放动态数组

delete p;       // p 必须指向一个动态分配的对象或为空
delete [] pa;   // pa 必须指向一个动态分配的数组或为空
第二条语句销毁 pa 指向的数组中的元素，并释放内存；元素销毁是逆向的，即先销毁 最后一个元素...

智能指针和动态数组

unique_ptr<int[]> up(new int[10]); // up 指向一个包含10个未初始化int的数组
up.release();   // 自动调用 delete[] 销毁其指针

指向数组的 unique_ptr:
指向数组的 unique_ptr 不支持成员运算符;
unique_ptr<T[]> u // u 指向一个动态分配的数组，元素类型为 T
unique_ptr<T[]> u(p) // 指向内置指针 p 所指向的动态分配的数组。p 必须能转化为类型 T*
u[i]    // 返回 u 拥有的数组中位置 i 处的对象

shared_ptr 不能直接管理动态数组，如果希望使用 shared_ptr 管理动态数组，需要提供自定义的删除函数:
shared_ptr<int> sp(new int[10], [](int *p){ delete[] p; });

shared_ptr 未定义下标运算符，而且智能指针类型不支持指针算术运算。因此，为了访问数组中的元素，必须用 get 获取一个内置指针，然后用它来访问数组元素。

2. allocator 类

allocator 旨在将内存申请与对象构造分离, 意味着我们可以分配大块内存，但只在真正需要是才真正的执行对象创建操作。

allocator 是一个模版，在定义时，需要指明这个 allocator 可以分配的对象类型:
allocator<string> alloc;    // 可以分配 string 的 allocator 对象
auto const p = alloc.allocate(n); // 分配 n 个未初始化的 string

标准库 allocator 类及其算法:
allocator<T> a          // 定义了一个名为 a 的 allocator 对象，可以为 类型为 T 的对象分配内存
a.allocate(n)           // 分配一段原始的，未构造的内存，保存 n 个类型为 T 的对象
a.deallocate(p, n)      // 释放从 T* 指针 p中地址开始的内存，这块内存保存了 n 个类型为 T 的对象；
p 必须是 allocate 返回的指针，且 n必须是 p创建时所要求的大小。调用 deallocate 之前，必须对象每个在这块内存中创建的对象调用 destroy
a.construct(p, args)    // p 必须是一个类型为 T* 的指针，指向一块原始内存；arg 被传递给类型为 T 的构造函数，用来在 p 指向的内存中构造一个对象
a.destroy(p)    // p为 T* 类型的指针，此算法对 p 指向的对象执行析构函数

allocate 分配未构造的内存
allocate 分配的内存是未构造的。construct 成员函数接受一个指针和额外参数，在给定位置构造一个元素。
auto q = p; // q 指向最后构造的元素之后的位置
alloc.construct(q++);           // *q 为空字符串
alloc.construct(q++, 10, 'c');  // *q 为 cccccccccc
alloc.construct(q++, "hi");     // *q 为 hi

当使用完对象后，必须对每个构造的元素调用 destroy 来销毁它们:
while(q != p)
    alloc.destroy(--q);
在循环开始处，q指向最后构造的元素之后的位置。我们在调用 destroy 之前对q进行了递减操作。
因此，第一次调用 destroy 时，q指向最后一个构造的元素。
最后一步循环中我们 destroy 了第一个构造的元素，随后q将与p 相等，循环结束。

注意: 只能对真正构造了的元素进行 destroy 操作。

一旦元素被销毁，我们可以重新使用这部分内存来保存其他 string, 也可以将其归还给系统:
alloc.deallocate(p, n);
传递给 deallocate 的指针不能为空，它必须指向由allocate 分配的内存。
而且，传递给 dealocate 的大小参数必须与调用 allocated 分配内存时提供的大小参数具有一样的值。

拷贝和填充未初始化内存的算法

uninitialized_copy(b, e, b2)    从迭代器 b 和 e 指出的输出范围中拷贝元素到迭代器 b2 指定的未构造的原始内存中
uninitialized_copy_n(b, n, b2)  从迭代器 b 指向的元素开始，拷贝 n 个元素到 b2开始的内存中
uninitialized_fill(b, e, t)     在迭代器 b和 e指定的原始内存范围中创建对象，对象的值均为 t的拷贝
uninitialized_fill_n(b, n, t)   从迭代器 b 指向的内存地址开始创建 n个对象

*/

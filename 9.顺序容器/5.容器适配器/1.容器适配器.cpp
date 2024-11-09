/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-07 21:32:37
 * @LastEditTime: 2024-11-08 16:53:15
 * @Description: 
 * 
 */
/*
容器适配器

适配器（adaptor）是标准库中的一个通用概念。本质上，一个适配器是一种机制，能使某种事物的行为看起来像另外一种事物一样。
一个容器适配器接受一种己有的容器类型，使其行看起来像一种不同的类型。

所有容器适配器都支持的操作和类型:
size_type       // 一种类型，足以保存当前类型的最大对象的大小
value_type      // 元素类型
container_type  // 实现适配器的底层容器类型
A a;            // 创建一个名为a 的空适配器
A a(c);         // 创建一个名为a 的适配器，带有容器c的一个拷贝
关系运算符        // 每个适配器都支持所有关系运算符： ==、 !=、＜、＜=、＞和>=这些运算符返回底层容器的比较结果
a.empty()       // 若a 包含任何元素，返回 false，否则返回true
a.size()        // 返回a 中的元素数目
swap(a, b)      // 交换a 和b的内容，a和b必须有相同类型，包括底层容器类型也必须相同
a.swap(b)       // 同上

*/

/*
定义一个适配器

每个适配器都定义两个构造函数: 默认构造函数创建一个空对象; 接受一个容器的构造函数拷贝该容器来初始化适配器。

stack<int> stk(deq);    // 从 deq 拷贝元素到 stk

默认情况下，stack和queue是基于deque实现的，priority_queue是在vector上实现的。我们可以传递一个顺序容器来重载默认容器类型:
// 基于 vector 实现的空栈
stack<string, vector<string>> str_stk;
// str_stk2 在vector上实现, 初始化时保存svec的拷贝
stack<string, vector<string>> str_stk2(svec);

所有适配器都要求容器具有添加，删除以及访问尾元素的能力。

栈适配器

stack 类型定义在 stack头文件中。

stack<int> intStack;

for (int i = 0; i != 10; ++i)
    intStack.push(i);

while (!intStack.empty())
{
    int value = intStack.top();  // 获取栈顶值
    intStack.pop();     // 弹出栈顶元素，继续循环
}

栈操作:
s.pop()             // 删除栈顶元素，但不返回该元素值
s.push(item)        // 创建一个新元素压入栈顶，该元素通过拷贝或移动item而来，或由args构造
s.emplace(args)     // 同上
s.top()             // 返回栈顶元素，但不将元素弹出栈

队列适配器

queue 和 priority_queue 适配器定义在 queue 头文件中。

queue 和 priority_queue 操作:
queue 默认基于 deque 实现，priority_queue 默认基于 vector 实现;
queue 也可以用 list 或 vector 实现，priority_queue 也可以用 deque 实现;
q.pop()     // 返回 queue 的首元素或 priority_queue 的最高优先级的元素，但不删除此元素
q.front()   // 返回首元素或尾元素，但不删除此元素
q.back()    // 只适用于 queue
q.top()     // 返回最高优先级元素，但不删除该元素只适用于 priority_queue
q.push(item) // 在 queue 木尾或 priority_queue 中恰当的位置创建一个元素，其值为item，或者由 args 构造
q.emplace(args) // 同上



*/

### 7.2 访问说明符

#### 在C++中, 我们使用访问说明符加强类的封装性:

- 定义在 `public` 说明符后的成员在整个程序内可被访问, public 成员定义类的接口。

- 定义在 `private` 说明符之后的成员可以被类的成员函数访问，但是不能被使用该类的代码访问，private 部分封装了（即隐藏了）类的实现细节。

- 注: 一个类可以包含0个或多个访问说明符，而且对于某个访问说明符能出现多少次也没有严格限定。每个访问说明符指定了接下来的成员的访问级别，其有效范围直到出现下一个访问说明符或者到达类的结尾处为止。

#### 使用 class 或 struct 关键字

- 使用 class 和struct定义类唯一的区别就是默认的访问权限:
- `class`关键字: 定义在第一个访问说明符之前的成员是 public 的。
- `struct`关键字: 与`class`关键字相反。


### 7.2.1 友元

> 类可以允许其他类或者函数访问它的非公有成员，方法是令其他类或者函数成为它的友元。如果类想把一个函数作为它的友元，只需要增加一条以 `friend` 关键字开始的函数声明语句。

#### 友元的声明

友元的声明仅仅指定了访问的权限，而非一个通常意义上的函数声明。如果希望类的用户能够调用某个友元函数，那么就必须在友元声明之外再专门对函数进行一次声明。

为了使友元对类的用户可见，我们通常把友元的声明与类本身放置在同一个头文件中（类的外部）。

```cpp

/** Person 类 */
struct Person;
/** 读取一个 Person 实例 */
std::istream &read(std::istream &is, Person &item);
/** 打印一个 Person 实例 */
std::ostream &print(std::ostream &os, const Person &item);


class Person
{
// 友元声明
friend std::istream &read(std::istream &is, Person &item);
friend std::ostream &print(std::ostream &os, const Person &item);

public:
...

private:
...

}

/** read print 函数的实现 */
...

```



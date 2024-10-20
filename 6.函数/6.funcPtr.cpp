#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

/**
 * 函数指针
 * 
 * 函数指针指向的是函数而不是对象。和其他指针一样，函数指针指向某种特定类型。函数的类型由它的返回类型和形参类型共同决定，与函数名无关。
 * 
 * bool lengthCompare(const string&, const string&);
 * 该函数的类型是 bool(const string&， const string&)。要想声明一个可以指向该函数的指针，只需要用指针替换函数名即可：
 * // Pf 指向一个函数，该函数的参数是两个 const string 的引用，返回值是bool类型
 * bool (*pf)(const string&, const string&);
 * 
 * 从我们声明的名字开始观察，pf 前面有个*，因此pf 是指针；
 * 右侧是形参列表，表示pf 指向的是函数；
 * 再观察左侧，发现函数的返回类型是布尔值。
 * 因此，pf 就是一个指向函数的指针，其中该函数的参数是两个 const string 的引用，返回值是bool类型。
 * 
 */

/**
 * 使用函数指针
 * 
 * 当我们把函数名作为一个值使用时，该函数自动地转换成指针。
 * 
 * pf = lengthCompare;      // pf 指向名为lengthCompare的函数
 * pf = &lengthCompare;     // 等价的赋值语句: 取地址符是可选的
 * 
 * 此外，我们还能直接使用指向函数的指针调用该函数，无须提前解引用指针：
 * bool b1 = pf("hello", "goodbye");            // 调用lengthCompare函数
 * bool b2 = (*pf)("hello", "goddbye");         // 一个等价的调用
 * bool b3 = lengthCompare("hello", "goodbye"); // 另一个等价的调用
 * 
 * 在指向不同函数类型的指针间不存在转换规则。但是和往常一样，我们可以为函数指针赋一个 nullptr或者值为0的整型常量表达式，表示该指针没有指向任何一个函数。
 * 
 */

/**
 * 重载函数的指针
 * 
 * 当我们使用重载函数时，上下文必须清晰地界定到底应该选用哪个函数。
 * void ff(int*);
 * void ff(unsigned int);
 * 
 * void (*pf1)(unsigned int) = ff;  // pf1指向ff(unsigned)
 * 编译器通过指针类型决定选用哪个函数，指针类型必须与重载函数中的某一个精确匹配
 * void (*pf2)(int) = ff;           // 错误：没有任何一个 ff 与该形参列表匹配
 * double (*pf3)(int*) = ff;        // 错误：ff 和 pf3 的返回类型不匹配
 * 
 */

/**
 * 函数指针形参
 * 
 * 和数组类似，虽然不能定义函数类型的形参，但是形参可以是指向函数的指针。此时，形参看起来是函数类型，实际上却是当成指针使用：
 * // 第三个形参是函数类型，它会自动地转换成指向函数的指针
 * void useBigger(const string &s1, const string &s2,
 *               bool pf(const string &, const string &));
 * 
 * // 等价的声明：显式地将形参定义成指向函数的指针
 * void useBigger(const string &s1, const string &s2,
 *               bool (*pf)(const string &, const string &));
 * 
 * 
 * 使用类型别名和decltype简化使用函数指针的代码:
 * // Func 和 Func2是函数类型
 * typedef bool Func(const string&, const string&);
 * typedef decltype(lengthCompare) Func2;       // 等价的类型
 * 
 * // FuncP 和 FuncP2 是指向函数的指针
 * typedef bool(*FuncP)(const string&, const string&);
 * typedef decltype(lengthCompare) *FuncP2;     // 等价的类型
 * 
 */

/**
 * 返回指向函数的指针
 * 
 * 和数组类似，虽然不能返回一个函数，但是能返回指向函数类型的指针。
 * 然而，我们必须把返回类型写成指针形式，编译器不会自动地将函数返回类型当成对应的指针类型处理。
 * 与往常一样，要想声明一个返回函数指针的函数，最简单的办法是使用类型别名：
 * using F = int(int*, int);        // F是函数类型, 不是指针
 * using FP = int(*)(int*, int);    // FP是指针类型
 * 
 * FP f1(int);      // 正确：FP 是指向函数的指针，f1返回指向函数的指针
 * F f1(int);       // 错误：F是函数类型，f1 不能返回一个函数
 * F *f1(int);      // 正确：显式地指定返回类型是指向函数的指针
 * 也可以直接声明 f1:
 * int (*f1(int))(int*, int);
 * 使用尾置返回类型:
 * auto f1(int) -> int (*)(int*, int);
 * 
 */

/**
 * 将auto和decltype用于函数指针类型
 * 
 * 如果我们明确知道返回的函数是哪一个，就能使用 decltype 简化书写函数指针返回类型的过程。
 * 
 * 例如假定有两个函数，它们的返回类型都是 string：：size_type，并且各有两个 const string&类型的形参，
 * 此时我们可以编写第三个函数，它接受一个string类型的参数，返回一个指针，该指针指向前两个函数中的一个：
 * string::size_type sumLength(const string&, const string&);
 * string::size_type largerLength(const string&, const string&);
 * // 根据其形参的取值，getFcn 函数返回指向 sumLength或者 largerLength 的指针
 * decltype(sumLength) *getFcn(const string &);
 * 
 */

/**
 * ex 6.54
 * 
 * 编写函数的声明，令其接受两个 int 形参并且返回类型也是 int; 然后声明一个 vector 对象，令其元素是指向该函数的指针。
 * 
 * vector<int (*)(int, int)> pv;
 * 
 * int func(int, int);
 * using funcP = int (*)(int, int);
 * vector<funcP> funcPtr;
 * 
 * using funcP1 = decltype(func) *;
 * using funcP2 = decltype(func);
 * typedef decltype(func) *funcP3;
 * using funcP4 = int (*)(int, int);
 * using funcP5 = int (int, int);
 * typedef int(*funcP6)(int, int);
 * 
 * vector<funcP1> pv1;
 * vector<funcP2 *> pv2;
 * vector<funcP3> pv3;
 * vector<funcP4> pv4;
 * vector<funcP5 *> pv5;
 * vector<funcP6> pv6;
 * 
 */

/**
 * 编写4个函数，分别对两个 int 值执行加、减、乘、除运算：在上一题创建的 vector 对象中保存指向这些函数的指针。
 */

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return b == 0 ? 0: a / b; }


int main()
{
    vector<int (*)(int, int)> vf;

    vf.push_back(add);
    vf.push_back(subtract);
    vf.push_back(multiply);
    vf.push_back(divide);

    // 调用上述 vector 对象中的每个元素并输出其结果
    int i = 6, j = 3;
    cout << "add: " << vf[0](i, j) << endl
         << "subtract: " << vf[1](i, j) << endl
         << "mutiply: " << vf[2](i, j) << endl
         << "divide: " << vf[3](i, j) << endl;

    // 使用范围for语句
    for (const auto &funcPtr : vf)  // 使用引用避免无意义的拷贝
        cout << funcPtr(i, j) << endl;

    return 0;
}



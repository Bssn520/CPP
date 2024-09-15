#include <iostream>
using namespace std;

/**
 * const 限定符
 * 
 * 有时我们希望定义这样一种变量，它的值不能被改变。
 * 例如，用一个变量来表示缓冲 区的大小。
 * 使用变量的好处是当我们觉得缓冲区大小不再合适时，很容易对其进行调整。 
 * 另一方面，也应随时警惕防止程序一不小心改变了这个值。
 * 为了满足这一要求，可以用关 键字 const对变量的类型加以限定。
 */
int main()
{
    /**
     * 默认状态下，const对象只在当前文件内有效
     * 
     * 编译器在编译过程中会把用到该变量的地方全部替换为对应的值。
     * 
     * 如果想要在多个文件中共享const对象，必须在变量的定义前添加extern关键字。
     * // file1.cpp 定义并初始化了一个常量，该常量能被其他文件访问
     * extern const int bufSize = fun();
     * // file1.h 头文件
     * extern const int bufSize; // 与file1.cpp 中定义的bufSize是同一个
     * 
     */
    extern const int bufSize;

    /**
     * const的引用
     * 
     * 可以把引用绑定到const 对象上，就像绑定到其他对象上一样，我们称之为对常量的引用。
     * 与普通引用不同的是，对常量的引用不能被用作修改它所绑定的对象。
     */

    // 常量引用仅对引用可参与的操作做出了限定，对于引用的对象本身是不是一个常量未做限定。
    int i = 42;
    int &r1 = i; // 引用r2绑定到对象i
    const int &r2 = i; // r2也绑定到对象i，但是不允许通过r2修改i的值
    r1 = 0; // r1并非常量，i的值被修改为0
//  r2 = 0; // 错误: r2是一个常量引用，不允许通过r2修改i的值

    /**
     * 指针和const
     * 
     * 与引用一样，也可以令指针指向常量或非常量。
     * 类似于常量引用，指向常量的指针 （pointer to const）不能用于改变其所指对象的值。
     * 要想存放常量对象的地址，只能使用指向常量的指针。
     */
    const double pi = 3.14;
//  double *ptr = &pi;          // 错误: ptr是一个普通指针
    const double *cptr = &pi;   // 正确: cptr可以指向一个双精度常量
//  *cptr;                      // 错误: 不能给 *cptr 赋值

    /**
     * 指针的类型必须与其所指对象的类型一致，但是有两个例外:
     * 1. 允许一个指向常量的指针指向一个非常量对象
     */
    double dval = 3.14;
    cptr = &dval; // 正确: 但是不能通过cptr改变dval的值

    /**
     * const指针
     * 指针是对象而引用不是，因此就像其他对象类型一样，允许把指针本身定为常量。
     * 常量指针（const pointer）必须初始化，而且一旦初始化完成，
     * 则它的值（也就是存放在指针中的那个地址）就不能再改变了。
     * 
     * 把*放在 const 关键字之前用以说明指针是一个常量，
     * 意味着不变的是指针本身的值而非指向的那个值。
     */
    int errNum = 0;
    int *const curErr = &errNum; // curErr将一直指向errNum
    const double pi2 = 3.14159;

    // 从右往左读, const说明pip是一个常量对象，*说明pip是一个常量指针, 
    // const double 说明 pip这个常量指针指向的是一个双精度浮点型常量。
    const double *const pip = &pi2; // pip是一个指向常量对象的常量指针

    /**
     * 顶层const
     * 
     * 顶层const表示指针本身是个常量，而底层const表示指针所指向的对象是一个常量。
     * int i=0;
     * int *const pl = &i; // 不能改变pl的值，这是一个顶层 const
     * const int ci = 42;  // 不能改变ci 的值，这是一个顶层 const
     * const int *p2 = &ci; // 允许改变p2的值，这是一个底层 const
     * const int *const p3 = p2; // 靠右的 const 是顶层 const，靠左的是底层 const 
     * const int &r= ci; // 用于声明引用的 const 都是底层 const
     * 
     * 底层 const 的限制却不能忽视。
     * 当执行对象的拷贝操作时，拷入和拷出 的对象必须具有相同的底层 const 资格，
     * 或者两个对象的数据类型必须能够转换。一般 来说，非常量可以转换成常量，反之则不行：
     * int *p = p3; // 错误：p3包含底层 const.的定义，而p没有
     * p2 = p3; // 正确：P2和p3都是底层 const
     * p2 = &i; // 正确：int*能转换成 const int*
     * int &r = ci; // 错误：普通的 int&不能绑定到int 常量上 
     * const int &r2 = i; // 正确：const int& 可以绑定到一个普通 int 上
     * 
     */
    

    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <cstddef>      // size_t 类型
#include <iterator>     // 迭代器 begin() end()
#include <cstring>      // cstring 是C语言头文件string.h的C++版本
using namespace std;

void printBinaryArray(int** arr, int row, int col);


int main()
{
    /**
     * C 风格字符串
     * 
     * 字符串字面值是一种通用结构的实例，这种结构即是C++由C继承而来的C风格字符串。
     * C风格字符串不是一种类型，而是为了表达和使用字符串而形成的一种约定俗成的写法。
     * 按此习惯书写的字符串存放在字符数组中并以空字符结束（null terminated）。
     * 以空字符结束的意思是在字符串最后一个字符后面跟着一个空字符（'\0'）。 一般利用指针来操作这些字符串。
     * 
     * C 标准库String函数
     * strlen(p);           // 返回p的长度, 空字符不计算在内
     * strcmp(p1, p2);      // 比较p1和p2的相等性。 p1 = p2 返回0; p1 < p2 返回负值; p1 > p2 返回正值；
     * strcat(p1, p2);      // 将p2追加到p1之后，返回p1
     * strcpy(p1, p2);      // 将p2拷贝给p1，返回p1
     * 传入此类函数的指针必须指向以空字符作为结束的数组。
     * 
     */

    /**
     * ex 3.37:
     * 
     * 下面的程序是何含义，程序的输出结果是什么？
     */
    const char ca[] = {'h', 'e', 'l', 'l', 'o'};
    const char* cp = ca;
    while (*cp)
    {
        cout << *cp;
        cp++;
    }
    cout << endl;
    // 答: 由于未添加空字符, 所以会导致指针访问意料之外的内存，引起错误。

    /**
     * ex 3.39:
     * 
     * 编写一段程序，比较两个 string对象。再编写一段程序，比较两个C风格字符串的内容。
     */
    string str1 = "hello";
    string str2 = "hello2";
    if (str1 == str2)
        cout << "相等" << endl;
    else
        cout << "不相等" << endl;

    char cstr1[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    char cstr2[] = {'h', 'e', 'l', 'l', 'o', '2', '\0'};
    if (strcmp(cstr1, cstr2) == 0)
        cout << "相等" << endl;
    else
        cout << "不相等" << endl;

    /**
     * ex 3.40:
     * 
     * 编写一段程序，定义两个字符数组并用字符串字面值初始化它们；
     * 接着再定义一个字符数组存放前两个数组连接后的结果。
     * 使用 strcpy 和 strcat 把前两个数组 的内容拷贝到第三个数组中。
     */
    char cstr3[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    char cstr4[] = {'w', 'o', 'r', 'l', 'd', '\0'};
    char cstr[100];

    strcpy(cstr, cstr3);
    strcat(cstr, cstr4);
    cout << cstr << endl << endl;   // helloworld
    

    /**
     * 与旧代码的接口
     * 
     * 为了使现代C++程序能够与那些充满了数组和/或C风格字符串的代码衔接,，C++专门提供了一组功能。
     */

    /**
     *  1. 混用 string 对象和 C 风格字符串
     * 
     * (1). 允许使用以空字符结束的字符数组来初始化 string 对象或力 string 对象赋值。 
     * (2). 在 string 对象的加法运算中允许使用以空字符结束的字符数组作为其中一个运算对象（不能两个运算对象都是）；
     * 在string 对象的复合赋值运算中允许使用以空字符结束的字符数组作为右侧的运算对象。
     * 
     * (3). string 对象的 c_str 的成员函数
     * c_str()返回结果是一个指针(C语言中, 使用数组时不正是使用了一个指向首元素的指针吗?)，该指针指向一个以空字符结束的字符数组。
     * 指针的类型是 const char*，从而确保我们不会改变字符数组的内容。
     * 
     * 注意:
     * 1. 使用 c_str() 的典型场景是需要将 string 转换成 C 风格字符串以与 C 函数（如 printf）兼容。
     * 2. 不可直接对 c_str() 返回的指针进行写操作是因为 c_str() 提供的是 string 内部数据的只读副本，目的是为了防止对 string 对象内部状态的意外更改。
     * 3. const char* 类型意味着不能通过解引用去修改字符串的值；但可以递增指针遍历数组等。
     * 4. c_str() 返回的字符数组是 string 对象的内部数据的引用。
     */
    string s("hello");  // string 类型的对象
//  char* ps = s;       // 错误: 不能使用string对象初始化char*
    const char* ps = s.c_str();     // 正确

    while (*ps)     // 通过返回的指针进行字符串遍历
    {
        cout << *ps;
        ps++;
    }
    cout << endl;   // hello

    /**
     * 使用数组初始化vector对象
     * 
     * 需要指明要拷贝区域的首元素地址和尾后地址。
     */
    int iarr[] = {0, 1, 2, 3, 4};
    vector<int> iv(begin(iarr), end(iarr));     // 用iarr[]全部元素来初始化
    vector<int> iv2(iarr+1, iarr+3);    // 用 iarr[1], iarr[2] 来初始化iv2
    for (auto i : iv2)
        cout << i << " ";
    cout << endl;   // 1 2


    /**
     * ex 3.42:
     * 
     * 编写一段程序，将含有整数元素的vector 对象拷贝给一个整型数组。
     */
    vector<int> iv3{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int iarr3[10];
    // 遍历赋值
    for (int i = 0; i < iv3.size(); i++) 
        iarr3[i] = iv3[i];
    // 打印拷贝后的数组
    for (auto i : iarr3)
        cout << i << " ";
    cout << endl << endl;   // 0 1 2 3 4 5 6 7 8 9


    /**
     * 多维数组
     * 
     * 严格来说，C++语言中没有多维数组，通常所说的多维数组其实是数组的数组。
     */
    int ia0[3][4];   // 大小为3的数组, 每个元素是含有4个整数的数组
    int arr[10][20][30] = {0};  // 大小为10的数组, 它的的每个元素都是大小为20的数组，这些数组的元素都是含有30个整数的数组

    /**
     * 1. 多维数组的初始化
     * 
     */
    int ia2[3][4] = {   // 三个元素，每个元素都是大小为4的数组
        {0, 1, 2, 3},   // 第1行的初始值
        {4, 5, 6, 7},   // 第2行的初始值
        {8, 9, 10, 11}  // 第3行的初始值
    };
    // 内嵌的花括号并非是必须的, 下面的语句与之等价:
    int ia3[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    // 显式地仅初始化每一行的第一个元素:
    int ia4[3][4] = {{ 0 }, { 4 }, { 8 }}; // 其余未列出的元素会执行默认值初始化

    // 显式地初始化第一行，其他元素执行值初始化:
    int ia5[3][4] = {0, 1, 2, 3};

    /**
     * 2. 多维数组的下标引用
     * 
     * 可以使用下标运算符来访问多维数组的元素，此时数组的每个维度对应一个下标运算符。
     * 如果表达式含有的下标运算符数量和数组的维度一样多，该表达式的结果将是给定类型的元素；
     * 反之，如果表达式含有的下标运算符数量比数组的维度小，则表达式的结果将 是给定索引处的一个内层数组。
     * 
     * 在第一个例子中，对于用到的两个数组来说，表达式提供的下标运算符数量都和它们各自的维度相同。
     * 在等号左侧，ia5[3]得到数组ia5的最后一行，此时返回的是表示ia5最后一行的那个一维数组而非任何实际元素；对这个一维数组再取下标，得到编号为［4］的元素，也就是这一行的最后一个元素。
     * 在第二个例子中，把 row 定义成一个含有4个整数的数组的引用，然后将其绑定到 ia 的第2行。
     */
    ia5[2][3] = ia2[0][0];  // 用ia2的首元素为ia5最后一行的最后一个元素赋值
    int (&row)[4] = ia5[1]; // 把row绑定到ia5的第二个4元素数组上

    // 嵌套for循环遍历多维数组
    constexpr size_t rowCnt = 3, colCnt = 4;
    int ia6[rowCnt][colCnt];    // 12个未初始化的元素

    // 对于每一行
    cout << "{" << endl;
    for (size_t i = 0; i != rowCnt; i++)
    {
        cout << "{ ";
        // 对于行内的每一列
        for (size_t j = 0; j != colCnt; j++)
        {
            // 将元素的位置索引作为它的值
            ia6[i][j] = i * colCnt + j;

            // 打印结果
            if (j == colCnt - 1)
                cout << ia6[i][j];
            else
                cout << ia6[i][j] << ", ";
        }
        if (i == rowCnt - 1)
            cout << " }";
        else
            cout << " }, " << endl;
        
    }
    cout << endl << "}" << endl << endl;

    /**
     * 使用范围for语句处理多维数组
     * 
     * 因为要改变元素的值，所以得把控制变量 row 和co1 声明成引用类型。
     * 第一个 for 循环遍历ia6 的所有元素，这些元素是大小为4的数组，因此 row 的类型就应该是含有4个整数的数组的引用。
     * 第二个 for 循环遍历那些4元素数组中的某一个，因此 col的类型是整数的引用。 每次迭代把 cnt 的值赋给ia6的当前元素，然后将 cnt 加1。
     * 
     * 注意: 要使用范围 EOr 语句处理多维数组，除了最内层的循环外，其他所有循环的控制变量都应该是引用类型。
     */
    int ia7[rowCnt][colCnt];    // 12个未初始化的元素
    size_t cnt = 0;

    cout << "使用范围for语句:" << endl;
    for (auto &row : ia7)   // 对于外层数组的每一个元素
        for (auto &col : row)    // 对于内层数组的每一个元素
        {
            col = cnt;                  // 将下一个值赋值给该元素
            cnt++;                      // cnt递增
            cout << col << " ";
        }
    cout << endl;   // 0 1 2 3 4 5 6 7 8 9 10 11 

    /**
     * 指针和多维数组
     * 
     * 当程序使用多维数组的名字时，也会自动将其转换成指向数组首元素的指针。
     * 因为多维数组实际上是数组的数组，所以由多维数组名转换得来的指针实际上是指向 第一个内层数组的指针。
     */
    int ia8[3][4] = {   // 三个元素，每个元素都是大小为4的数组
        {0, 1, 2, 3},   // 第1行的初始值
        {4, 5, 6, 7},   // 第2行的初始值
        {8, 9, 10, 11}  // 第3行的初始值
    };

    cout << "使用普通指针完成遍历:" << endl;
    for (auto p = ia8; p != ia8 + 3; p++)   // ia8 + 3 指的是尾后指针
    {
        for (auto q = *p; q != *p + 4; q++)
        {
            cout << *q << ' ';
        }
    }
    cout << endl;   // 0 1 2 3 4 5 6 7 8 9 10 11

    cout << "使用 bnegin() end() 完成遍历:" << endl;
    for (auto p = begin(ia8); p != end(ia8) ; p++)
    {
        for (auto q = begin(*p); q != end(*p); q++) // 对 p 解引用结果为数组，故才能使用begin or end
        {
            cout << *q << ' ';
        }
    }
    cout << endl;   // 0 1 2 3 4 5 6 7 8 9 10 11

    /**
     * 类型别名简化多维数组的指针
     * 
     * 读、写和理解一个指向多维数组的指针是一个让人不胜其烦的工作，使用类型别名能让这项工作变得简单一点儿。
     */
    using int_array = int[4];   // 类型别名声明
    typedef int int_array[4];   // 等价的typedef声明

    cout << "使用类型别名简化指针:" << endl;
    for (int_array *p = ia8; p != ia8 + 3; p++)
    {
        for (int* q = *p; q != *p + 4; q++)
        {
            cout << *q << ' ';
        }
    }
    cout << endl << endl;   // 0 1 2 3 4 5 6 7 8 9 10 11

    /**
     * ex 3.43:
     * 
     * 编写3个不同版本的程序，令其均能输出ia 的元素:
     * 
     * 版本1使用范围 for 语句管理迭代过程；
     * 
     * 版本2和版本3都使用普通的for 语句，
     * 其中版本2要求用下标 运算符，
     * 
     * 版本3要求用指针。
     * 
     * 此外，在所有3个版本的程序中都要直接写出数据类型， 而不能使用类型别名、auto关键字或decltype关键字。
     */
    int ia[3][4] = {   // 三个元素，每个元素都是大小为4的数组
        {0, 1, 2, 3},   // 第1行的初始值
        {4, 5, 6, 7},   // 第2行的初始值
        {8, 9, 10, 11}  // 第3行的初始值
    };
    
    /** 使用 范围for 语句完成遍历 */
    cout << "ex 3.43 使用范围for语句:" << endl;
    for (int (&row)[4] : ia)    // row 的类型是含有4个整数的数组的引用
    {
        for (int col : row)
        {
            cout << col << " ";
        }
    }
    cout << endl;

    /** 使用 下标运算符 语句完成遍历 */
    cout << "ex 3.43 使用下标运算符完成遍历:" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
           cout << ia[i][j] << " ";
        }
    }
    cout << endl;

    /** 使用 指针 语句完成遍历 */
    cout << "ex 3.43 使用指针完成遍历:" << endl;
    for (int (*p)[4] = ia; p != ia + 3; p++)
    {
        for (int* q = *p; q != *p + 4; q++)
        {
            cout << *q << " ";
        }   
    }
    cout << endl;

    /**
     * ex 3.44:
     * 
     * 改写上一个练习中的程序，使用类型别名来代替循环控制变量的类型。
     */
    cout << "ex 3.44 使用类型别名简化指针:" << endl;
    using i4 = int[4];
    for (i4* p = ia; p != ia + 3; p++)
    {
       for (int* q = *p; q != *p + 4; q++)
       {
            cout << *q << " ";
       }
    }
    cout << endl;


    /**
     * ex 3.45:
     * 
     * 再一次改写程序，这次使用 auto 关键字。
     */
        cout << "ex 3.44 使用auto关键字完成遍历:" << endl;
    for (auto &i : ia)
        for (auto j : i)
            cout << j << " ";
    cout << endl;

    return 0;
}
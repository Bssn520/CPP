#include <iostream>
#include <string>
using namespace std;

/**
 * 标准库类型 string 表示可变长的字符序列。
 */

int main()
{
    /**
     * 1. 定义和初始化 string 对象
     * 
     * 如果使用等号(=)初始化一个变量, 实际上执行的是拷贝初始化, 编译器把右侧的初始值拷贝到新创建的对象中去。
     * 如果不使用等号(=)，则执行的是直接初始化。
     * 
     */
    string s1; // 默认初始化，s1是一个空串
    string s2(s1); // s2是s1的副本
//  string s2 = s1; // 等价于s2(s1)
    string s3("value"); // s3是字面值"value"的副本，除了字面值最后的那个空字符串外
//  string s3 = "value"; // 等价于s3("value")
    int n = 10;
    string s4(n, 'c'); // 把s4初始化为由连续n个字符c组成的字符串

    /**
     * 2. string对象上的操作
     * 
     * string类的大多数操作:
     * os << s      // 将s写到输出流os中，返回os
     * is >> s      // 从is中读取字符串赋值给s，字符串以空白分割，返回is
     * getline(is, s) // 从is中读取一行赋值给s，返回is
     * s.empty()    // s为空返回true否则返回false
     * s.szie()     // 返回s中字符的个数
     * s[n]         // 返回s中第n个字符的引用，位置从0记起
     * s1 + s2      // 返回 s1 和 s2连接后的结果
     * s1 = s2      // 用s2的副本代替s1中原来的字符
     * s1 == s2     // 如果s1和s2中所含字符完全一样，则它们相等；
     * s1 != s2     // string对象的相等性判断对字母大小写敏感
     * <, <=, >, >= // 利用字符在字典中的顺序进行比较，对字母大小写敏感
     * 
     */

    /**
     * 读写string对象
     * 
     * 在执行读操作时，string 对象会自动忽略开头的空白（即空格符、换行符、制表符等,
     * 并从第一个真正的字符开始读起，直到遇见下一处空白为止。
     * ex: 输入 "   Hello  World!   ", 输出将是"Hello"
     */
    string s5, s6; // 空字符串
    cin >> s5 >> s6; // 将string对象读入s，遇到空白停止
    cout << s5 << s6 << endl; // 输出s

    // 读取未知数量的string对象
    /*
    string word;
    while (cin >> word) // 如果输入流有效就一直执行
        cout << word << endl;
    */

    /**
     * 使用getline()读取一整行
     * 
     * 传入参数: 输入流 string对象
     * 停止条件: 遇见换行符
     */
    /**
     * 成员函数: empty 和 size
     * 
     * 注意: 成员函数使用点操作符进行使用(.empty() .size())
     */

    string line;
    // 忽略掉之前cin缓存中的的换行符
    cin.ignore();
    getline(cin, line);
    cout << "isEmpty: " << line.empty() << endl
         << "size: " << line.size() << endl
         << "content: " << line << endl;

    /**
     * string::size_type类型
     * 
     * 成员函数 .size() 返回的并不是一个int类型值, 而是string::size_type类型的值,
     * 可以确定的是，其是一个无符号类型的值而且能够存放下任何string对象的大小。
     * 所有用于存放 string 类的 size 函数返回值的变量，都应该是 string：：size_type类型的。
     * 
     * 注意:
     * 如果一条表达式中已经有了size（）函数就不要再使用int了，
     * 这样可以避免混用int和unsigned 可能带来的问题。
     * 
     */

    /**
     * 比较 string 对象
     * 
     * 相等性运算符（==和！=）分别检验两个 string 对象相等或不相等，
     * string 对象相等意味着它们的长度相同而且所包含的字符也全都相同。
     * 
     * 关系运算符 < 、<=、>、>=分别检验一个 string 对象是否小于、小于等于、大于、大于等于另外一个 string 对象。
     * 这些运算符都依照（大小写敏感的）字典顺序：
     * 1. 如果两个 string 对象的长度不同，
     * 而且较短 string 对象的每个字符都与较长 string 对象对应位置上的字符相同，
     * 就说较短 string 对象小于较长 string 对象。
     * 2. 如果两个 string 对象在某些对应的位置上不一致，
     * 则string 对象比较的结果 其实是 string对象中第一对相异字符比较的结果。
     * 
     */
    // 根据规则1可判断，对象 str 小于对象 phrase；
    // 根据规则2可判断，对象 slang 既大 于 str 也大于phrase。
    string str = "Hello";
    string phrase = "Hello World";
    string slang = "Hiya";

    // 为string对象赋值
    string st1(10, 'c'), st2;
    st2 = st1; // 此时 st2 的内容都是 cccccccccc

    // 两个string对象相加
    string s7 = "Hello", s8 = "World";
    string s9 = s7 + s8;
    cout << s9 << endl; // HelloWorld

    // 字面值和string对象相加
        // 当把string 对象和字符字面值及字符串字面值混在一条语句中使用时，
        // 必须确保每个加 法运算符（+）的两侧的运算对象至少有一个是 string。
        // 切记，字符串字面值与 string是不同的类型。
    string s11 = s7 + " " + s8 + "!";
    cout << s11 << endl; // Hello World!

    return 0;
}
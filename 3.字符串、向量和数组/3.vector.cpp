#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

/**
 * 标准库类型vector表示对象的集合，其中所有对象的类型都相同。
 * 集合中的每个对象都有一个与之对应的索引，索引用于访问对象，所以它也常被称作容器。
 * 
 */


int main()
{
    /**
     * 定义和初始化vector对象
     * 
     * vector<T> v1             v1是一个空vector, 它潜在的元素是T类型, 执行默认初始化
     * vector<T> v2(v1)         v2中包含有v1所有元素的副本
     * vector<T> v2 = v1        等价于v2(v1), v2中包含有v1所有元素的副本
     * vector<T> v3(n, val)     v3包含了n个重复的元素, 每个元素的值都是val
     * vector<T> v4(n)          v4包含了n个重复地执行了值初始化的对象
     * vector<T> v5{a,b,c...}   v5包含了初始值个数的元素, 每个元素被赋予相应的初始值
     * vector<T> v5={a,b,c...}  等价于v5{a,b,c...}
     * 
     * 在定义vector时指定元素的初始值:
     * vector<int> ivec;        初始状态为空
     * vector<int> ivec2(ivec)  把ivec的元素拷贝给ivec2
     * vector<int> ivec3 = ivec 把ivec的元素拷贝给ivec3
     * vector<string> svec(ivec) 错误: svec的元素是string类型, 不是int
     * 
     */

    /* 列表初始化vector对象 */
    vector<string> articles = {"a", "an", "the"}; // 列表初始化
//  vector<string> articles2("a", "an", "the"); // 错误, 应该把初始值放在花括号内进行初始化
    
    /* 创建指定数量的元素 */
    vector<string> v1(10, "hi!"); // 10个string类型的元素，每个都被初始化为"hi!
    vector<int> v2(10, -1); // 10个int类型的元素，每个都被初始化为-1

    /**
     * 值初始化
     * 
     * 如果 vector 对象的元素是内置类型，比如int，则元素初始值自动设为0。
     * 如果元素是某种类类型，比如 string，则元素由类默认初始化：
     * vectorcint> ivec(10); // 10个元素，每个都初始化为0
     * vector<string> svec(10); // 10个元素，每个都是空 string 对象
     * 对这种初始化的方式有两个特殊限制：
     * 1. 有些类要求必须明确地提供初始值
     * 2. 如果只提供了元素的数量而没有设定初始值，只能使用直接初始化
    */
    vector<string> v5{"hi"};        // 列表初始化: v5有一个元素
//  vector<string> v6("hi");        // 错误: 不能使用字符串字面值构建vector对象
    vector<string> v7{10};          // v7有10个默认初始化的元素
    vector<string> v8{10, "hi"};    // v8有10个值为"hi"的元素

    /**
     * 向vector对象中添加元素
     * 
     * push_back() 成员函数
     */
    int i = 0, num1;
    vector<int> nums1;
    while (i < 5)
    {
        cin >> num1;
        nums1.push_back(num1);
        i++;
    }
    printf("The size of vector nums: %zu\n\n", nums1.size()); // 5
    
    /**
     * 其他vector操作:
     * 
     * v.empty()        如果v不含有任何元素, 返回真; 否则返回假
     * v.size()         返回v中元素的个数
     * v.push_back(t)   向v的尾端添加一个值为t的元素
     * v[n]             返回v中第n个位置上元素的引用
     * v1 = v2          用v2中的元素拷贝替换v1中的元素
     * v1 = {a,b,c...}  用列表中的元素的拷贝替换v1中的元素
     * v1 == v2         v1和v2相等当且仅当它们的元素数量相同且对应位置的的元素值都相同
     * v1 != v2
     * <, <=, >, >=     顾名思义, 以字典顺序进行比较
     * 
     */

    /** 
     * 注意: 不能使用下标形式来为vector对象添加元素
     * 
     * vector<int> ivec;
     * for (decltype(ivec.size()) ix = 0; ix != 10; i++)
     *     ivec[ix] = ix;
     * 上面的代码是错误的, ivec是一个空vector, 根本不包含任何元素, 当然也就不能通过下标去访问任何元素。
     * 
     * 试图用下标的形式去访问一个不存在的元素将引发错误，不过这种错误不会被编译器发现，
     * 而是在运行时产生一个不可预知的值。
     * 
     * 应该尽可能使用范围for语句，避免出现这类错误。
     */


    /**
     * ex 3.17:
     * 
     * 从 cin 读入一组词并把它们存入一个 vector 对象，
     * 然后设法把所有词都改写为大写形式。输出改变后的结果，每个词占一行。
     */
    string word;
    vector<string> sentences;

    // 存储用户输入
    for (int i = 0; i < 5; i++)
    {
        cin >> word;
        sentences.push_back(word);
    }

    // 逐字符转换为大写
    for (auto& word : sentences)
        for (auto& c : word)
            if (isalpha(c))
                c = toupper(c);

    // 输出结果
    for (const auto& sentence : sentences)
        cout << sentence << endl;

    /**
     * ex 3.19:
     * 
     * 如果想定义一个含有10个元素的vector 对象，所有元素的值都是42,
     * 列举出三种不同的实现方法。哪种方法更好呢？为什么？
     */
    vector<int> ex21 = {42, 42, 42,42, 42, 42, 42, 42,42, 42};
    vector<int> ex22{42, 42, 42,42, 42, 42, 42, 42,42, 42};
    vector<int> ex23(10, 42); // 最优


    /**
     * ex 3.20:
     * 
     * 读入一组整数并把它们存入一个 vector 对象，将每对相邻整数的和输出出来。
     * 
     * 改写你的程序，这次要求先输出第1个和最后1个元素的和，
     * 接着输出第2个和倒数第2个元素的和，以此类推。
     */
    vector<int> nums, sum1, sum2;
    
    // 获取并存储用户输入
    for (int i = 0; i < 5; i++)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    // 计算相邻元素和
    for (decltype(nums.size()) i = 0; i < nums.size() - 1; i++)
    {
        sum1.push_back(nums[i] + nums[i + 1]);
    }
    for (auto num : sum1)
        cout << num << " ";
    cout << endl;

    // 计算对称元素和
    for (decltype(nums.size()) i = 0; i < nums.size()/2 + 1; i++)
    {
        sum2.push_back(nums[i] + nums[nums.size() - i - 1]);
    }
    for (auto num : sum2)
        cout << num << " ";
    cout << endl;

    return 0;
}
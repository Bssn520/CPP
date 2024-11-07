/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-05 17:07:16
 * @LastEditTime: 2024-11-07 21:30:10
 * @Description: 
 * 
 */
/*
额外的 string 操作

1. 构造 string 的其他方法:
n, len2, pos2 都是无符号值
string s(cp, n)             s 是 cp 指向的数组中前 n 个字符的拷贝。若 pos2 > s2.size() 构造函数的行为未定义
string s(s2, pos2)          s 是 string s2 从下标 pos2 开始的字符串的拷贝。若pos2 > s2.size() 构造函数的行为未定义
string s(s2, pos2, len2)    s 是string s2 从下标 pos2 开始 len2 个字符的拷贝。若 pos2 > s2.size(), 构造函数的行为未定义。不管len2的值是多少，构造函数至多拷贝 s2.size() - pos2 个字符。

substr操作
substr 操作返回一个 string，它是原始 string 的一部分或全部的拷贝。可以传递给 substr一个可选的开始位置和计数值：
s.substr(pos,n) // 返回一个 string，包含s中从pos 开始的n个字符的拷贝。pos 的默认值为0。n 的默认值为 s.size（）-pos，即拷贝从 pos 开始的所有字符。
string s("hello world");
string s2 = s.substr(0, 5); // hello
string s3 = s.substr(6);    // world
string s4 = s.substr(6, 11); // world
string s5 = s.substr(12);   // 拋出一个 out_of_range 异常

*/

/*
改变 string 的其他方法

append 和 replace 函数

append 操作是在string末尾进行插入操作的一种简写形式:
string s("C++ Primer"), s2 = s; // 将s 和 s2 初始化
s.insert(s.size(), "4th Ed.");  // s = "C++ Primer 4th Ed."
s2.append(" 4th Ed.");          // 与上一行等价的方法

replace 操作是调用erase 和 insert 的一种简写形式:
// 将 "4th" 替换为 "5th" 的等价方法
s.erase(11, 3);             // s == "C++ Primer Ed."
s.insert(11, "5th");        // s == "C++ Prime 5th Ed."
// 从位置 1 开始，删除3个字符并插入"5th"
s2.replace(11, 3, "5th");   // 等价方法: s == s2

*/

/*
string 搜索操作

搜索函数返回一个 string::size_type 值, 表示匹配发生位置的下标。如果搜索失败，则返回一个名为 string::npos 的 static 成员。
标准库将 npos 定义为一个 const string:size_type 类型，并初始化为值-1。由于 npos 是一个 unsigned 类型，此初始值意味着 npos 等于任何string 最大的可能大小。

string搜索操作
// 搜索操作返回指定字符出现的下标，如果未找到则返回 npos
s.find(args)                // 查找s 中 args第一次出现的位置
s.rfind(args)               // 查找s中 args 最后一次出现的位置
s.find_first_of(args)       // 在s中查找 args 中任何一个字符第一次出现的位置。
s.find_last_of(args)        // 在s中查找 args 中任何一个字符最后一次出现的位置
s.find_first_not_of(args)   // 在s中查找第一个不在 args 中的字符
s.find_last_not_of(args)    // 在s中查找最后一个不在 args 中的字符
// args 必须是以下形式之一:
c,pos       // 从s中位置 pos 开始查找字符c。pos 默认为0
s2,pos      // 从s中位置 pos 开始查找字符串 s2。pos 默认为0
cp,pos      // 从s中位置 pos 开始查找指针cp 指向的以空字符结尾的C风格字符串。pos 默认为0
cp,pos,n    // 从s中位置 pos 开始查找指针cp 指向的数组的前n个字符。pos 和 n 无默认值

string numbers("0123456789"), name("r2d2");
// 返回 1，即，name中第一个数字的下标
auto pos = name.find_first_of(numbers);

string dept("03714p3");
// 返回 5，字符 'p' 的下标
auto pos = dept.find_first_not_of(numbers);

指定在哪里开始搜索

find_first_of(args, pos); 

逆向搜索

string river("Mississippi");
auto first_pos = river.find("is"); // 1
auto last_pos = river.rfind("is"); // 4

*/

/*
compare函数

compare函数的几种重载参数
s2  // 比较s和s2
pos1, n1, s2    // 将s中从pos1 开始的n1 个字符与s2进行比较
pos1, n1, s2, pos2, n2  // 将s 中从 pos1 开始的n1 个字符与s2中从pos2 开始的n2 个字符进行比较
cp  // 比较s与cp 指向的以空字符结尾的字符数组
pos1, n1, cp    // 将s中从 pos1 开始的n1 个字符与 cp 指向的以空字符结尾的字符数组进行比较
pos1, n1, cp, n2    // 将s中从 pos1 开始的n1个字符与指针cp 指向的地址开始的 n2个字符进行比较


*/

/*
数值转换

string和数值之间的转换:
to_string(val)  // 一组重载函数，返回数值val 的 string表示。val 可以是任何算术类型。对每个浮点类型和 int或更大的整型，都有相应版本的to_string。与往常一样，小整型会被提升。

返回s的起始子串（表示整数内容）的数值，返回值类型分别是 int, long, unsigned long, long long,unsigned long long。
b表示转换所用的基数，默认值为10。p是 size_t指针，用来保存 s 中第一个非数值字符的下标，p默认为0，即，函数不保存下标。
返回s的起始子串（表示浮点数内容）的数值，返回值类型分别是 float、double 或 long double。参数 p 的作用与整数转换函数中一样。

stoi(s,p,b)
stoi(s,p,b)
stoul(s,p,b)
stoll(s,p,b)
stoull(s,p,b)

stof(s,p)
stod(s,p)
stold(s,p)

*/
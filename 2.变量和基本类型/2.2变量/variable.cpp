#include <iostream>
using namespace std;

// 声明全局变量
string global_str;
int global_int;

int main()
{
    /**
     * 变量的初始化
     * 
     * 初始化不是赋值，初始化的含义是创建变量时赋予其一个初始值；
     * 赋值的含义是把对象的当前值擦除，而以一个新值来替代。
     * 
     * 定义于函数体内的内置类型的对象如果没有初始化，则其值未定义。
     * 类的对象如果没有显式地初始化，则其值由类确定。
     */
    // 声明局部变量
    int local_int;
    string local_str;

    // 尝试打印这些未初始化的变量的值
    cout << local_int << endl // 1
         << global_int << endl // 0
         << local_str << endl // ""
         << global_str << endl; // ""

    
    /**
     * 变量声明与定义的关系
     * 
     * 声明使得名字为程序所知，一个文件如果想使用别处定义的名字则必须包含对那个名字的声明。
     * 定义负责创建与名字关联的实体。
     * 
     * 如果想要声明一个变量而非定义它，使用 extern 关键字。
     * extern 语句如果包含初始值就不再是声明，而变成定义了。
     * 
     * 变量能且只能被定义一次，但是能够被多次声明。
     */
}
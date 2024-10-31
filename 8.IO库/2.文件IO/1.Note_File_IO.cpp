// fstream 继承自 iostream 类型

/*
fstream 特有的操作

fstream fstrm;          // fstream
fstream fstrm(s);       // 创建一个fstream，并打开名为s的文件。s可以是string类型或指向C风格字符串的指针。
fstream fstrm(s, mode); // 与前一个构造函数类似，但按指定mode 打开文件
fstrm.open(s);          // 打开名为s 的文件，并将文件与 Estrm 绑定。返回viod
fstrm.close();          // 关闭与 Estrm 绑定的文件。返回 void
fstrm.is_open();        // 返回一个bool 值，指出与fstrm 关联的文件是否成功打开且尚未关闭

 */

/*
用 fstream 代替 iostream&

在要求使用基类型对象的地方，我们可以用继承类型的对象来替代。
这意味着，接受一个 iostream 类型引用(或指针)参数的函数，
可以用一个对应的 fstream(或sstream)类型来调用。
也就是说，如果函数接受一个一个 ostream& 参数，我们可以传递一个 ofstream 对象，istream&也是一样。

 */

/*
成员函数 open 和 close

open()  用来将空文件流对象与文件关联。

ofstream.open(ifile + ".copy");
ifile + ".copy"：假设 ifile 是一个字符串变量，表示输入文件名: ifile + ".copy" 表示将输入文件名加上扩展名 .copy 生成新的文件名。
这意味着程序会创建一个新文件，其名称基于 ifile 的值加上 .copy，如 "input.txt" 会变成 "input.txt.copy"

如果调用 open 成功, open会设置流的状态, 使得good()为 true;
如果调用 open 失败，failbit会被置位。调用open后检查是否成功是一个好习惯。

自动构造和析构
    // 对每个传递给程序的文件执行循环操作
    for (auto p = argv + 1; p != argv + argc; ++p) {
        std::ifstream input(*p);// 创建输出流并打开文件
        if (input) {
            process(input);

        } else {
            std::cerr << "couldn't open: " + std::string(*p);
        }// 每个循环步 input 都会离开作用域，因此会被销毁
    }

 */


/*
文件模式

每个流都有一个关联的文件模式（file mode），用来指出如何使用文件。

文件模式:
in      只读
out     只写
app     每次写操作前都定位到文件末尾
ate     打开文件后立即定位到文件末尾
trunc   截断文件
binary  以二进制方式进行 IO

指定文件模式有如下限制：
只可以对 ofstream 或 fstream 对象设定 out 模式。 
只可以对 ifstream 或 fstream 对象设定in 模式。 
只有当 out 也被设定时才可设定trunc 模式。 
只要trunc 没被设定，就可以设定 app 模式。在app 模式下，即使没有显式指定 out 模式，文件也总是以输出方式被打开。 
默认情况下，即使我们没有指定trunc，以out 模式打开的文件也会被截断。为了保留以 out 模式打开的文件的内容，我们必须同时指定 app 模式，这样只会将 数据追加写到文件末尾：或者同时指定in 模式，即打开文件同时进行读写操作。 
ate 和binary 模式可用于任何类型的文件流对象，且可以与其他任何文件模式组合使用。

每个文件流类型都定义了一个默认的文件模式，
ofstream默认以 out 模式打开;
ifstream默认以 in 模式打开;


以out模式打开文件会丢弃一有数据:

默认情况下，当我们打开一个 ofstream 时，文件的内容会被丢弃。阻止一个 ofstream 清空给定文件内容的方法是同时指定 app 模式:
// 在这几条语句中，file1 都被截断
ofstream out("file1"); // 隐式以输出模式打开并截断文件
ofstream out2("file1", ofstream::out); 隐含地截断文件
ofstream out3("file1", ofstream::out | ofstream::trunc);
// 为了保留文件内容，我们必须显式指定 app 模式
ofstream app("file2", ofstream::app); // 隐含为输出模式
ofstream app2("file2", ofstream::out | ofstream::app);

// 注: 保留被 ofstream 打开的文件中已有数据的唯一方法是显式指定 app或 in 模式


每次调用 open 时都会确定文件模式:

对于一个给定流，每当打开文件时，都可以改变其文件模式。

ofstream out;   // 未指定文件打开模式
out.open("name1");   // 模式隐含设置为输出和截断
out.close();
out.open("name2", ofstream::app); // 模式为输出和追加
out.close();
第一个 open 调用未显式指定输出模式，文件隐式地以out 模式打开。通常情况下，out 模式意味着同时使用trunc模式。因此，当前目录下名力 name1 的文件的内容将被清空。
当打开名为 name2 的文件时，我们指定了 append 模式。文件中己有的数据都得以保留，所有写操作都在文件末尾进行。

 */

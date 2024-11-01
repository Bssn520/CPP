/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-10-31 21:39:33
 * @LastEditTime: 2024-11-01 21:45:32
 * @Description: String IO
 * 
 * Copyright (c) 2024 by Bssn520, All Rights Reserved. 
 */

#include <sstream>

/*
string 流

sstream 头文件定义了三个类型来支持内存IO，这些类型可以向 string 写入数据， 从string读取数据，就像 string 是一个 IO 流一样。

istringstream 从string读取数据;
ostringstream 向string写入数据;

sstream 中定义的类型都继承自 iostream 中定义的类型。
除了继承得来的操作， sstream 中定义的类型还增加了一些成员来管理与流相关联的 string:
            stringstream 特有的操作
sstream strm;       strm是一个未绑定的 stringstream 对象。
sstream strm(s);    strm 是一个 sstream 对象，保存 string s 的一个拷贝。
strm.str();         返回 strm 所保存的string的拷贝。
strm.str(s);        将 string s 拷贝到 strm 中。返回void


1. ostringstream 和 istringstream 的概念

ostringstream：用于将数据写入一个内存缓冲区，主要通过 << 操作符实现数据的追加。最终可以通过 .str() 方法获取缓冲区的字符串内容。
istringstream：用于从一个字符串缓冲区中读取数据，主要通过 >> 操作符来解析内容为不同的数据类型。

2. 流对象的缓冲区

流对象（如 ostringstream 和 istringstream）就像一个字符串变量，允许动态构建和处理字符串内容。
使用 << 操作符可以将数据写入缓冲区，而 >> 操作符可以从缓冲区读取数据。

3. ostringstream 的优势

自动数据类型转换：可以方便地拼接多种数据类型，而无需手动转换。
动态更新内容：可以通过 str(new_content) 和 clear() 方法重新设置或清空缓冲区。
格式化控制：支持格式化输出，例如控制小数位数、宽度等。

4. 使用场景的选择

std::string：更适合保存和直接操作已有的字符串内容。
ostringstream：更适合动态拼接或格式化内容，特别是在需要处理多种数据类型时。

5. 使用实例

写入示例：
std::ostringstream oss;
oss << "Error: Code " << 404 << ", Page not found.";
std::string result = oss.str();  // 获取整个缓冲区内容
读取示例：
std::istringstream iss("Hello World");
std::string word;
while (iss >> word) {
    std::cout << word << std::endl;  // 输出: Hello 和 World
}

6. << 和 >> 操作符的理解

<< 在流对象中表示将数据写入缓冲区，而不是直接输出到控制台。
>> 表示从缓冲区读取数据。

*/
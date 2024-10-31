/**
 * IO类
 *
 * IO库类型和头文件
 *
 * 头文件       类型
 * iostream     istream, wistream从流读取数据
 *              ostream, wostream向流写入数据
 *              iostream, wiostream读写流
 *
 * fstream      ifstream, wifstream从文件读取数据
 *              ofstream, wofstream向文件写入数据
 *              fstream, wfstream读写文件
 *
 * sstream      istringstream, wistringstream从string读取数据
 *              ostringstream, wostringstream向string写入数据
 *              stringstream, wstringstream读写string 
 *
 * 为了支持使用宽字符的语言，标准库定义了一组类型和对象来操纵 wchar_t类型的数据宽字符版本的类型和函数的名字以一个w开始。
 * 例如， wcin、wcout 和 wcerr 是分别对应 cin、cout 和 cerr 的宽字符版对象。
 * 宽字符版本的类型和对象与其对应的普通 char 版本的类型定义在同一个头文件中。例如，头文件 fstream 定义了 ifstream 和 wifstream 类型。
 *
 * 注意: IO对象无拷贝或赋值。
 *
 */

/**
 * 流的状态
 *
 * strm::iostate        strm是一种IO类型。iostate是一种机器相关的类型。
 * strm::badbit         用来指出流已崩溃
 * strm::failbit        用来指出一个IO操作失败了
 * strm::eofbit         用来指出流到达了文件结束
 * strm::goodbit        用来指出流未处于错误状态。此值保证为0
 * s.eof()              若流s的eofbit置位，则返回true
 * s.fail()             若s的badbit 或 failbit置位，则返回true
 * s.bad()              若s的badbit置位，则返回true
 * s.good()             若s处于有效状态，则返回true
 * s.clear()            将流s中所有条件状态位复位，将流的状态设置为有效。返回void
 * s.clear(flags)       根据给定的flags位，将流s中对应条件状态复位。返回void
 * s.setstate(flags)    根据给定的flags位，将流s中对应条件状态复位。返回void
 * s.rdstate()          返回流s的当前条件状态，返回值类型为strm::iostate
 *
 *
 * 查询流的状态
 *
 * 管理条件状态
 *
 *
 */

/**
 * 管理输出缓冲
 *
 * 刷新输出缓冲区 
 * endl flush ends 三个操纵符都能够刷新缓冲区。
 * std::cout << "hi!" << std::endl; // 输出hi和一个换行符，然后刷新缓冲区
 * std::cout << "hi!" << std::flush; // 输出hi，然后刷新缓冲区，不附加任何额外字符
 * std::cout << "hi!" << std::ends; // 输出hi和一个空白字符，然后刷新缓冲区
 *
 * unitbuf操纵符
 * 如果想在每次输出操作后都刷新缓冲区，我们可以使用unitbuf 操纵符。
 * 它告诉流在接下来的每次写操作之后都进行一次 flush 操作。
 * 而 nounitbuf 操纵符则重置流，使其恢复使用正常的系统管理的缓冲区刷新机制。
 * std::cout << unitbuf; // 所有输出操作后都会立即刷新缓冲区
 * // 任何输出都立即刷新，无缓冲
 * std::cout << nounitbuf; // 回到正常的缓冲方式
 *
 * 关联输入和输出流
 * 当一个输入流被关联到一个输出流时，任何试图从输入流读取数据的操作都会先刷新关联的输出流。
 * 标准库将 cout 和 cin 关联在一起。
 * std::cin >> ival; // 会导致std::cout的缓冲区被刷新
 * 
 * std::cin.tie(&std::cout); // 标准库将 cin 和 cout 关联在一起
 * ostream *old_tie = std::cin.tie(nullptr); // cin不再与其他流关联
 * std::cin.tie(&cerr); // 将cin与cerr关联；读取cin会刷新cerr
 * std::cin.tie(old_tie); // 重建cin与cout的正常关联
 *
 */

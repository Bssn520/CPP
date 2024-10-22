#ifndef SCREEN_H_
#define  SCREEN_H_

#include <ostream>
#include <string>


class Screen
{

public:
    using pos = std::string::size_type;
    // 因为 Screen 有另一个构造函数，所以本函数是必需的
    Screen() = default; 
    // 构造函数
    Screen(pos ht, pos wd) : heigth(ht), width(wd) { }
    Screen(pos ht, pos wd, char c) : heigth(ht), width(wd), contents(ht * wd, c) { }    
    // 成员函数 读取光标处的字符 隐式内联
    char get() const { return contents[cursor]; }
    char get(pos ht, pos wd) const;
    /** 成员函数 光标移动 */
    Screen &move(pos r, pos c);
    /** 成员函数 设置某一位置的字符 */
    Screen &set(char);
    Screen &set(pos row, pos col, char ch);
    /** 成员函数 打印 Screen */
    Screen &display(std::ostream &os) { do_display(os); return *this; }
    const Screen &display(std::ostream &os) const { do_display(os); return *this; }

private:
    /** 该函数负责显示 Screen 的内容 */
    void do_display(std::ostream &os) const { os << contents; }
    pos cursor = 0;
    pos  heigth = 0, width = 0;
    std::string contents;
};


/** 成员函数 读取光标处的字符 */
inline char Screen::get(pos r, pos c) const
{
    pos row = r * width;

    return contents[row + c];
}

/** 成员函数 光标移动 */
inline Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;    // 计算行位置
    cursor = row + c;       // 在行内将光标移动到指定的列

    return  *this;          // 以左值的形式返回对象
}

/** 成员函数 设置光标处的字符 */
inline Screen &Screen::set(char c)
{
    contents[cursor] = c;

    return  *this;
}

/** 成员函数 设置某一位置的字符 */
inline Screen &Screen::set(pos row, pos col, char ch)
{
    contents[row*width + col] = ch;

    return  *this;
}


#endif
#include <cstdlib>
#include <iostream>
#include <string>

class numbered
{
    friend void f(const numbered &s);

public:
    numbered() :
        mysn(std::to_string(std::rand())) {};
    numbered(const numbered &) :
        mysn(std::to_string(std::rand())) {};
    ~numbered() {};

private:
    std::string mysn;
};

void f(const numbered &s)
{
    std::cout << s.mysn << std::endl;
}

int main(int argc, const char **argv)
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);

    return 0;
}

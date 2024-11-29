#include <iostream>

struct X
{
    X() { std::cout << "X()" << std::endl; };
    X(const X &) { std::cout << "X(const X&)" << std::endl; }
    X &operator=(const X &rh)
    {
        std::cout << "X &operator=(const X &rh)" << std::endl;
        return *this;
    }
    ~X() { std::cout << "~X()" << std::endl; }
};

void fcn1(X x)
{
    std::cout << "void fcn1(X x)" << std::endl;
}

void fcn2(X &x)
{
    std::cout << "void fcn2(X &x)" << std::endl;
}

int main(int argc, const char **argv)
{
    std::cout << "--- x1 ---" << std::endl;
    X x1;
    fcn1(x1);

    std::cout << "--- x2 ---" << std::endl;
    X x2;
    fcn2(x2);

    std::cout << "--- new ---" << std::endl;
    X *x3 = new X();
    delete x3;

    return 0;
}

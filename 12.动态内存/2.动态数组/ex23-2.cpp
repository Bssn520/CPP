#include <cstring>
#include <iostream>
#include <string>
int main(int argc, const char **argv)
{
    std::string buf;

    std::cout << "Please input a string: ";
    std::cin >> buf;

    char *ps = new char[buf.size() + 1];
    strcat(ps, buf.c_str());

    std::cout << std::string(ps) << std::endl;
    delete[] ps;

    return 0;
}

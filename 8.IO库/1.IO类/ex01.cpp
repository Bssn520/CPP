#include <iostream>

std::istream &test(std::istream &is) {
    std::string content;
    while (is >> content) {
        std::cout << content << std::endl;
    }

    if (is.eof())
        is.clear();

    return is;
}

int main(int argc, char *argv[]) {
    test(std::cin);

    return 0;
}

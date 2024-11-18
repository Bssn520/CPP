#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, const char **argv)
{
    std::vector<std::string> sv;
    std::string buf;
    while (std::cin >> buf)
    {
        if (buf == "q")
            break;

        if (std::find(sv.begin(), sv.end(), buf) == sv.end())
            sv.push_back(buf);
    }

    for (const auto &s : sv)
        std::cout << s << " ";
    std::cout << std::endl;

    return 0;
}

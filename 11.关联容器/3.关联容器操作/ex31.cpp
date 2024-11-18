#include <iostream>
#include <map>
#include <string>
int main(int argc, const char **argv)
{
    std::multimap<std::string, std::string> books{{"aa", "abc"}, {"bb", "abc"}, {"aa", "abd"}};

    /*
        auto iter = books.find("aa");
        if (iter != books.end())
        {
            books.erase(iter);
        }
     */

    for (auto delete_book = books.equal_range("aa");
         delete_book.first != delete_book.second;)
    {
        delete_book.first = books.erase(delete_book.first);
    }

    for (const auto &book : books)
    {
        std::cout << book.first << ": 《" << book.second << "》" << std::endl;
    }

    return 0;
}

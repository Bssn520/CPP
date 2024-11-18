#include <iostream>
#include <map>
#include <string>
int main(int argc, const char **argv)
{
    std::map<std::string, int> map = {{"Dwh", 20}};
    std::map<std::string, int>::iterator map_it = map.begin();
    map_it->second = 21;

    std::cout << map_it->first << " " << map_it->second << std::endl; // Dwh 21

    return 0;
}

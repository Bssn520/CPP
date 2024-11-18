/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-18 20:12:27
 * @LastEditTime: 2024-11-18 20:41:20
 * @Description:
 *
 */

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>


const std::string &
transform(const std::string &s, const std::map<std::string, std::string> &map)
{
    auto map_it = map.find(s);
    if (map_it != map.cend())
        return map_it->second;
    else
        return s;
}

std::map<std::string, std::string> buildMap(std::ifstream &map_file)
{
    std::map<std::string, std::string> trans_map;
    std::string key;
    std::string value;
    while (map_file >> key && std::getline(map_file, value))
    {
        if (value.size() > 1)
            trans_map[key] = value.substr(1);
        else
            throw std::runtime_error("no rule for " + key);
    }

    return trans_map;
}

void word_transform(std::ifstream &map_file, std::ifstream &input)
{
    auto trans_map = buildMap(map_file);
    std::string text;
    while (std::getline(input, text))
    {
        std::istringstream stream(text);
        std::string word;
        bool firstWord = true;
        while (stream >> word)
        {
            if (firstWord)
                firstWord = false;
            else
                std::cout << " ";
            std::cout << transform(word, trans_map);
        }
        std::cout << std::endl;
    }
}

int main(int argc, const char **argv)
{
    std::string map_file_path = argv[1];
    std::string input_path = argv[2];

    std::ifstream map_file(map_file_path);
    std::ifstream input(input_path);

    word_transform(map_file, input);

    return 0;
}

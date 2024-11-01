/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-11-01 19:55:10
 * @LastEditTime: 2024-11-01 20:49:52
 * @Description: 将来自一个文件中的行保存在一个 vector<string>中。然后使用一个 istringstream 从 vector 读取数据元素，每次读取一个单词。
 * 
 * Copyright (c) 2024 by Bssn520, All Rights Reserved. 
 */

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

/**
 * @brief 逐行从文件中读取数据
 * 
 * @param s_v 用来存储每行数据的 vector
 * @param file 要打开的文件路径
 */
void storeByLine(std::vector<std::string> &s_v, std::string file) {
    std::ifstream inputFile(file);

    if (!inputFile) {
        std::cout << "Error: Could not open input file " + file << std::endl;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        s_v.push_back(line);
    }
}

int main(int argc, const char **argv) {
    // 如果参数总数不为2，则提示并返回
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <inputFile_path>" << std::endl;
        return 1;
    }
    // 声明存储 line, word 所需的 vector
    std::vector<std::string> s_line_v, s_word_v;
    storeByLine(s_line_v, argv[1]);// 交由函数处理

    std::string word;         // 存储行内的单词
    std::istringstream record;// 定义输出string流,用来读取行

    // 对每一行(s_line_v的每一个元素即为一行)进行操作，使用 istringstream读取为单词并存进对应的vector
    for (auto line: s_line_v) {
        // record 需要在每次处理新的一行时被重置，否则 record 会保留上一次的内容
        record.clear();
        // 设置当前行内容到 record
        record.str(line);
        // 以单词的形式把行存储进 s_word_v vector
        while (record >> word) {
            s_word_v.push_back(word);
        }
    }

    // 按单词读取并打印
    for (const auto &word: s_word_v) {
        std::cout << word << std::endl;
    }

    return 0;
}

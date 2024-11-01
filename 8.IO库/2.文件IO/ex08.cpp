/*
 * @Author: Bssn520 Bssn520@duck.com
 * @Date: 2024-10-31 11:37:56
 * @LastEditTime: 2024-11-01 17:18:13
 * @Description: 从指定文件中读取数据源并以追加模式输出到目标文件
 * 
 * Copyright (c) 2024 by Bssn520, All Rights Reserved. 
 */


#include "Sales_data_ex41.hpp"
#include <fstream>
#include <iostream>
#include <ostream>

/**
 * @brief 从指定文件中读取数据源并以追加模式输出到目标文件
 * 
 * @param argc 参数总数
 * @param argv 命令行参数 inputFile 和 outputFile
 * @return int 
 */
int main(int argc, char *argv[]) {
    if (argc <= 1 || argc > 3) {// 参数检查
        std::cerr << "Usage: " << argv[0] << " <inputFile_path> <outputFile_path>" << std::endl;
        return 1;
    }

    std::ifstream input(argv[1]);
    if (!input) {// 检查输入文件是否成功打开
        std::cerr << "Error: Could not open input file " << argv[1] << std::endl;
        return 1;
    }

    std::ofstream fileOutput;
    std::ostream *output = &std::cout;
    if (argc == 3) {                                // 如果提供了输出文件路径则尝试打开
        fileOutput.open(argv[2], std::ostream::app);// 以追加模式输出
        if (!fileOutput) {
            std::cerr << "Error: Could not open output file " << argv[2] << std::endl;
            return 1;
        }
        output = &fileOutput;
    }

    Sales_data total;
    if (read(input, total)) {
        Sales_data trans;
        while (read(input, trans)) {
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            } else {
                print(*output, total) << std::endl;
                total = trans;
            }
        }
        print(*output, total) << std::endl;
    } else {
        std::cerr << "No Data?!" << std::endl;
    }

    return 0;
}

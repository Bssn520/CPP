#include "Sales_data_ex41.hpp"
#include <fstream>
#include <iostream>

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
    if (argc == 3) {// 如果提供了输出文件路径则尝试打开
        fileOutput.open(argv[2]);
        if (!fileOutput) {
            std::cerr << "Error: Could not open output file " << argv[2] << std::endl;
            return 1;

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
    }
    
    return 0;
}

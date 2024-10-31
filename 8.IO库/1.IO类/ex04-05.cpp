#include <fstream>
#include <iostream>
#include <string>
#include <vector>

/** 以读模式打开一个文件，将其内容读入到一个 string的 vector中，将每一行作为一个独立的元素存于 vector 中 */
void byLine(std::vector<std::string> &content, const char *path) {
    std::ifstream ifs(path);
    std::string buf;

    if (ifs) {
        while (getline(ifs, buf)) {
            content.push_back(buf);
        }
    } else {
        std::cerr << "Error: Unable to open file " << path << std::endl;
    }

    for (auto &s: content) {
        std::cout << s << std::endl;
    }
}

/** 重写上面的程序，将每个单词作为一个独立的元素进行存储 */
void byWord(std::vector<std::string> &content, const char *path) {
    std::ifstream ifs(path);
    std::string buf;

    if (ifs) {
        while (ifs >> buf) {
            content.push_back(buf);
        }
    } else {
        std::cerr << "Error: Unable to open file " << path << std::endl;
    }

    for (auto s: content) {
        std::cout << s << std::endl;
    }
}


int main(int argc, char *argv[]) {
    if (argc < 1) {
        std::cerr << "Usage: " << argv[0] << " <file_path>" << std::endl;

        return 1;
    }

    std::vector<std::string> contentV1, contentV2;

    byLine(contentV1, argv[1]);
    byWord(contentV2, argv[1]);

    return 0;
}

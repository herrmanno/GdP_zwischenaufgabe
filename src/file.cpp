#include <string>
#include <fstream>
#include <streambuf>

std::string getFileContent(const std::string& file) {
    std::ifstream fs(file);
    const std::string s((std::istreambuf_iterator<char>(fs)), (std::istreambuf_iterator<char>()));
    return s;
}
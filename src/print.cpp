#include "./print.hpp"
#include <iomanip>

void printWords(const std::vector<WordCount> &vec, std::ostream &os) {
     auto printWidth = maxLength(vec);
     for (auto pair : vec) {
        os << std::left << std::setw(printWidth) << pair.first << "  "
            << std::setw(5) << std::right << pair.second << std::endl;
            //                                              ^
            //                                              flushes more often then needed,
            //                                              used for easier cross-platform support
    }
}
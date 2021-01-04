#include <iostream>
#include <fstream>
#include "./args.hpp"
#include "./file.hpp"
#include "./wordcount.hpp"
#include "./print.hpp"

int main(int argc, char** argv) {
    const Args args = parseArgs(argc, argv);

    if (!args.filename.has_value()) {
        std::cerr << "Usage: " << argv[0] << " [-o outfile] file" << std::endl;
        return 1;
    } else if (!std::ifstream(*args.filename).good()) {
        std::cerr << "File '" << *args.filename << "' does not exist" << std::endl;
        return 1;
    } else {
        auto s = getFileContent(*args.filename);
        auto vs = countWords(s);

        if (args.outFilename.has_value()) {
            auto os = std::ofstream(*args.outFilename);
            printWords(vs, os);
        } else {
            printWords(vs, std::cout);
        }

        return 0;
    }
}
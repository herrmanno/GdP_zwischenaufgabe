#include <string>
#include <vector>
#include <optional>
#include "./args.hpp"

Args parseArgs(int argc, char* argv[]) {
    if (argc < 2) {
        return {};
    } else {
        std::vector<std::string> args(&argv[1], &argv[argc]);
        std::optional<std::string> filename;
        std::optional<std::string> outFilename;

        auto outIndex = std::find(args.begin(), args.end(), "-o");
        if (outIndex != args.end() && outIndex + 1 != args.end()) {
            outFilename.emplace(*(outIndex + 1));
            args.erase(outIndex + 1);
            args.erase(outIndex);
        }

        filename.emplace(args.front());
        
        return Args { filename, outFilename };
    }
}
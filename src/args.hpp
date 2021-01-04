#pragma once

#include <optional>

/**
 * Commandline arguments for the main routine
 */
struct Args {
    /** the filename argument */
    const std::optional<std::string> filename;
    /** the (optional) outfile argument argument */
    const std::optional<std::string> outFilename;
};

/**
 * Parses the program's command line arguments from the given 'argc,argv' tuple
 * 
 * @param argc the global program argument count
 * @param argv the global program arguments
 * @returns the parsed program arguments
 */
Args parseArgs(int argc, char** argv);
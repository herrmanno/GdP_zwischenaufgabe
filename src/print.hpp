#pragma once

#include "./wordcount.hpp"
#include <iostream>
#include <vector>

/**
 * Pretty-prints a vector of WordCount objects to an out stream
 * 
 * @param vec the data to print
 * @param os the out stream to print to
 */
void printWords(const std::vector<WordCount> &vec, std::ostream &os);
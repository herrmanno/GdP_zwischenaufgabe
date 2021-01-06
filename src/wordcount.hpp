#pragma once

#include <stdint.h>
#include <string>
#include <vector>

/**
 * A Pair of (word, number of occurrences)
 */
using WordCount = std::pair<std::string, unsigned int>;

/**
 * Counts the indiviaul words of a string
 * 
 * word are one or more adjacent characters, where at least one character is an alpha character
 * (in terms of ASCII) and are seperated by non-alphanum characters (in terms of ASCII).
 * 
 * @param str the string whose words shall be counted
 * @returns a vector of {@link WordCount} objects
 */
std::vector<WordCount> countWords(const std::string &str);

/**
 * Retrieves the max word length (= length of longest word) of a vector of {@link WordCount} objects
 * 
 * @param vec the vector of WordCount objects
 * @returns the length of the longest word (= first value of a WordCount tuple) of {@code vec}
 */
int maxLength (const std::vector<WordCount> &vec);
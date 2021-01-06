#include "./wordcount.hpp"
#include <map>

/**
 * @returns if c is a non-alphanumerical char w/ ord <= 255
 */
bool isSpecialChar(char c) {
    return (c <= 46) || (c >= 58 && c <= 64) || (c >= 91 && c <= 96) || (c >= 123 && c <= 127);
}

/**
 * Splits a string at every special char {@see isSpecialChar} and returns a list of not-empty tokens
 */
std::vector<std::string> splitString(const std::string &str) {
    std::vector<std::string> v;
    std::string s;
    for (auto c : str) {
        if (isSpecialChar(c)) {
            if (!s.empty()) {
                // only track words containing at least one alpha character
                if (std::find_if(s.begin(), s.end(), isalpha) != s.end()) {
                    v.push_back(s);
                }
                s.clear();
            }
        } else {
            s.push_back(c);
        }
    }
    if (!str.empty() && std::find_if(s.begin(), s.end(), isalpha) != s.end()) {
        v.push_back(s);
    }
    return v;
}

/**
 * Maps identic strings in a string vector to the number of their apperance in said vector
 * 
 * @returns Map { word -> occurence count }
 */
std::map<std::string,unsigned int> countWords(const std::vector<std::string> &vec) {
    std::map<std::string,unsigned int> m;
    for (auto &word : vec) {
        auto count = m.find(word);
        if (count == m.end()) {
            m[word] = 1;
        } else {
            m[word] = count->second + 1;
        }
    }
    return m;
}

/**
 * Sorts the contents of a {word -> count} map as a vector of WordCount objects
 * 
 * Sorts by count(a) > count(b), word(a) < word(b)
 */
std::vector<WordCount> sortWordCount(const std::map<std::string,unsigned int> &map) {
    std::vector<WordCount> vec;
    std::copy(map.begin(), map.end(), std::back_inserter(vec));
    std::sort(vec.begin(), vec.end(), [](auto p1, auto p2) {
        return  p1.second == p2.second ? p1.first < p2.first : p1.second > p2.second;
    });
    return vec;
}

std::vector<WordCount> countWords(const std::string &str) {
    auto v = splitString(str);
    auto m = countWords(v);
    return sortWordCount(m);
}

int maxLength (const std::vector<WordCount> &vec) {
    if (vec.empty()) {
        return 0;
    } else {
        auto me = std::max_element(vec.begin(), vec.end(), [](auto p1, auto p2) {
            return p1.first.length() < p2.first.length();
        });

        return me->first.length();
    }
}
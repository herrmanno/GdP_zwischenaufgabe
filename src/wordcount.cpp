#include "./wordcount.hpp"

bool isSpecialChar(char c) {
    return (c <= 46) || (c >= 58 && c <= 64) || (c >= 91 && c <= 96) || (c >= 123 && c <= 127);
}

std::vector<std::string> splitString(const std::string &str) {
    std::vector<std::string> v;
    std::string s;
    for (auto c : str) {
        if (isSpecialChar(c)) {
            if (!s.empty()) {
                if (std::find_if(s.begin(), s.end(), isalpha) != s.end()) {
                    v.push_back(s);
                }
                s.clear();
            }
        } else {
            s.push_back(c);
        }
    }
    if (!str.empty()) {
        v.push_back(s);
    }
    return v;
}

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

std::vector<std::pair<std::string,unsigned int> > sortWordCount(const std::map<std::string,unsigned int> &map) {
    std::vector<std::pair<std::string,unsigned int> > vec;
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

int maxLength (const std::vector<std::pair<std::string,unsigned int> > &vec) {
    if (vec.empty()) {
        return 0;
    } else {
        auto me = std::max_element(vec.begin(), vec.end(), [](auto p1, auto p2) {
            return p1.first.length() < p2.first.length();
        });

        return me->first.length();
    }
}
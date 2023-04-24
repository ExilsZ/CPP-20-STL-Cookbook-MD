#include <algorithm>
#include <format>
#include <iostream>
#include <iterator>
#include <set>
#include <string>

using std::cin, std::cout, std::endl;
using std::format;
using std::string;

using input_it = std::istream_iterator<string>;

auto main() -> int {
    std::set<std::string> words;
    input_it it{cin};
    input_it end{};
    std::copy(it, end, std::inserter(words, words.end()));
    for (const string &w : words) {
        cout << format("{} ", w);
    }
    cout << endl;
}

// "a a a b c this that this foo foo foo" | .\build\windows\x64\release\ch03_3.10.exe

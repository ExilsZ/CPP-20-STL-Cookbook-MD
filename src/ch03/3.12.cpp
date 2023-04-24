/*
 * @Author       : ExilsZ
 * @LastEditor   : ExilsZ
 * @Date         : 23-04-22 15:47
 * @LastEditTime :
 * @Description  : 单词计数
 */

#include <algorithm>
#include <cctype>
#include <format>
#include <iostream>
#include <map>
#include <regex>
#include <string>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
using std::format;
using std::map;
using std::pair;
using std::regex;
using std::smatch;
using std::sregex_iterator;
using std::string;
using std::vector;

namespace ranges = std::ranges;

namespace ez {
    constexpr const char *re{"(\\w+)"};
}

auto main() -> int {
    map<string, int> wordmap{};
    vector<pair<string, int>> wordvec{};
    regex word_re(ez::re);
    size_t total_words{};

    for (string s{}; cin >> s;) {
        auto words_begin{sregex_iterator(s.begin(), s.end(), word_re)};
        auto words_end{sregex_iterator()};

        for (auto r_it{words_begin}; r_it != words_end; ++r_it) {
            const smatch &match{*r_it};
            auto word_str{match.str()};

            ranges::transform(word_str, word_str.begin(),
                              [](unsigned char c) { return tolower(c); });

            auto [map_it, result] = wordmap.try_emplace(word_str, 0);
            auto &[w, count] = *map_it;
            ++total_words;
            ++count;
        }
    }

    auto unique_words = wordmap.size();
    wordvec.reserve(unique_words);
    ranges::move(wordmap, back_inserter(wordvec));
    ranges::sort(wordvec, [](const auto &a, const auto &b) {
        if (a.second != b.second) {
            return (a.second > b.second);
        }
        return (a.first < b.first);
    });

    cout << format("total word count: {}\n", total_words);
    cout << format("unique word count: {}\n", unique_words);

    for (int limit{20}; auto &[w, count] : wordvec) {
        cout << format("{}: {}\n", count, w);
        if (--limit == 0) {
            break;
        }
    }
}

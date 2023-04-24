/*
 * @Author       : ExilsZ
 * @LastEditor   : ExilsZ
 * @Date         : 23-03-16 17:54
 * @LastEditTime : 23-04-11 17:39
 * @Description  :
 */

#include <algorithm>
#include <format>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::format;
using std::string;

// 旧的删除操作，通常用 erase-remove 从 STL 容器中删除元素
template <typename Tc, typename Tv>
void remove_value(Tc &c, const Tv &v) {
    auto remove_it = std::remove(c.begin(), c.end(), v);
    c.erase(remove_it, c.end());
}

void print_seq(auto &r) {
    cout << format("size({}): ", r.size());
    for (auto &e : r) {
        cout << format("{} ", e);
    }
    cout << "\n";
}

void print_assoc(auto &r) {
    cout << format("size({}): ", r.size());
    for (auto &[k, v] : r) {
        cout << format("{}:{} ", k, v);
    }
    cout << "\n";
}

auto main() -> int {
    std::vector<int> vec{1, 2, 3, 4, 4, 3, 2, 1, 1, 2, 3, 4};
    remove_value(vec, 1);
    print_seq(vec);

    // 新的擦除功能
    vec = {1, 2, 3, 4, 4, 3, 2, 1, 1, 2, 3, 4};
    std::erase(vec, 1);
    print_seq(vec);

    // 带谓词的版本
    std::erase_if(vec, [](auto x) { return x % 2 == 0; });
    print_seq(vec);

    // 关联容器
    std::map<int, string> m{{1, "uno"}, {2, "dos"}, {3, "tres"}, {4, "quatro"}, {5, "cinco"}};
    print_assoc(m);
    erase_if(m, [](auto &p) { auto& [k, v] = p; return k % 2 == 0; });
    print_assoc(m);
}

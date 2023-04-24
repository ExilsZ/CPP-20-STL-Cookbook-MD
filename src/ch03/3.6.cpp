/*
 * @Author       : ExilsZ
 * @LastEditor   : ExilsZ
 * @Date         : 23-04-16 13:35
 * @LastEditTime :
 * @Description  : 保持 vector 顺序的插入
 */

#include <algorithm>
#include <format>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::format;
using std::string;

using Vstr = std::vector<string>;

void printv(const auto &v) {
    for (const auto &e : v) {
        cout << format("{} ", e);
    }
    cout << "\n";
}

void psorted(const Vstr &v) {
    if (std::ranges::is_sorted(v)) {
        cout << "sorted: ";
    } else {
        cout << "unsorted: ";
    }
    printv(v);
}

template <typename C, typename E>
void insert_sorted(C &c, const E &e) {
    const auto pos{std::ranges::lower_bound(c, e)};
    // lower_bound() 查找不小于实参的第一个元素
    c.insert(pos, e);
}

auto main() -> int {
    Vstr v{"Miles",
           "Hendrix",
           "Beatles",
           "Zappa",
           "Shostakovich"};

    psorted(v);

    std::ranges::sort(v);
    psorted(v);

    insert_sorted(v, "Ella");
    insert_sorted(v, "Stones");
    psorted(v);
}

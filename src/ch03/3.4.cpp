/*
 * @Author       : ExilsZ
 * @LastEditor   : ExilsZ
 * @Date         : 23-03-16 17:54
 * @LastEditTime : 23-04-11 17:39
 * @Description  : 常数时间内从未排序的 vector 中删除项
 */

#include <format>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::format;
using std::string;

void printc(auto &r) {
    cout << format("size({}) ", r.size());
    for (auto &e : r) {
        cout << format("{} ", e);
    }
    cout << "\n";
}

template <typename T>
void quick_delete(T &v, size_t idx) {
    if (idx < v.size()) {
        v[idx] = std::move(v.back());
        v.pop_back();
    }
}

template <typename T>
void quick_delete(T &v, typename T::iterator it) {
    if (it < v.end()) {
        *it = std::move(v.back());
        v.pop_back();
    }
}

auto main() -> int {
    std::vector v{12, 196, 47, 38, 19};
    printc(v);
    auto it = std::ranges::find(v, 47);
    quick_delete(v, it);
    printc(v);
    quick_delete(v, 1);
    printc(v);
}

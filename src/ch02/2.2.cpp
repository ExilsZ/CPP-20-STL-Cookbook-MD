/*
 * @Author       : ExilsZ
 * @LastEditor   : ExilsZ
 * @Date         : 23-03-14 18:24
 * @LastEditTime : 23-03-14 18:24
 * @Description  : span 类
 */

#include <format>
#include <iostream>
#include <span>

using std::cout;
using std::format;
using std::span;

template <typename T>
void pspan(span<T> s) {
    cout << format("number of elements: {}\n", s.size());
    cout << format("size of span: {}\n", s.size_bytes());
    for (auto e : s) {
        cout << format("{} ", e);
    }
    cout << "\n";
}

auto main() -> int {
    int carray[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    pspan<int>(carray);
}

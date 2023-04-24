/*
 * @Author       : ExilsZ
 * @LastEditor   : ExilsZ
 * @Date         : 23-03-14 15:02
 * @LastEditTime : 23-03-14 15:37
 * @Description  : concept and constraint
 */

#include <concepts>
#include <iostream>

using std::cout;

// 没有 concept 时
template <typename T>
auto arg_v0(const T &arg) -> T { return arg + 42; }

template <typename T>
concept Numeric = std::integral<T> || std::floating_point<T>;

template <Numeric T>
auto arg_v1(const T &arg) -> T { return arg + 42; }

auto main() -> int {
    const char *n = "7";
    cout << arg_v0(n) << "\n";
    // cout << arg_v1(n) << "\n"; // 报错：constraints not satisfied
}

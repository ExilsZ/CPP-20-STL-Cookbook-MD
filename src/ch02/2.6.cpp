#include <cstdio>
#include <format>
#include <iostream>
#include <string>
#include <type_traits>

using std::cout;
using std::format;
using std::string;

// if constexpr(condition) 语句用于根据编译时条件执行代码的地方
// 条件可以是 bool 类型的 constexpr 表达式
// 在编译时求值

template <typename T>
auto value_of(const T v) {
    if constexpr (std::is_pointer_v<T>) {
        return *v;
    } else {
        return v;
    }
}

auto main() -> int {
    int x{47};
    int *y{&x};
    cout << format("value is {}\n", value_of(x));
    cout << format("value is {}\n", value_of(y));
}

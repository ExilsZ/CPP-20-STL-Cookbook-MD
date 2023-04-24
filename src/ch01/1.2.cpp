/*
 * @Author       : ExilsZ
 * @LastEditor   : ExilsZ
 * @Date         : 23-03-12 17:06
 * @LastEditTime : 23-03-13 11:29
 * @Description  : 测试 C++20 的格式化输出，GCC 和 Clang 尚未实现，可以使用第三方库 fmt
 */

#include <cstdio>
#include <format>
#include <iostream>
#include <numbers>
#include <string>
#include <string_view>

using std::cout;
using std::format;
using std::string;

template <typename... Args>
void print(const std::string_view fmt_str, Args &&...args) {
    auto fmt_args{std::make_format_args(args...)};
    string outstr{vformat(fmt_str, fmt_args)};
    fputs(outstr.c_str(), stdout);
}

auto main() -> int {
    string who{"everyone"};
    int ival{42};
    double pi{std::numbers::pi};
    cout << format("Hello, {}!\n", who);   // Hello, everyone!
    cout << format("Integer: {}\n", ival); // Integer: 42
    cout << format("π: {}\n", pi);         // π: 3.141592653589793

    cout << format("Hello {1} {0}\n", ival, who); // Hello everyone 42
    cout << format("Hola {0} {1}\n", ival, who);  // Hola 42 everyone
    cout << format("{:.<10}\n", ival);            // 42........
    cout << format("{:.>10}\n", ival);            // ........42
    cout << format("{:.^10}\n", ival);            // ....42....
    cout << format("{: ^10}\n", ival);            //     42
    cout << format("{:~^10}\n", ival);            // ~~~~42~~~~
    cout << format("π: {:.5}\n", pi);             // π: 3.1416

    print("Hello, {}!\n", who);
    print("π: {}\n", pi);
    print("Hello {1} {0}\n", ival, who);
    print("{:.^10}\n", ival);
    print("{:.5}\n", pi);
}

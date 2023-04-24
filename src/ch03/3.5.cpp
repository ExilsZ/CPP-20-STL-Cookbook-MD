/*
 * @Author       : ExilsZ
 * @LastEditor   : ExilsZ
 * @Date         : 23-03-16 17:54
 * @LastEditTime : 23-04-11 17:39
 * @Description  :
 */

#include <format>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::format;
using std::string;

auto main() -> int {
    std::vector v{19, 71, 47, 192, 4004};

    auto &a = v[2]; // 不执行边界检查
    auto &b = v[5]; // 不执行边界检查，编译无异常，运行不抛出异常
    cout << format("element is {}\n", b);

    // auto &c = v.at(2); // 执行边界检查
    // auto &d = v.at(5); // 执行边界检查，编译无异常，运行抛出异常
    // cout << format("element is {}\n", d);

    try {
        v.at(5) = 2001;
    } catch (const std::out_of_range &e) {
        cout << format("Ouch!\n{}\n", e.what()); // invalid vector subscript
    }
}

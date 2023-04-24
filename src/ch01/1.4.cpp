/*
 * @Author       : ExilsZ
 * @LastEditor   : ExilsZ
 * @Date         : 23-03-13 15:35
 * @LastEditTime : 23-03-13 15:35
 * @Description  : 安全地比较不同类型的整数
 */

#include <cstdio>
#include <iostream>
#include <string>
#include <utility>

// using std::cout;
// using std::endl;
using std::string;

auto main() -> int {
    int x{-3};
    unsigned y{7};

    // 输出 false
    if (x < y) {
        std::puts("true");
    } else {
        std::puts("false");
    }

    if (std::cmp_less(x, y)) {
        std::puts("true");
    } else {
        std::puts("false");
    }
    std::cout << std::cmp_equal(x, y);         // x == y is false
    std::cout << std::cmp_not_equal(x, y);     // x != y is true
    std::cout << std::cmp_less(x, y);          // x < y is true
    std::cout << std::cmp_less_equal(x, y);    // x <= y is true
    std::cout << std::cmp_greater(x, y);       // x > y is false
    std::cout << std::cmp_greater_equal(x, y); // x >= y is false
}

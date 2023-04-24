/*
 * @Author       : ExilsZ
 * @LastEditor   : ExilsZ
 * @Date         : 23-03-14 21:36
 * @LastEditTime : 23-03-14 21:36
 * @Description  : 结构化绑定
 */

#include <array>
#include <cstdint>
#include <format>
#include <iostream>
#include <map>
#include <string>
#include <tuple>

using std::array;
using std::cin;
using std::cout;
using std::endl;
using std::format;
using std::string;

struct div_result {
    long quo;
    long rem;
};

// 对函数的返回使用结构化绑定
auto int_div(const long &num, const long &denom) -> div_result {
    struct div_result r {};

    r.quo = num / denom;
    r.rem = num % denom;
    return r;
}

const std::map<string, uint64_t> inhabitants{
    {"humans", 7000000000},
    {"pokemon", 17863376},
    {"klingons", 24246291},
    {"cats", 1086881528}};

// 使用结构化绑定来检索键值对
auto make_commas(const uint64_t num) -> string {
    string s{std::to_string(num)};
    for (unsigned long long l = s.length() - 3; l > 0; l -= 3) {
        s.insert(l, ",");
    }
    return s;
}

auto main() -> int {
    { // 和 C 数组 一起使用
        int nums[]{1, 2, 3, 4, 5};
        auto [a, b, c, d, e] = nums;
        cout << format("{} {} {} {} {}\n", a, b, c, d, e);
    }
    { // 和 tuple 一起使用
        std::tuple<int, double, string> nums{1, 2.7, "three"};
        auto [a, b, c] = nums;
        cout << format("{} {} {}\n", a, b, c);
    }
    { // 和结构体一起使用
        struct Things {
            int i{};
            double d{};
            string s{};
        };

        Things nums{1, 2.7, "three"};
        auto [a, b, c] = nums;
        cout << format("{} {} {}\n", a, b, c);
    }
    { // 和 STL 数组一起使用
        array<int, 5> nums{1, 2, 3, 4, 5};
        auto &[a, b, c, d, e] = nums; // 带有结构化绑定的引用
        cout << format("{} {} {} {} {}\n", a, b, c, d, e);

        // 修改绑定容器中的值同时避免数据复制
        a = 10;
        cout << format("nums[0] = {}, a = {} \n", nums[0], a); // 1 10}
    }
    { // const 数组
        const array<int, 5> nums{1, 2, 3, 4, 5};
        const auto &[a, b, c, d, e] = nums;
        // a                     = 10;
    }
    { // const 绑定
        array<int, 5> nums{1, 2, 3, 4, 5};
        const auto &[a, b, c, d, e] = nums;
        // a                           = 10;
        nums[0] = 10;
    }
    { // 对函数的返回使用结构化绑定
        auto [quo, rem] = int_div(47, 5);
        cout << format("quotient: {}, remainder: {}\n", quo, rem);
    }
    { // 使用结构化绑定来检索键/值对
        for (const auto &[creature, pop] : inhabitants) {
            cout << format("there are {} {}\n", make_commas(pop), creature);
        }
    }
}

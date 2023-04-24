/*
 * @Author       : ExilsZ
 * @LastEditor   : ExilsZ
 * @Date         : 23-03-14 11:14
 * @LastEditTime : 23-04-11 17:36
 * @Description  :
 */

#include <compare>
#include <iostream>

// 不使用三路比较符需要重载多个比较符
/* struct Num {
    int a;
    constexpr bool operator==(const Num &rhs) const { return a == rhs.a; }
    constexpr bool operator!=(const Num &rhs) const { return !(a == rhs.a); }
    constexpr bool operator<(const Num &rhs) const { return a < rhs.a; }
    constexpr bool operator>(const Num &rhs) const { return rhs.a < a; }
    constexpr bool operator<=(const Num &rhs) const { return !(rhs.a < a); }
    constexpr bool operator>=(const Num &rhs) const { return !(a < rhs.a); }
}; */

class Num {
    int x{0};

  public:
    constexpr Num(int x) : x{x} {}

    auto operator<=>(const Num &) const = default;
};

auto main() -> int {
    Num a{1};
    Num b{2};
    std::cout << (a < b) << "\n";
    std::cout << (a > b) << "\n";
    std::cout << (a == b) << "\n";
    std::cout << (a != b) << "\n";
}

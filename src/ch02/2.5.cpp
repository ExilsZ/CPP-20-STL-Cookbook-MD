/*
 * @Author       : ExilsZ
 * @LastEditor   : ExilsZ
 * @Date         : 23-03-15 17:37
 * @LastEditTime : 23-03-15 17:53
 * @Description  : 模板参数推导
 */

#include <format>
#include <iostream>
#include <string>
#include <type_traits>
#include <typeinfo>

using namespace std::string_literals;

using std::cout;
using std::format;
using std::string;

template <typename T1, typename T2>
auto f(const T1 /*a*/, const T2 /*b*/) -> const string {
    return format("{} {}", typeid(T1).name(), typeid(T2).name());
}

// requires template deduction guide
template <typename T>
class Sum {
    T v{};

  public:
    template <typename... Ts>
    Sum(Ts &&...values) : v{(values + ...)} {}

    [[nodiscard]] auto value() const -> const T & { return v; }
};

// template deduction guide
template <typename... Ts>
Sum(Ts &&...ts) -> Sum<std::common_type_t<Ts...>>;

auto main() -> int {
    // 当模板函数或类模板构造函数 (C++17 起) 的实参类型足够清楚
    // 无需使用模板实参编译器就能进行模板实参推导
    cout << format("T1 T2: {}\n", f(47, 47L));
    cout << format("T1 T2: {}\n", f(47L, 47.0));
    cout << format("T1 T2: {}\n", f(47.0, "47"));
    // PKc: pointer(P) const(K) char(c)

    Sum s1{1U, 2.0, 3, 4.0F};
    Sum s2{"abc"s, "def"};

    auto v1 = s1.value();
    auto v2 = s2.value();
    cout << format("s1 is {} {}, s2 is {} {}\n", typeid(v1).name(), v1, typeid(v2).name(), v2);
}

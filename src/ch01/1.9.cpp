/*
 * @Author       : ExilsZ
 * @LastEditor   : ExilsZ
 * @Date         : 23-03-14 17:33
 * @LastEditTime : 23-03-14 17:33
 * @Description  : 范围和视图，编译器可能不支持
 */

#include <algorithm>
#include <iostream>
#include <ranges>
#include <vector>
using std::vector;

namespace ranges = std::ranges;

auto main() -> int {
    const vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto result_1 = ranges::take_view(nums, 5); // 返回前 n 个元素的视图
    for (auto v : result_1) { std::cout << v << " "; }
    std::cout << "\n";

    auto result_2 = nums | std::views::take(5);
    for (auto v : result_2) { std::cout << v << " "; }
    std::cout << "\n";

    const vector<int> nums_2{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto result_3 = nums_2 | std::views::take(5) | std::views::reverse;
    for (auto v : result_3) { std::cout << v << " "; }
    std::cout << "\n";

    auto result_4 = nums | std::views::filter([](int i) { return 0 == i % 2; });
    for (auto v : result_4) { std::cout << v << " "; }
    std::cout << "\n";

    auto result_5 = nums | std::views::transform([](int i) { return i * i; });
    for (auto v : result_5) { std::cout << v << " "; }
    std::cout << "\n";

    auto rnums = std::views::iota(1, 10);
    for (auto v : rnums) { std::cout << v << " "; }
    std::cout << "\n";

    vector<int> vi{0, 1, 2, 3, 4, 5};
    ranges::take_view tv{vi, 2};
    for (int i : tv) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    vector<int> v{1, 3, 5, 2, 4, 6};
    std::ranges::sort(v);
    for (int i : v) {
        std::cout << i << " ";
    }
    std::cout << "\n";
}

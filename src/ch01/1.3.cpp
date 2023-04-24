/*
 * @Author       : ExilsZ
 * @LastEditor   : ExilsZ
 * @Date         : 23-03-13 15:03
 * @LastEditTime : 23-03-13 15:04
 * @Description  : 使用编译时 vector 和字符串
 */

#include <iostream>
#include <string>
#include <vector>

using std::string;

constexpr auto use_vector() {
    std::vector<int> vec{1, 2, 3, 4, 5};
    return vec;
}

auto main() -> int {

    // 报错：表达式的计算结果不是常数，(子) 对象指向在常量计算过程中堆分配的内存
    // constexpr auto vec = use_vector();
    // std::cout << vec[0];

    constexpr auto value = use_vector().size();
    std::cout << value;
}

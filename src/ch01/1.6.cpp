/*
 * @Author       : ExilsZ
 * @LastEditor   : ExilsZ
 * @Date         : 23-03-14 14:56
 * @LastEditTime : 23-03-14 14:57
 * @Description  : 查找特性测试宏
 */

#include <iostream>
#include <version>
#ifdef __cpp_lib_three_way_comparison
#    include <compare>
#else
#    error Spaceship has not yet landed
#endif

#if __has_include(<compare>)
#    include <compare>
#else
#    error Spaceship has not yet landed
#endif

auto main() -> int {

#ifdef __cpp_lib_three_way_comparison
    std::cout << "value is " << __cpp_lib_three_way_comparison << "\n";
#endif
}

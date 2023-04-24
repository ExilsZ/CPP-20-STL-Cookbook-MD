/*
 * @Author       : ExilsZ
 * @LastEditor   : ExilsZ
 * @Date         : 23-03-15 15:57
 * @LastEditTime : 23-03-15 16:11
 * @Description  : 在 if 和 switch 语句中初始化变量
 */

#include <cstddef>
#include <iostream>
#include <string>

using std::cout;
using std::string;

auto main() -> int {
    { // 旧写法，变量 pos 暴露在条件语句的作用域之外
        const string artist{"Jimi Hendrix"};
        size_t pos{artist.find("Jimi")};
        if (pos != string::npos) {
            cout << "found\n";
        } else {
            cout << "not found\n";
        }
    }

    { // 新写法，离开 if 语句的作用域，变量不再可见且会调用相关的析构函数
        const string artist{"Jimi Hendrix"};
        if (size_t pos{artist.find("Jimi")}; pos != string::npos) {
            cout << "found\n";
        } else {
            cout << "not found\n";
        }
    }
    const string artist{"Jimi Hendrix"};
    size_t pos{artist.find("Jimi")};
    if (pos != string::npos) {
        cout << "found\n";
    } else {
        cout << "not found\n";
    }
}

/*
 * @Author       : ExilsZ
 * @LastEditor   : ExilsZ
 * @Date         : 23-03-12 17:32
 * @LastEditTime : 23-03-13 11:12
 * @Description  : 测试文件名空格和中文字符输出
 */

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

auto main() -> int {
    string hi{"Hello world!\n"};
    string zh{"你好！\n"};

    cout << hi;
    cout << zh << endl;

    cin.get();
}

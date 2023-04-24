/*
 * @Author       : ExilsZ
 * @LastEditor   : ExilsZ
 * @Date         : 2023-04-16 13:27
 * @LastEditTime :
 * @Description  : 高效地将元素插入到 map 中
 */

#include <format>
#include <iostream>
#include <string>

#include <map>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::format;
using std::string;

struct BigThing {
    string v_;

    BigThing(const char *v) : v_(v) {
        cout << format("BigThing constructed {}\n", v_);
    }
};

using Mymap = std::map<string, BigThing>;

void print(const auto &m) {
    for (const auto &[k, v] : m) {
        cout << format("[{}:{}] ", k, v.v_);
    }
    cout << "\n";
}

auto main() -> int {
    {
        std::map<string, string> m;

        // 将元素插入到 map 中
        m["Miles"] = "Trumpet";
        m.insert(std::pair<string, string>("H", "G"));
        m.emplace("K", "D");
    }

    Mymap m;
    m.emplace("Miles", "Trumpet");  // 调用构造函数
    m.emplace("Hendrix", "Guitar"); // 调用构造函数
    m.emplace("Miles", "Trumpet");  // 重复键值依然构造对象
    print(m);

    m.try_emplace("Krupa", "Drums");   // 调用构造函数
    m.try_emplace("Zappa", "Guitar");  // 调用构造函数
    m.try_emplace("Miles", "Trumpet"); // 重复键值没有构造对象
    print(m);
}

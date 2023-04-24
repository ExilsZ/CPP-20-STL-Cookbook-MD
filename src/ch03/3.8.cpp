/*
 * @Author       : ExilsZ
 * @LastEditor   : ExilsZ
 * @Date         : 23-04-16 13:55
 * @LastEditTime :
 * @Description  : 高效地修改 map 项的键值
 */

#include <format>
#include <iostream>
#include <map>
#include <string>

using Racermap = std::map<unsigned int, std::string>;

using std::cin, std::cout, std::endl;
using std::format;
using std::string;

void printm(const auto &m) {
    cout << "Rank:\n";
    for (const auto &[rank, racer] : m) {
        cout << format("{}:{}\n", rank, racer);
    }
    cout << "\n";
}

template <typename M, typename K>
auto node_swap(M &m, K k1, K k2) -> bool {
    auto node1{m.extract(k1)}; // 返回一个 node_handle 对象
    auto node2{m.extract(k2)};
    if (node1.empty() || node2.empty()) { return false; }
    std::swap(node1.key(), node2.key());
    m.insert(std::move(node1));
    m.insert(std::move(node2));
    return true;
}

auto main() -> int {
    Racermap racers{
        {1, "Mario"}, {2, "Luigi"}, {3, "Bowser"}, {4, "Peach"}, {5, "Donkey Kong Jr"}};
    printm(racers);
    node_swap(racers, 3, 5);
    printm(racers);
}

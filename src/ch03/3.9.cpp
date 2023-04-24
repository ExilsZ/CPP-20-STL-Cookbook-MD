#include <format>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vcruntime.h>

using std::cin, std::cout, std::endl;
using std::format;
using std::string;

struct Coord {
    int x{};
    int y{};
};

using Coordmap = std::unordered_map<Coord, int>;

auto operator==(const Coord &lhs, const Coord &rhs) -> bool {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

namespace std {
    template <>
    struct hash<Coord> {
        auto operator()(const Coord &c) const -> size_t {
            return static_cast<size_t>(c.x) + static_cast<size_t>(c.y);
        }
    };
} // namespace std

void print_Coordmap(const auto &m) {
    for (const auto &[key, value] : m) {
        cout << format("{{ ({}, {}): {} }} ", key.x, key.y, value);
    }
    cout << "\n";
}

auto main() -> int {
    Coordmap m{
        {{0, 0}, 1},
        {{0, 1}, 2},
        {{2, 1}, 3},
    };
    print_Coordmap(m);
    Coord k{0, 1};
    cout << format("{{ ({}, {}): {} }}\n", k.x, k.y, m.at(k));
}

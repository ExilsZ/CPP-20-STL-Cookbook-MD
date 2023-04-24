#include <deque>
#include <format>
#include <iostream>
#include <limits>
#include <map>
#include <string>

using std::cin, std::cout, std::endl;
using std::format;
using std::string;

class RPN {
    std::deque<double> deq_{};
    static constexpr double zero_{0.0};
    static constexpr double inf_{std::numeric_limits<double>::infinity()};

    auto pop_get2() -> std::pair<double, double> {
        if (deq_.size() < 2) {
            return {zero_, zero_};
        }
        double v1{deq_.front()};
        deq_.pop_front();
        double v2{deq_.front()};
        deq_.pop_front();
        return {v2, v1};
    }

    // Finds range-based for loops that can be replaced by a call to std::any_of or std::all_of.
    static auto is_numeric(const string &s) -> bool {
        for (const char c : s) {
            if (c != '.' && (std::isdigit(c) == 0)) {
                return false;
            }
        }
        return true;
    }

    auto optor(const string &op) {
        std::map<string, double (*)(double, double)> opmap{
            {"+", [](double l, double r) { return l + r; }},
            {"-", [](double l, double r) { return l - r; }},
            {"*", [](double l, double r) { return l * r; }},
            {"/", [](double l, double r) { return l / r; }},
            {"^", [](double l, double r) { return pow(l, r); }},
            {"%", [](double l, double r) { return fmod(l, r); }},
        };
        if (opmap.find(op) == opmap.end()) { return zero_; }

        auto [l, r] = pop_get2();

        if (op == "/" && r == zero_) {
            deq_.push_front(inf_);
        } else {
            deq_.push_front(opmap.at(op)(l, r));
        }

        return deq_.front();
    }

  public:
    auto op(const string &s) -> double {
        if (is_numeric(s)) {
            double v{std::stod(s, nullptr)};
            deq_.push_front(v);
            return v;
        }
        return optor(s);
    }

    void clear() { deq_.clear(); }

    [[nodiscard]] auto get_stack_string() const -> string {
        string s{};
        for (auto v : deq_) {
            s += format("{} ", v);
        }
        return s;
    }
};

auto main() -> int {
    RPN rpn;
    for (string o{}; cin >> o;) {
        rpn.op(o);
        auto stack_str{rpn.get_stack_string()};
        cout << format("{}: {}\n", o, stack_str);
    }
}

// "9 6 * 2 3 * +" | .\build\windows\x64\release\ch03_3.11.exe

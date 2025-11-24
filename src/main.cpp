// main.cpp

import input;

import std;

auto main() -> int
{
    try {
        std::println("pipe-keys");
        for (auto input : app::input()) {
            if (input.key != "") {
                std::println("{}", std::move(input.key));
            }
        }
    } catch (...) {
        return 1;
    }
}

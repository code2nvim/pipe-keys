module;

#include <string>
#include <string_view>
#include <unordered_map>

export module data:code;

namespace app {

const auto mapping = std::unordered_map<std::string_view, std::string_view> {
    { "LEFTCTRL", "L-Ctrl" },
    { "RIGHTCTRL", "R-Ctrl" },
};

export auto convert(std::string input) -> std::string
{
    if (input.starts_with("KEY_")) {
        input.replace(0, 4, "");
    }
    return std::string {
        mapping.contains(input) ? mapping.at(input) : input
    };
}

}

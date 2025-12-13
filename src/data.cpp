module;

#include <string>

#include <json/json.h>

export module data;

import :code;

namespace app {

export struct data {
    bool hold;
    std::string type;
    std::string name;
};

export auto to_string(const data& data) -> std::string
{
    Json::Value root;
    root["hold"] = data.hold;
    root["type"] = data.type;
    root["name"] = convert(data.name);

    Json::StreamWriterBuilder builder;
    builder["indentation"] = "";

    return Json::writeString(builder, root);
}

}

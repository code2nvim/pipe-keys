module;

#include <string>

#include <json/json.h>

export module data;

namespace app {

export struct data {
    std::string key;
};

export auto to_string(const data& data) -> std::string
{
    Json::Value root;
    root["key"] = data.key;

    Json::StreamWriterBuilder builder;
    builder["indentation"] = "";

    return Json::writeString(builder, root);
}

}

module;

#include <atomic>
#include <exception>
#include <filesystem>
#include <print>
#include <thread>

#include <gtkmm/application.h>
#include <gtkmm/window.h>

export module window;

import :external;

import data;
import input;

namespace app {

export using Application = Gtk::Application;

namespace {
    void init()
    {
        namespace fs = std::filesystem;
        try {
            const auto des = fs::path { "/tmp/pipe-keys" };
            const auto src = fs::path { "gui" };
            if (fs::exists(des)) {
                fs::remove_all(des);
            }
            fs::copy(src, des, fs::copy_options::recursive);
        } catch (const std::exception& e) {
            std::println("{}", e.what());
        } catch (...) {
            return;
        }
    }
}

export class Window : public Gtk::Window {
public:
    Window();

private:
    WebView web_view_ {};
    std::atomic<bool> loaded_ = false;
    std::jthread thread_ { [this] -> void { send_data(); } };

    void load_page()
    {
        web_view_.allow_file_access();
        web_view_.load_uri("file:///tmp/pipe-keys/index.html");
        loaded_ = true;
    }

    void send_data()
    {
        while (!loaded_) {
            // wait
        }
        for (const auto& data : app::input()) {
            auto content = app::to_string(data);
            std::println("{}", content);
            web_view_.evaluate_javascript(
                std::format("load('{}')", std::move(content)));
        }
    }
};

Window::Window()
{
    init();
    load_page();
    set_child(*web_view_.wrapped());
    signal_close_request().connect(
        [] -> bool { std::exit(0); return false; }, false);
}

}

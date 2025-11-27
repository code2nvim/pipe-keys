module;

#include <string>

#include <gtk/gtk.h>
#include <gtkmm/widget.h>
#include <webkit/webkit.h>

export module window:external;

namespace app {

export class WebView {
public:
    void allow_file_access();
    void evaluate_javascript(const std::string& script);
    void load_uri(const std::string& uri);
    auto wrapped();

private:
    WebKitWebView* web_view_ = WEBKIT_WEB_VIEW(webkit_web_view_new());
};

void WebView::allow_file_access()
{
    auto* settings = webkit_web_view_get_settings(WEBKIT_WEB_VIEW(web_view_));
    webkit_settings_set_allow_file_access_from_file_urls(settings, TRUE);
}

void WebView::evaluate_javascript(const std::string& script)
{
    webkit_web_view_evaluate_javascript(web_view_, script.c_str(), -1,
        nullptr, nullptr, nullptr, nullptr, nullptr);
}

void WebView::load_uri(const std::string& uri)
{
    webkit_web_view_load_uri(web_view_, uri.c_str());
}

auto WebView::wrapped()
{
    return Glib::wrap(GTK_WIDGET(web_view_));
}

}

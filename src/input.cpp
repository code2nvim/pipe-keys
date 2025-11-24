module;

#include <libinput.h>

export module input;

import :data;
import :event;
import :external;
import :resource;

import std;

namespace app {

namespace {
    auto event_input(const app::event_ptr& event) -> app::data
    {
        switch (libinput_event_get_type(event.get())) {
        case LIBINPUT_EVENT_KEYBOARD_KEY:
            return app::keyboard_key(event);
        case LIBINPUT_EVENT_POINTER_BUTTON:
            return app::pointer_button(event);
        case LIBINPUT_EVENT_POINTER_MOTION:
            return app::pointer_motion(event);
        default:
            return app::data { .key = "" };
        }
    }
}

export auto input() -> std::generator<app::data>
{
    const auto udev = app::make_udev();
    const libinput_interface interface = {
        .open_restricted = app::open_restricted,
        .close_restricted = app::close_restricted,
    };
    const auto libinput = app::make_libinput(&interface, nullptr, udev.get());
    libinput_udev_assign_seat(libinput.get(), "seat0");
    app::pollfd fds = {
        .fd = libinput_get_fd(libinput.get()),
        .events = 0x001, // POLLIN from <poll.h>
        .revents = 0,
    };
    for (;;) {
        app::poll(&fds);
        libinput_dispatch(libinput.get());
        while (auto event = app::make_event(libinput.get())) {
            co_yield event_input(event);
        }
    }
}

}

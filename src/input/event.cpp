module;

#include <libevdev/libevdev.h>
#include <libinput.h>

export module input:event;

import :data;
import :resource;

import std;

namespace app {

export auto keyboard_key(const app::event_ptr& event) -> app::data
{
    auto* keyboard = libinput_event_get_keyboard_event(event.get());
    const std::string name {
        libevdev_event_code_get_name(0x01, // EV_KEY <linux/input-event-codes.h>
            libinput_event_keyboard_get_key(keyboard)),
    };
    switch (libinput_event_keyboard_get_key_state(keyboard)) {
    case LIBINPUT_KEY_STATE_PRESSED:
    case LIBINPUT_KEY_STATE_RELEASED:
        return app::data { .key = name };
    };
}

export auto pointer_button(const app::event_ptr& event) -> app::data
{
    auto* pointer = libinput_event_get_pointer_event(event.get());
    const std::string name {
        libevdev_event_code_get_name(0x01, // EV_KEY <linux/input-event-codes.h>
            libinput_event_pointer_get_button(pointer)),
    };
    switch (libinput_event_pointer_get_button_state(pointer)) {
    case LIBINPUT_BUTTON_STATE_PRESSED:
    case LIBINPUT_BUTTON_STATE_RELEASED:
        return app::data { .key = name };
    };
}

export auto pointer_motion(const app::event_ptr& event) -> app::data
{
    auto* pointer = libinput_event_get_pointer_event(event.get());
    const auto [mov_x, mov_y] = std::tuple {
        libinput_event_pointer_get_dx(pointer),
        libinput_event_pointer_get_dy(pointer),
    };
    // NOLINTBEGIN
    auto arrow = [](int key) -> std::string_view {
        switch (key) {
        case 0b1000:
            return "←";
        case 0b0100:
            return "↑";
        case 0b0010:
            return "→";
        case 0b0001:
            return "↓";
        case 0b1100:
            return "↖";
        case 0b0110:
            return "↗";
        case 0b0011:
            return "↘";
        case 0b1001:
            return "↙";
        default:
            return " ";
        };
    };
    return app::data { .key = std::format("{}",
                           arrow((mov_x < 0.0 ? 0b1000 : 0b0000)
                               | (mov_y < 0.0 ? 0b0100 : 0b0000)
                               | (mov_x > 0.0 ? 0b0010 : 0b0000)
                               | (mov_y > 0.0 ? 0b0001 : 0b0000))) };
    // NOLINTEND
}

}

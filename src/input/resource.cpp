module;

#include <libinput.h>
#include <libudev.h>

export module input:resource;

import std;

namespace app {

export using udev_ptr = std::unique_ptr<udev, std::function<void(udev*)>>;

export auto make_udev()
{
    return udev_ptr {
        udev_new(),
        [](udev* udev) -> void {
            udev_unref(udev);
        },
    };
}

export using libinput_ptr = std::unique_ptr<libinput, std::function<void(libinput*)>>;

export auto make_libinput(const libinput_interface* interface, void* user_data, udev* udev)
{
    return libinput_ptr {
        libinput_udev_create_context(interface, user_data, udev),
        [](libinput* libinput) -> void {
            libinput_unref(libinput);
        }
    };
}

export using event_ptr = std::unique_ptr<libinput_event, std::function<void(libinput_event*)>>;

export auto make_event(libinput* libinput)
{
    return event_ptr {
        libinput_get_event(libinput),
        [](libinput_event* event) -> void {
            libinput_event_destroy(event);
        },
    };
}

}

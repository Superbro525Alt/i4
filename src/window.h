#pragma once

#include <Windows.h>
#include <string>

namespace core {
namespace window {

class Window {
    public:
    explicit Window(HWND native_handle);

    HWND GetNativeHandle();

    std::string GetTitle();
    bool IsVisible();
    bool IsForeground();
    bool IsMinimized();
    bool IsMaximized();

    private:
    HWND native_handle;
};
}
}
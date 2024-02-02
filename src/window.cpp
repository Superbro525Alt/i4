#include "window.h"

#include <iostream>

namespace core {
namespace window {

Window::Window(HWND native_handle) {
    this->native_handle = native_handle;
}

HWND Window::GetNativeHandle() {
    return this->native_handle;
}

std::string Window::GetTitle() {
    char title[256];
    GetWindowTextA(this->native_handle, title, sizeof(title));
    return std::string(title);
}

bool Window::IsVisible() {
    return IsWindowVisible(this->native_handle);
}

bool Window::IsForeground() {
    return GetForegroundWindow() == this->native_handle;
}

bool Window::IsMinimized() {
    return IsIconic(this->native_handle);
}

bool Window::IsMaximized() {
    return IsZoomed(this->native_handle);
}
} // namespace window
} // namespace core
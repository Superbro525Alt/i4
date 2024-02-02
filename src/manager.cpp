#include "manager.h"

namespace core {
namespace window {

WindowManager::WindowManager(core::config::ConfigManager *config_manager) {
    this->config_manager = config_manager;
}

WindowManager::WindowManager() {
    this->config_manager = new core::config::ConfigManager();
}

WindowManager::~WindowManager() {
    delete this->config_manager;
}

void WindowManager::AddWindow(core::window::Window *window) {
    this->windows.push_back(window);
}

void WindowManager::RemoveWindow(core::window::Window *window) {
    for (int i = 0; i < static_cast<int>(this->windows.size()); i++) {
        if (this->windows[i]->GetNativeHandle() == window->GetNativeHandle()) {
            this->windows.erase(this->windows.begin() + i);
            break;
        }
    }
}

std::vector<core::window::Window*> WindowManager::GetWindows() {
    return this->windows;
}

std::vector<core::window::Window*> WindowManager::GetActiveWindows() {
    std::vector<core::window::Window*> windows = std::vector<core::window::Window*>();

    // get all of the windows that are currently open
    HWND window_handle = GetWindow(GetDesktopWindow(), GW_CHILD);

    while (window_handle != NULL) {
        if (IsWindowVisible(window_handle) && GetWindowTextLength(window_handle) > 0) {
            windows.push_back(new core::window::Window(window_handle));
        }

        window_handle = GetNextWindow(window_handle, GW_HWNDNEXT);
    }

    return windows;
}

std::vector<core::window::Window*> WindowManager::GetRealWindows() {
    std::vector<core::window::Window*> windows = std::vector<core::window::Window*>();

    // get all windows that are open on the current desktop
    HWND window_handle = GetWindow(GetDesktopWindow(), GW_CHILD);

    while (window_handle != NULL) {
        if (IsWindowVisible(window_handle)) {
            windows.push_back(new core::window::Window(window_handle));
        }

        window_handle = GetNextWindow(window_handle, GW_HWNDNEXT);
    }

    return windows;
}

} // namespace window
} // namespace core
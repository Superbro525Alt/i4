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

void WindowManager::add_window(HWND window) {
    this->windows.push_back(window);
}

void WindowManager::remove_window(HWND window) {
    for (int i = 0; i < static_cast<int>(this->windows.size()); i++) {
        if (this->windows[i] == window) {
            this->windows.erase(this->windows.begin() + i);
            break;
        }
    }
}
}
}
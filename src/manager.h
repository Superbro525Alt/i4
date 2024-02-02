#pragma once

#include "config.h"
#include "window.h"

#include <Windows.h>
#include <vector>
#include <iostream>

namespace core {
namespace window {
class WindowManager {
    public:
    WindowManager(core::config::ConfigManager *config_manager);
    explicit WindowManager();
    ~WindowManager();
    
    void AddWindow(core::window::Window *window);
    void RemoveWindow(core::window::Window *window);

    std::vector<core::window::Window*> GetWindows();

    static std::vector<core::window::Window*> GetActiveWindows();
    static std::vector<core::window::Window*> GetRealWindows();

    private:
    std::vector<core::window::Window*> windows;
    core::config::ConfigManager *config_manager;
};
}
}
#include "main.h"

int main() {
    config_manager = new core::config::ConfigManager();
    window_manager = new core::window::WindowManager(config_manager);

    return 0;
}
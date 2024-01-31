#include "config.h"

#include <Windows.h>
#include <vector>

namespace core {
namespace window {
class WindowManager {
    public:
    WindowManager(core::config::ConfigManager *config_manager);
    explicit WindowManager();
    ~WindowManager();
    
    void add_window(HWND window);
    void remove_window(HWND window);

    private:
    std::vector<HWND> windows;
    core::config::ConfigManager *config_manager;
};
}
}
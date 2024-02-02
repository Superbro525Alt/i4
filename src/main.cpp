#include "main.h"

int main() {
    config_manager = new core::config::ConfigManager();
    workspace_manager = new core::workspace::WorkspaceManager();

    core::workspace::Workspace *workspace = new core::workspace::Workspace(0);

    workspace_manager->AddWorkspace(workspace);

    workspace->AddWindows(core::window::WindowManager::GetActiveWindows());

    core::input::KeybindManager *keybind_manager = new core::input::KeybindManager();

    keybind_manager->AddKeybind({"CTRL", "ALT", "T"}, []() {
        std::cout << "CTRL + ALT + T" << std::endl;
    });

    while (true) {
        keybind_manager->Tick();

        Sleep(100);
    }
    return 0;
}
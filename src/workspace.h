#pragma once

#include "window.h"
#include "manager.h"

namespace core {
namespace workspace {

class Workspace {
    public:
    Workspace(int id);
    ~Workspace();

    int get_id();

    void AddWindow(core::window::Window *window);
    void RemoveWindow(core::window::Window *window);

    void AddWindows(std::vector<core::window::Window*> windows);
    void RemoveWindows(std::vector<core::window::Window*> windows);

    std::vector<core::window::Window*> GetWindows();

    private:
    int id;
    core::window::WindowManager *window_manager;
    std::vector<std::vector<core::window::Window*>> alignment;
};

class WorkspaceManager {
    public:
    WorkspaceManager();
    ~WorkspaceManager();

    void AddWorkspace(core::workspace::Workspace *workspace);
    void RemoveWorkspace(core::workspace::Workspace *workspace);

    private:
    std::vector<core::workspace::Workspace*> workspaces;
};
}
}
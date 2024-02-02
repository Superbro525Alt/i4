#include "workspace.h"

namespace core {
namespace workspace {

Workspace::Workspace(int id) {
    this->id = id;
    this->window_manager = new core::window::WindowManager();
}

Workspace::~Workspace() {
    delete this->window_manager;
}

int Workspace::get_id() {
    return this->id;
}

void Workspace::AddWindow(core::window::Window *window) {
    this->window_manager->AddWindow(window);
}

void Workspace::RemoveWindow(core::window::Window *window) {
    this->window_manager->RemoveWindow(window);
}

void Workspace::AddWindows(std::vector<core::window::Window*> windows) {
    for (int i = 0; i < static_cast<int>(windows.size()); i++) {
        this->window_manager->AddWindow(windows[i]);
    }
}

void Workspace::RemoveWindows(std::vector<core::window::Window*> windows) {
    for (int i = 0; i < static_cast<int>(windows.size()); i++) {
        this->window_manager->RemoveWindow(windows[i]);
    }
}

std::vector<core::window::Window*> Workspace::GetWindows() {
    return this->window_manager->GetWindows();
}

WorkspaceManager::WorkspaceManager() {
    this->workspaces = std::vector<core::workspace::Workspace*>();
}

WorkspaceManager::~WorkspaceManager() {
    for (int i = 0; i < static_cast<int>(this->workspaces.size()); i++) {
        delete this->workspaces[i];
    }
}

void WorkspaceManager::AddWorkspace(core::workspace::Workspace *workspace) {
    this->workspaces.push_back(workspace);
}

void WorkspaceManager::RemoveWorkspace(core::workspace::Workspace *workspace) {
    for (int i = 0; i < static_cast<int>(this->workspaces.size()); i++) {
        if (this->workspaces[i]->get_id() == workspace->get_id()) {
            this->workspaces.erase(this->workspaces.begin() + i);
            break;
        }
    }
}
} // namespace workspace
} // namespace core
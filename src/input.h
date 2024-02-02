#pragma once

#include <vector>
#include <string>
#include <iostream>

#include "Windows.h"

namespace core {
namespace input {
std::vector<std::string> GetRawKeys();
std::vector<std::string> GetKeys();

bool Keybind(std::vector<int> keys);
bool Keybind(std::vector<std::string> keys);

class KeybindManager {
    public:
    KeybindManager();
    ~KeybindManager();

    void AddKeybind(std::vector<int> keys, void (*callback)());
    void AddKeybind(std::vector<std::string> keys, void (*callback)());

    void RemoveKeybind(std::vector<int> keys);
    void RemoveKeybind(std::vector<std::string> keys);

    void Tick();

    private:
    std::vector<std::vector<int>> keybinds;
    std::vector<void (*)()> callbacks;
};

namespace key {
std::string GetKeyName(int key);
int GetKeyName(std::string key);
}
}
}
#include "input.h"

namespace core {
namespace input {
std::vector<std::string> GetRawKeys() {
    std::vector<std::string> inputs;

    // get current key presses
    for (int i = 0; i < 256; i++) {
        if (GetAsyncKeyState(i) & 0x8000) {
            inputs.push_back(std::to_string(i));
        }
    }
    
    return inputs;
}

std::vector<std::string> GetKeys() {
    std::vector<std::string> inputs;

    // get if key is pressed
    for (int i = 0; i < 256; i++) {
        if (GetAsyncKeyState(i) & 0x8000) {
            // convert to string containing key name
            inputs.push_back(key::GetKeyName(i));
        }
    }


    return inputs;
}

bool Keybind(std::vector<int> keys) {
    // check if keybind is pressed
    for (int i = 0; i < static_cast<int>(keys.size()); i++) {
        if (!(GetAsyncKeyState(keys[i]) & 0x8000)) {
            return false;
        }
    }
    return true;
}

bool Keybind(std::vector<std::string> keys) {
    // check if keybind is pressed
    for (int i = 0; i < static_cast<int>(keys.size()); i++) {
        if (!(GetAsyncKeyState(key::GetKeyName(keys[i])) & 0x8000)) {
            return false;
        }
    }
    return true;
}

KeybindManager::KeybindManager() {
    // initialize keybind manager
    this->keybinds = std::vector<std::vector<int>>();
    this->callbacks = std::vector<void (*)()>();
}

KeybindManager::~KeybindManager() {
    // delete keybind manager
    this->keybinds.clear();
    this->callbacks.clear();
}

void KeybindManager::AddKeybind(std::vector<int> keys, void (*callback)()) {
    // add keybind to manager
    this->keybinds.push_back(keys);
    this->callbacks.push_back(callback);
}

void KeybindManager::AddKeybind(std::vector<std::string> keys, void (*callback)()) {
    // add keybind to manager
    std::vector<int> keycodes;
    for (int i = 0; i < static_cast<int>(keys.size()); i++) {
        keycodes.push_back(key::GetKeyName(keys[i]));
    }
    this->keybinds.push_back(keycodes);
    this->callbacks.push_back(callback);
}

void KeybindManager::RemoveKeybind(std::vector<int> keys) {
    // remove keybind from manager
    for (int i = 0; i < static_cast<int>(this->keybinds.size()); i++) {
        if (this->keybinds[i] == keys) {
            this->keybinds.erase(this->keybinds.begin() + i);
            this->callbacks.erase(this->callbacks.begin() + i);
            break;
        }
    }
}

void KeybindManager::RemoveKeybind(std::vector<std::string> keys) {
    // remove keybind from manager
    std::vector<int> keycodes;
    for (int i = 0; i < static_cast<int>(keys.size()); i++) {
        keycodes.push_back(key::GetKeyName(keys[i]));
    }
    for (int i = 0; i < static_cast<int>(this->keybinds.size()); i++) {
        if (this->keybinds[i] == keycodes) {
            this->keybinds.erase(this->keybinds.begin() + i);
            this->callbacks.erase(this->callbacks.begin() + i);
            break;
        }
    }
}

void KeybindManager::Tick() {
    // update keybinds
    for (int i = 0; i < static_cast<int>(this->keybinds.size()); i++) {
        if (Keybind(this->keybinds[i])) {
            this->callbacks[i]();
        }
    }
}

namespace key {
std::string GetKeyName(int key) {
    // get key name from key code

    switch (key) {
        case 0x41:
            return "A";
        case 0x42:
            return "B";
        case 0x43:
            return "C";
        case 0x44:
            return "D";
        case 0x45:
            return "E";
        case 0x46:
            return "F";
        case 0x47:
            return "G";
        case 0x48:
            return "H";
        case 0x49:
            return "I";
        case 0x4A:
            return "J";
        case 0x4B:
            return "K";
        case 0x4C:
            return "L";
        case 0x4D:
            return "M";
        case 0x4E:
            return "N";
        case 0x4F:
            return "O";
        case 0x50:
            return "P";
        case 0x51:
            return "Q";
        case 0x52:
            return "R";
        case 0x53:
            return "S";
        case 0x54:
            return "T";
        case 0x55:
            return "U";
        case 0x56:
            return "V";
        case 0x57:
            return "W";
        case 0x58:
            return "X";
        case 0x59:
            return "Y";
        case 0x5A:
            return "Z";
        case 0x30:
            return "0";
        case 0x31:
            return "1";
        case 0x32:
            return "2";
        case 0x33:
            return "3";
        case 0x34:
            return "4";
        case 0x35:
            return "5";
        case 0x36:
            return "6";
        case 0x37:
            return "7";
        case 0x38:
            return "8";
        case 0x39:
            return "9";
        case VK_LBUTTON:
            return "MOUSE_LEFT";
        case VK_RBUTTON:
            return "MOUSE_RIGHT";
        case VK_MBUTTON:
            return "MOUSE_MIDDLE";
        case VK_XBUTTON1:
            return "MOUSE_X1";
        case VK_XBUTTON2:
            return "MOUSE_X2";
        case VK_BACK:
            return "BACKSPACE";
        case VK_TAB:
            return "TAB";
        case VK_RETURN:
            return "ENTER";
        case VK_SHIFT:
            return "SHIFT";
        case VK_CONTROL:
            return "CTRL";
        case VK_MENU:
            return "ALT";
        case VK_PAUSE:
            return "PAUSE";
        case VK_CAPITAL:
            return "CAPS_LOCK";
        case VK_ESCAPE:
            return "ESC";
        case VK_SPACE:
            return "SPACE";
        case VK_PRIOR:
            return "PAGE_UP";
        case VK_NEXT:
            return "PAGE_DOWN";
        case VK_END:
            return "END";
        case VK_HOME:
            return "HOME";
        case VK_LEFT:
            return "LEFT";
        case VK_UP:
            return "UP";
        case VK_RIGHT:
            return "RIGHT";
        case VK_DOWN:
            return "DOWN";
        case VK_SELECT:
            return "SELECT";
        case VK_PRINT:
            return "PRINT";
        case VK_EXECUTE:    
            return "EXECUTE";
        case VK_SNAPSHOT:
            return "PRINT_SCREEN";
        case VK_INSERT:
            return "INSERT";
        case VK_DELETE:
            return "DELETE";
        case VK_HELP:
            return "HELP";
        case VK_LWIN:
            return "LEFT_WIN";
        case VK_RWIN:
            return "RIGHT_WIN";
        case VK_APPS:
            return "APPS";
        case VK_SLEEP:
            return "SLEEP";
        case VK_NUMPAD0:
            return "NUMPAD_0";
        case VK_NUMPAD1:    
            return "NUMPAD_1";
        case VK_NUMPAD2:
            return "NUMPAD_2";
        case VK_NUMPAD3:
            return "NUMPAD_3";
        case VK_NUMPAD4:
            return "NUMPAD_4";
        case VK_NUMPAD5:
            return "NUMPAD_5";
        case VK_NUMPAD6:
            return "NUMPAD_6";
        case VK_NUMPAD7:
            return "NUMPAD_7";
        case VK_NUMPAD8:
            return "NUMPAD_8";
        case VK_NUMPAD9:
            return "NUMPAD_9";
        case VK_MULTIPLY:
            return "NUMPAD_MULTIPLY";

    }
    return "UNKNOWN";
}

int GetKeyName(std::string key) {
    // get key code from key name

    if (key == "A") {
        return 0x41;
    } else if (key == "B") {
        return 0x42;
    } else if (key == "C") {
        return 0x43;
    } else if (key == "D") {
        return 0x44;
    } else if (key == "E") {
        return 0x45;
    } else if (key == "F") {
        return 0x46;
    } else if (key == "G") {
        return 0x47;
    } else if (key == "H") {
        return 0x48;
    } else if (key == "I") {
        return 0x49;
    } else if (key == "J") {
        return 0x4A;
    } else if (key == "K") {
        return 0x4B;
    } else if (key == "L") {
        return 0x4C;
    } else if (key == "M") {
        return 0x4D;
    } else if (key == "N") {
        return 0x4E;
    } else if (key == "O") {
        return 0x4F;
    } else if (key == "P") {
        return 0x50;
    } else if (key == "Q") {
        return 0x51;
    } else if (key == "R") {
        return 0x52;
    } else if (key == "S") {
        return 0x53;
    } else if (key == "T") {
        return 0x54;
    } else if (key == "U") {
        return 0x55;
    } else if (key == "V") {
        return 0x56;
    } else if (key == "W") {
        return 0x57;
    } else if (key == "X") {
        return 0x58;
    } else if (key == "Y") {
        return 0x59;
    } else if (key == "Z") {
        return 0x5A;
    } else if (key == "0") {
        return 0x30;
    } else if (key == "1") {
        return 0x31;
    } else if (key == "2") {
        return 0x32;
    } else if (key == "3") {
        return 0x33;
    } else if (key == "4") {
        return 0x34;
    } else if (key == "5") {
        return 0x35;
    } else if (key == "6") {
        return 0x36;
    } else if (key == "7") {
        return 0x37;
    } else if (key == "8") {
        return 0x38;
    } else if (key == "9") {
        return 0x39;
    } else if (key == "MOUSE_LEFT") {
        return VK_LBUTTON;
    } else if (key == "MOUSE_RIGHT") {
        return VK_RBUTTON;
    } else if (key == "MOUSE_MIDDLE") {
        return VK_MBUTTON;
    } else if (key == "MOUSE_X1") {
        return VK_XBUTTON1;
    } else if (key == "MOUSE_X2") {
        return VK_XBUTTON2;
    } else if (key == "BACKSPACE") {
        return VK_BACK;
    } else if (key == "TAB") {
        return VK_TAB;
    } else if (key == "ENTER") {
        return VK_RETURN;
    } else if (key == "SHIFT") {
        return VK_SHIFT;
    } else if (key == "CTRL") {
        return VK_CONTROL;
    } else if (key == "ALT") {
        return VK_MENU;
    } else if (key == "PAUSE") {
        return VK_PAUSE;
    } else if (key == "CAPS_LOCK") {
        return VK_CAPITAL;
    } else if (key == "ESC") {
        return VK_ESCAPE;
    } else if (key == "SPACE") {
        return VK_SPACE;
    } else if (key == "PAGE_UP") {
        return VK_PRIOR;
    } else if (key == "PAGE_DOWN") {
        return VK_NEXT;
    } else if (key == "END") {
        return VK_END;
    } else if (key == "HOME") {
        return VK_HOME;
    } else if (key == "LEFT") {
        return VK_LEFT;
    } else if (key == "UP") {
        return VK_UP;
    } else if (key == "RIGHT") {
        return VK_RIGHT;
    } else if (key == "DOWN") {
        return VK_DOWN;
    } else if (key == "SELECT") {
        return VK_SELECT;
    } else if (key == "PRINT") {
        return VK_PRINT;
    } else if (key == "EXECUTE") {
        return VK_EXECUTE;
    } else if (key == "PRINT_SCREEN") {
        return VK_SNAPSHOT;
    } else if (key == "INSERT") {
        return VK_INSERT;
    } else if (key == "DELETE") {
        return VK_DELETE;
    } else if (key == "HELP") {
        return VK_HELP;
    } else if (key == "LEFT_WIN") {
        return VK_LWIN;
    } else if (key == "RIGHT_WIN") {
        return VK_RWIN;
    } else if (key == "APPS") {
        return VK_APPS;
    } else if (key == "SLEEP") {
        return VK_SLEEP;
    } else if (key == "NUMPAD_0") {
        return VK_NUMPAD0;
    } else if (key == "NUMPAD_1") {
        return VK_NUMPAD1;
    } else if (key == "NUMPAD_2") {
        return VK_NUMPAD2;
    } else if (key == "NUMPAD_3") {
        return VK_NUMPAD3;
    } else if (key == "NUMPAD_4") {
        return VK_NUMPAD4;
    } else if (key == "NUMPAD_5") {
        return VK_NUMPAD5;
    } else if (key == "NUMPAD_6") {
        return VK_NUMPAD6;
    } else if (key == "NUMPAD_7") {
        return VK_NUMPAD7;
    } else if (key == "NUMPAD_8") {
        return VK_NUMPAD8;
    } else if (key == "NUMPAD_9") {
        return VK_NUMPAD9;
    } else if (key == "NUMPAD_MULTIPLY") {
        return VK_MULTIPLY;
    }

    return -1;
}
}
} // namespace input
} // namespace core
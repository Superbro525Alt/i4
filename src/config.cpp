#include "config.h"

namespace core {
namespace config {
template<typename T>
Config<T>::Config(T value) {
    this->value = value;
}

template<typename T>
Config<T>::~Config() {
}

template<typename T>
T Config<T>::get() {
    return this->value;
}

template<typename T>
void Config<T>::set(T value) {
    this->value = value;
}

ConfigManager::ConfigManager() {
    this->int_configs = std::map<std::string, Config<int> *>();
    this->float_configs = std::map<std::string, Config<float> *>();
    this->string_configs = std::map<std::string, Config<std::string> *>();
}

ConfigManager::~ConfigManager() {
    for (auto it = this->int_configs.begin(); it != this->int_configs.end(); ++it) {
        delete it->second;
    }
    for (auto it = this->float_configs.begin(); it != this->float_configs.end(); ++it) {
        delete it->second;
    }
    for (auto it = this->string_configs.begin(); it != this->string_configs.end(); ++it) {
        delete it->second;
    }
}

Config<int> *ConfigManager::get_int(std::string key) {
    if (this->int_configs.find(key) == this->int_configs.end()) {
        this->int_configs[key] = new Config<int>(0);
    }
    return this->int_configs[key];
}

Config<float> *ConfigManager::get_float(std::string key) {
    if (this->float_configs.find(key) == this->float_configs.end()) {
        this->float_configs[key] = new Config<float>(0.0f);
    }
    return this->float_configs[key];
}

Config<std::string> *ConfigManager::get_string(std::string key) {
    if (this->string_configs.find(key) == this->string_configs.end()) {
        this->string_configs[key] = new Config<std::string>("");
    }
    return this->string_configs[key];
}

GapConfig::GapConfig(int value) : Config<int>(value) {
}

GapConfig::~GapConfig() {
}
} // namespace config
} // namespace core
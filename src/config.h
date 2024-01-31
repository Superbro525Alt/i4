#pragma once

#include <string>
#include <map>

namespace core {
namespace config { 
template<typename T>
class Config {
    public:
        Config(T value);
        ~Config();
        T get();
        void set(T value);
    private:
        T value;
};

class ConfigManager {
    public:
        ConfigManager();
        ~ConfigManager();
        Config<int> *get_int(std::string key);
        Config<float> *get_float(std::string key);
        Config<std::string> *get_string(std::string key);
    private:
        std::map<std::string, Config<int> *> int_configs;
        std::map<std::string, Config<float> *> float_configs;
        std::map<std::string, Config<std::string> *> string_configs;
};

class GapConfig : public Config<int> {
    public:
        GapConfig(int value);
        ~GapConfig();
};
} // namespace config
} // namespace core
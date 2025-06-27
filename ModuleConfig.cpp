#include "ModuleConfig.h"

ModuleConfig::ModuleConfig()
{
    this->module_name = "";
    this->timescale = "";
}

ModuleConfig::ModuleConfig(
    const std::string& arg_module_name,
    const std::string& arg_timescale,
    const ClockConfig& arg_clock,
    const ResetConfig& arg_reset,
    const IOPort& arg_io_port,
    const std::vector<IOPattern>& arg_io_patterns
) {
    this->module_name = arg_module_name;
    this->timescale = arg_timescale;
    this->clock = arg_clock;
    this->reset = arg_reset;
    this->io_port = arg_io_port;
    this->io_patterns = arg_io_patterns;
}

void ModuleConfig::setModuleName(const std::string& name)
{
    this->module_name = name;
}

const std::string& ModuleConfig::getModuleName() const
{
    return this->module_name;
}

void ModuleConfig::setTimescale(const std::string& ts)
{
    this->timescale = ts;
}

const std::string& ModuleConfig::getTimescale() const
{
    return this->timescale;
}

void ModuleConfig::setClockConfig(const ClockConfig& clk)
{
    this->clock = clk;
}

const ClockConfig& ModuleConfig::getClockConfig() const
{
    return this->clock;
}

void ModuleConfig::setResetConfig(const ResetConfig& rst)
{
    this->reset = rst;
}

const ResetConfig& ModuleConfig::getResetConfig() const
{
    return this->reset;
}

void ModuleConfig::setIOPort(const IOPort& io)
{
    this->io_port = io;
}

const IOPort& ModuleConfig::getIOPort() const
{
    return this->io_port;
}

void ModuleConfig::addIOPattern(const IOPattern& pattern)
{
    this->io_patterns.push_back(pattern);
}

void ModuleConfig::clearIOPatterns()
{
    this->io_patterns.clear();
}

const std::vector<IOPattern>& ModuleConfig::getIOPatterns() const
{
    return this->io_patterns;
}

Json::Value* ModuleConfig::dump2JSON(void)
{
    Json::Value* result_ptr = new Json::Value();

    (*result_ptr)["module"] = this->module_name;
    (*result_ptr)["timescale"] = this->timescale;

    // clock
    Json::Value* clk_json = this->clock.dump2JSON();
    if (clk_json)
        (*result_ptr)["clock"] = *clk_json;
    else
        (*result_ptr)["clock"] = Json::nullValue;
    delete clk_json;

    // reset
    Json::Value* rst_json = this->reset.dump2JSON();
    if (rst_json)
        (*result_ptr)["reset"] = *rst_json;
    else
        (*result_ptr)["reset"] = Json::nullValue;
    delete rst_json;

    // IO ports
    Json::Value* io_json = this->io_port.dump2JSON();
    if (io_json)
        (*result_ptr)["IO ports"] = *io_json;
    else
        (*result_ptr)["IO ports"] = Json::nullValue;
    delete io_json;

    // IO patterns
    Json::Value io_patterns_array(Json::arrayValue);
    for (auto& pattern : this->io_patterns) {
        Json::Value* pattern_json = pattern.dump2JSON();
        if (pattern_json) {
            io_patterns_array.append(*pattern_json);
            delete pattern_json;
        }
    }
    (*result_ptr)["IO patterns"] = io_patterns_array;

    return result_ptr;
}

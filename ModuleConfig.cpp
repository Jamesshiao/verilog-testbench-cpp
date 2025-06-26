#include "ModuleConfig.h"

ModuleConfig::ModuleConfig()
{
    this->module = "unnamed";
    this->timescale = "1ns/1ps";
    this->clock = ClockConfig();
    this->reset = ResetConfig();
    this->io_port = IOPort();
    this->patterns.clear();
}

ModuleConfig::ModuleConfig(std::string arg_module,
                           std::string arg_timescale,
                           ClockConfig clk,
                           ResetConfig rst,
                           IOPort port,
                           std::vector<IOPattern> pats)
{
    this->module = arg_module;
    this->timescale = arg_timescale;
    this->clock = clk;
    this->reset = rst;
    this->io_port = port;
    this->patterns = pats;
}

Json::Value* ModuleConfig::dump2JSON(void)
{
    Json::Value* result_ptr = new Json::Value();

    (*result_ptr)["module"] = this->module;
    (*result_ptr)["timescale"] = this->timescale;

    Json::Value* clk_json = this->clock.dump2JSON();
    (*result_ptr)["clock"] = *clk_json;
    delete clk_json;

    Json::Value* rst_json = this->reset.dump2JSON();
    (*result_ptr)["reset"] = *rst_json;
    delete rst_json;

    Json::Value* port_json = this->io_port.dump2JSON();
    (*result_ptr)["IO ports"] = *port_json;
    delete port_json;

    Json::Value pattern_array(Json::arrayValue);
    for (auto& p : this->patterns)
    {
        Json::Value* p_json = p.dump2JSON();
        pattern_array.append(*p_json);
        delete p_json;
    }
    (*result_ptr)["IO patterns"] = pattern_array;

    return result_ptr;
}

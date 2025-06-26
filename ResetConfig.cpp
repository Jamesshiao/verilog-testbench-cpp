#include "ResetConfig.h"

ResetConfig::ResetConfig()
{
    this->signal.name = "rst";
    this->type = "synchronous";
    this->active_high = true;
}

ResetConfig::ResetConfig(Signal arg_signal, std::string arg_type, bool arg_active_high)
{
    this->signal = arg_signal;
    this->type = arg_type;
    this->active_high = arg_active_high;
}

Json::Value* ResetConfig::dump2JSON(void)
{
    Json::Value* result_ptr = new Json::Value();
    (*result_ptr)["name"] = this->signal.name;
    (*result_ptr)["type"] = this->type;
    (*result_ptr)["active_high"] = this->active_high;
    return result_ptr;
}

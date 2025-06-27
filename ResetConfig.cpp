#include "ResetConfig.h"

ResetConfig::ResetConfig()
{
    this->en = false;
    this->type = "";
    this->active_high = false;
}

ResetConfig::ResetConfig(Signal arg_signal, std::string arg_type, bool arg_active_high)
{
    this->signal = arg_signal;
    this->type = arg_type;
    this->active_high = arg_active_high;
    this->en = true;
}

void ResetConfig::SetType(const std::string& arg_type)
{
    this->type = arg_type;
}

std::string ResetConfig::GetType() const
{
    return this->type;
}

void ResetConfig::SetActiveHigh(bool arg_active_high)
{
    this->active_high = arg_active_high;
}

bool ResetConfig::IsActiveHigh() const
{
    return this->active_high;
}

Json::Value* ResetConfig::dump2JSON(void)
{
    Json::Value* result_ptr = new Json::Value();
    if (!this->en) return result_ptr;
    (*result_ptr)["name"] = this->signal.name;
    (*result_ptr)["type"] = this->type;
    (*result_ptr)["active_high"] = this->active_high;
    return result_ptr;
}

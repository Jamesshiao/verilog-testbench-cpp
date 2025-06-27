#include "Config.h"

Config::Config()
{
    this->en = false;
}

Config::Config(Signal arg_signal)
{
    this->signal = arg_signal;
    this->en = true;
}

void Config::Set(Signal s)
{
    this->signal = s;
    this->en = true;
}

void Config::Disable()
{
    this->en = false;
}

bool Config::IsEnabled() const
{
    return this->en;
}

Signal Config::GetSignal() const
{
    return this->signal;
}

Json::Value* Config::dump2JSON(void)
{
    Json::Value* result_ptr = new Json::Value();
    if (!this->en) return result_ptr;
    (*result_ptr)["signal"] = this->signal.name;
    return result_ptr;
}

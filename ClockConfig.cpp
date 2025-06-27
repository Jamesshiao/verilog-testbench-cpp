#include "ClockConfig.h"

ClockConfig::ClockConfig()
{
    this->en = false;
    this->period = 0;
    this->unit = "s";
}

ClockConfig::ClockConfig(Signal arg_signal, int arg_period, std::string arg_unit)
{
    this->signal = arg_signal;
    this->period = arg_period;
    this->unit = arg_unit;
    this->en = true;
}

void ClockConfig::SetPeriod(int arg_period)
{
    this->period = arg_period;
}

int ClockConfig::GetPeriod() const
{
    return this->period;
}

void ClockConfig::SetUnit(const std::string& arg_unit)
{
    this->unit = arg_unit;
}

std::string ClockConfig::GetUnit() const
{
    return this->unit;
}

Json::Value* ClockConfig::dump2JSON(void)
{
    Json::Value* result_ptr = new Json::Value();
    if (!this->en) return result_ptr;
    (*result_ptr)["signal"] = this->signal.name;
    (*result_ptr)["period"] = this->period;
    (*result_ptr)["unit"] = this->unit;
    return result_ptr;
}

#include "ClockConfig.h"

ClockConfig::ClockConfig()
{
  this->signal.name = "clk";
  this->period = 0;
  this->unit = "s";
}

ClockConfig::ClockConfig(Signal arg_signal, int arg_period, std::string arg_unit)
{
  this->signal = arg_signal;
  this->period = arg_period;
  this->unit = arg_unit;
}

Json::Value *ClockConfig::dump2JSON(void)
{
  Json::Value *result_ptr = new Json::Value();
  (*result_ptr)["signal"] = this->signal.name;
  (*result_ptr)["period"] = this->period;
  (*result_ptr)["unit"] = this->unit;
  return result_ptr;
}

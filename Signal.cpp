
#include "Signal.h"

Signal::Signal()
{
  this->name = "None";
}

Signal::Signal(std::string arg_name)
{
  this->name = arg_name;
}

bool
Signal::operator<(const Signal& another) const
{
  return this->name < another.name;
}


Json::Value *
Signal::dump2JSON
(void)
{
  Json::Value * result_ptr = new Json::Value();
  (*result_ptr)["signal"]  = this->name;
  return result_ptr;
}


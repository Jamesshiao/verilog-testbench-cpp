
#include "Time.h"

Time::Time()
{
  this->time_sec = 0;
}

Time::Time(int arg_time_sec)
{
  this->time_sec = arg_time_sec;
}

const int 
Time::getTime()
{
  return this->time_sec;
}

Json::Value *
Time::dump2JSON
(void)
{
  Json::Value * result_ptr = new Json::Value();
  (*result_ptr)["time"]  = this->time_sec;
  return result_ptr;
}


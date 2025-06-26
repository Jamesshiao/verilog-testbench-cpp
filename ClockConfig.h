#ifndef _CLOCK_CONFIG_H_
#define _CLOCK_CONFIG_H_

#include "Signal.h"
#include <jsoncpp/json/json.h>

class ClockConfig
{
public:
  Signal signal;
  int period;
  std::string unit;

  ClockConfig();
  ClockConfig(Signal, int, std::string);

  Json::Value *dump2JSON(void);
};

#endif /* _CLOCK_CONFIG_H_ */

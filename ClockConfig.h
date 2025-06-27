#ifndef _CLOCKCONFIG_H_
#define _CLOCKCONFIG_H_

#include <string>
#include "Config.h"
#include <jsoncpp/json/json.h>

class ClockConfig : public Config {
public:
    int period;
    std::string unit;

    ClockConfig();
    ClockConfig(Signal, int, std::string);

    void SetPeriod(int);
    int GetPeriod() const;

    void SetUnit(const std::string&);
    std::string GetUnit() const;

    Json::Value* dump2JSON(void);
};

#endif

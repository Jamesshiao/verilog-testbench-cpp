#ifndef MODULECONFIG_H
#define MODULECONFIG_H

#include <string>
#include <vector>
#include <jsoncpp/json/json.h>

#include "ClockConfig.h"
#include "ResetConfig.h"
#include "IOPort.h"
#include "IOPattern.h"

class ModuleConfig {
public:
    std::string module;
    std::string timescale;
    ClockConfig clock;
    ResetConfig reset;
    IOPort io_port;
    std::vector<IOPattern> patterns;

    ModuleConfig();
    ModuleConfig(std::string,
                 std::string,
                 ClockConfig,
                 ResetConfig,
                 IOPort,
                 std::vector<IOPattern>);

    Json::Value* dump2JSON(void);
};

#endif

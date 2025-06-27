#ifndef _MODULECONFIG_H_
#define _MODULECONFIG_H_

#include <string>
#include <vector>
#include <jsoncpp/json/json.h>

#include "ClockConfig.h"
#include "ResetConfig.h"
#include "IOPort.h"
#include "IOPattern.h"

class ModuleConfig {
public:
    std::string module_name;
    std::string timescale;

    ClockConfig clock;
    ResetConfig reset;
    IOPort io_port;
    std::vector<IOPattern> io_patterns;

    ModuleConfig();

    ModuleConfig(
    const std::string&,
    const std::string&,
    const ClockConfig&,
    const ResetConfig&,
    const IOPort&,
    const std::vector<IOPattern>&);

    void setModuleName(const std::string&);
    const std::string& getModuleName() const;

    void setTimescale(const std::string&);
    const std::string& getTimescale() const;

    void setClockConfig(const ClockConfig&);
    const ClockConfig& getClockConfig() const;

    void setResetConfig(const ResetConfig&);
    const ResetConfig& getResetConfig() const;

    void setIOPort(const IOPort&);
    const IOPort& getIOPort() const;

    void addIOPattern(const IOPattern&);
    void clearIOPatterns();
    const std::vector<IOPattern>& getIOPatterns() const;

    Json::Value* dump2JSON(void);
};

#endif

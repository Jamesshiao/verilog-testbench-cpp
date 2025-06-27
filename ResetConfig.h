#ifndef _RESETCONFIG_H_
#define _RESETCONFIG_H_

#include <string>
#include "Config.h"
#include <jsoncpp/json/json.h>

class ResetConfig : public Config {
public:
    std::string type;
    bool active_high;

    ResetConfig();
    ResetConfig(Signal arg_signal, std::string arg_type, bool arg_active_high);

    void SetType(const std::string& arg_type);
    std::string GetType() const;

    void SetActiveHigh(bool arg_active_high);
    bool IsActiveHigh() const;

    Json::Value* dump2JSON(void);
};

#endif

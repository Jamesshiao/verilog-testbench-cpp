#ifndef RESETCONFIG_H
#define RESETCONFIG_H

#include <string>
#include "Signal.h"
#include <jsoncpp/json/json.h>

class ResetConfig {
public:
    Signal signal;          
    std::string type;       
    bool active_high;      

    ResetConfig();
    ResetConfig(Signal, std::string, bool);

    Json::Value* dump2JSON(void);
};

#endif

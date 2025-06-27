#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <string>
#include "Signal.h"
#include <jsoncpp/json/json.h>

class Config {
public:
    Signal signal;
    bool en;

    Config();
    Config(Signal);

    void Set(Signal);
    void Disable();
    bool IsEnabled() const;

    Signal GetSignal() const;

    Json::Value* dump2JSON(void);    
};

#endif

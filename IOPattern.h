#ifndef IOPATTERN_H
#define IOPATTERN_H

#include <map>
#include <string>
#include <jsoncpp/json/json.h>
#include "Time.h"
#include "Signal.h"

class IOPattern {
public:
    Time time;
    std::map<Signal, std::string> inputs;
    std::map<Signal, std::string> expected_outputs;

    IOPattern(); 
    IOPattern(Time t,
              std::map<Signal, std::string> in,
              std::map<Signal, std::string> out = std::map<Signal, std::string>());

    Json::Value* dump2JSON(void);
};

#endif

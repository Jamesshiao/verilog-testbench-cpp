#ifndef IOPORT_H
#define IOPORT_H

#include <vector>
#include <string>
#include <jsoncpp/json/json.h>

class IOPort {
public:
    std::vector<std::string> inputs;
    std::vector<std::string> outputs;

    IOPort();
    IOPort(std::vector<std::string>, std::vector<std::string>);

    Json::Value* dump2JSON(void);
};

#endif

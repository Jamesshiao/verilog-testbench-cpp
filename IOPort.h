#ifndef _IOPORT_H_
#define _IOPORT_H_

#include <string>
#include <vector>
#include <jsoncpp/json/json.h>

class IOPort {
public:
    std::vector<std::string> inputs;
    std::vector<std::string> outputs;

    IOPort();
    IOPort(const std::vector<std::string>& inputs, const std::vector<std::string>& outputs);

    void addInput(const std::string&);
    void addOutput(const std::string&);

    void removeInput(const std::string&);
    void removeOutput(const std::string&);

    void clearInputs();
    void clearOutputs();

    const std::vector<std::string>& getInputs() const;
    const std::vector<std::string>& getOutputs() const;

    void setInputs(const std::vector<std::string>&);
    void setOutputs(const std::vector<std::string>&);

    Json::Value* dump2JSON(void);
};

#endif

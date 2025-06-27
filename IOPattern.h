#ifndef _IOPATTERN_H_
#define _IOPATTERN_H_

#include <map>
#include <string>
#include <jsoncpp/json/json.h>
#include "Signal.h"
#include "Time.h"

class IOPattern {
private:
    Time time;
    std::map<Signal, std::string> inputs;
    std::map<Signal, std::string> expected_outputs;

public:
    IOPattern();
    IOPattern(Time, std::map<Signal, std::string>);
    IOPattern(Time, std::map<Signal, std::string>, std::map<Signal, std::string>);

    void setTime(const Time&);
    Time getTime() const;

    void setInputs(const std::map<Signal, std::string>&);
    const std::map<Signal, std::string>& getInputs() const;
    void addInput(const Signal&, const std::string&);
    void removeInput(const Signal&);
    void clearInputs();

    void setExpectedOutputs(const std::map<Signal, std::string>&);
    const std::map<Signal, std::string>& getExpectedOutputs() const;
    void addExpectedOutput(const Signal&, const std::string&);
    void removeExpectedOutput(const Signal&);
    void clearExpectedOutputs();

    Json::Value* dump2JSON(void);
};

#endif

#include "IOPattern.h"

IOPattern::IOPattern()
{
}

IOPattern::IOPattern(Time arg_time,
                     std::map<Signal, std::string> in,
                     std::map<Signal, std::string> out)
{
    this->time = arg_time;
    this->inputs = in;
    this->expected_outputs = out;
}

void IOPattern::setTime(const Time& arg_time)
{
    this->time = arg_time;
}

Time IOPattern::getTime() const
{
    return this->time;
}

void IOPattern::setInputs(const std::map<Signal, std::string>& in)
{
    this->inputs = in;
}

const std::map<Signal, std::string>& IOPattern::getInputs() const
{
    return this->inputs;
}

void IOPattern::addInput(const Signal& signal, const std::string& value)
{
    this->inputs[signal] = value;
}

void IOPattern::removeInput(const Signal& signal)
{
    this->inputs.erase(signal);
}

void IOPattern::clearInputs()
{
    this->inputs.clear();
}

void IOPattern::setExpectedOutputs(const std::map<Signal, std::string>& out)
{
    this->expected_outputs = out;
}

const std::map<Signal, std::string>& IOPattern::getExpectedOutputs() const
{
    return this->expected_outputs;
}

void IOPattern::addExpectedOutput(const Signal& signal, const std::string& value)
{
    this->expected_outputs[signal] = value;
}

void IOPattern::removeExpectedOutput(const Signal& signal)
{
    this->expected_outputs.erase(signal);
}

void IOPattern::clearExpectedOutputs()
{
    this->expected_outputs.clear();
}

Json::Value* IOPattern::dump2JSON(void)
{
    Json::Value* result_ptr = this->time.dump2JSON();

    if (!inputs.empty())
    {
        Json::Value inputs_obj(Json::objectValue);
        for (auto kv : this->inputs)
        {
            inputs_obj[kv.first.name] = kv.second;
        }
        (*result_ptr)["inputs"] = inputs_obj;
    }

    if (!expected_outputs.empty())
    {
        Json::Value outputs_obj(Json::objectValue);
        for (auto kv : this->expected_outputs)
        {
            outputs_obj[kv.first.name] = kv.second;
        }
        (*result_ptr)["expected_outputs"] = outputs_obj;
    }

    return result_ptr;
}

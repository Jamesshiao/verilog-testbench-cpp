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

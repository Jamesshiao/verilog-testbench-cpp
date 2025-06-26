#include "IOPort.h"

IOPort::IOPort()
{
}

IOPort::IOPort(std::vector<std::string> arg_inputs, std::vector<std::string> arg_outputs)
{
    inputs = arg_inputs;
    outputs = arg_outputs;
}

Json::Value* IOPort::dump2JSON(void)
{
    Json::Value* result_ptr = new Json::Value();

    Json::Value inputs_array(Json::arrayValue);
    for (const auto& in : inputs) {
        inputs_array.append(in);
    }
    (*result_ptr)["inputs"] = inputs_array;

    Json::Value outputs_array(Json::arrayValue);
    for (const auto& out : outputs) {
        outputs_array.append(out);
    }
    (*result_ptr)["outputs"] = outputs_array;

    return result_ptr;
}

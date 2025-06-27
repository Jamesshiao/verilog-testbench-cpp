#include "IOPort.h"
#include <algorithm>

IOPort::IOPort() {}

IOPort::IOPort(const std::vector<std::string>& arg_inputs, const std::vector<std::string>& arg_outputs) {
    inputs = arg_inputs;
    outputs = arg_outputs;
}

void IOPort::addInput(const std::string& s) {
    inputs.push_back(s);
}

void IOPort::addOutput(const std::string& s) {
    outputs.push_back(s);
}

void IOPort::removeInput(const std::string& s) {
    inputs.erase(std::remove(inputs.begin(), inputs.end(), s), inputs.end());
}

void IOPort::removeOutput(const std::string& s) {
    outputs.erase(std::remove(outputs.begin(), outputs.end(), s), outputs.end());
}

void IOPort::clearInputs() {
    inputs.clear();
}

void IOPort::clearOutputs() {
    outputs.clear();
}

const std::vector<std::string>& IOPort::getInputs() const {
    return inputs;
}

const std::vector<std::string>& IOPort::getOutputs() const {
    return outputs;
}

void IOPort::setInputs(const std::vector<std::string>& in) {
    inputs = in;
}

void IOPort::setOutputs(const std::vector<std::string>& out) {
    outputs = out;
}

Json::Value* IOPort::dump2JSON(void) {
    Json::Value* result = new Json::Value();
    Json::Value inputs_array(Json::arrayValue);
    for (auto& in : inputs) {
        inputs_array.append(in);
    }
    Json::Value outputs_array(Json::arrayValue);
    for (auto& out : outputs) {
        outputs_array.append(out);
    }
    (*result)["inputs"] = inputs_array;
    (*result)["outputs"] = outputs_array;
    return result;
}

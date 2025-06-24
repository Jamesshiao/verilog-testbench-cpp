#include "VerilogTestBench.h"
#include <sstream>

// ---------- ClockConfig 實作 ----------

ClockConfig::ClockConfig() : name("clk"), period(10), unit("ns") {}

ClockConfig::ClockConfig(const std::string &n, int p, const std::string &u)
    : name(n), period(p), unit(u) {}

// ---------- ResetConfig 實作 ----------

ResetConfig::ResetConfig() : name("rst"), type("synchronous"), active_high(true) {}

ResetConfig::ResetConfig(const std::string &n, const std::string &t, bool a)
    : name(n), type(t), active_high(a) {}

// ---------- IOPattern 實作 ----------

IOPattern::IOPattern() : time(0) {}

IOPattern::IOPattern(int t, const std::map<std::string, std::string> &in,
                     const std::map<std::string, std::string> &out)
    : time(t), inputs(in), expected_outputs(out) {}

// ---------- VerilogTestBench 實作 ----------

VerilogTestBench::VerilogTestBench() {}

VerilogTestBench::~VerilogTestBench() {}

void VerilogTestBench::setModule(const std::string &m)
{
    module = m;
}

void VerilogTestBench::setTimescale(const std::string &ts)
{
    timescale = ts;
}

void VerilogTestBench::setClock(const ClockConfig &clk)
{
    clock = clk;
}

void VerilogTestBench::setReset(const ResetConfig &rst)
{
    reset = rst;
}

void VerilogTestBench::setInputs(const std::vector<std::string> &inputs)
{
    input_ports = inputs;
}

void VerilogTestBench::setOutputs(const std::vector<std::string> &outputs)
{
    output_ports = outputs;
}

void VerilogTestBench::addPattern(const IOPattern &pattern)
{
    patterns.push_back(pattern);
}

// ---------- Helper functions ----------

static std::string quote(const std::string &s)
{
    return "\"" + s + "\"";
}

static std::string mapToJSON(const std::map<std::string, std::string> &m)
{
    std::ostringstream oss;
    oss << "{";
    bool first = true;
    for (std::map<std::string, std::string>::const_iterator it = m.begin(); it != m.end(); ++it)
    {
        if (!first)
            oss << ", ";
        oss << quote(it->first) << ": " << quote(it->second);
        first = false;
    }
    oss << "}";
    return oss.str();
}

static std::string vectorToJSON(const std::vector<std::string> &v)
{
    std::ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < v.size(); ++i)
    {
        oss << quote(v[i]);
        if (i != v.size() - 1)
            oss << ", ";
    }
    oss << "]";
    return oss.str();
}

// ---------- dump2JSON ----------

std::string VerilogTestBench::dump2JSON(void)
{
    std::ostringstream oss;
    oss << "{\n";
    oss << "  " << quote("module") << ": " << quote(module) << ",\n";
    oss << "  " << quote("timescale") << ": " << quote(timescale) << ",\n";

    // Clock
    oss << "  " << quote("clock") << ": {\n";
    oss << "    " << quote("name") << ": " << quote(clock.name) << ",\n";
    oss << "    " << quote("period") << ": " << clock.period << ",\n";
    oss << "    " << quote("unit") << ": " << quote(clock.unit) << "\n";
    oss << "  },\n";

    // Reset
    oss << "  " << quote("reset") << ": {\n";
    oss << "    " << quote("name") << ": " << quote(reset.name) << ",\n";
    oss << "    " << quote("type") << ": " << quote(reset.type) << ",\n";
    oss << "    " << quote("active_high") << ": " << (reset.active_high ? "true" : "false") << "\n";
    oss << "  },\n";

    // IO ports
    oss << "  " << quote("IO ports") << ": {\n";
    oss << "    " << quote("inputs") << ": " << vectorToJSON(input_ports) << ",\n";
    oss << "    " << quote("outputs") << ": " << vectorToJSON(output_ports) << "\n";
    oss << "  },\n";

    // IO patterns
    oss << "  " << quote("IO patterns") << ": [\n";
    for (size_t i = 0; i < patterns.size(); ++i)
    {
        const IOPattern &p = patterns[i];
        oss << "    {\n";
        oss << "      " << quote("time") << ": " << p.time;
        if (!p.inputs.empty())
        {
            oss << ",\n      " << quote("inputs") << ": " << mapToJSON(p.inputs);
        }
        if (!p.expected_outputs.empty())
        {
            oss << ",\n      " << quote("expected_outputs") << ": " << mapToJSON(p.expected_outputs);
        }
        oss << "\n    }";
        if (i != patterns.size() - 1)
            oss << ",";
        oss << "\n";
    }
    oss << "  ]\n";
    oss << "}";

    return oss.str();
}

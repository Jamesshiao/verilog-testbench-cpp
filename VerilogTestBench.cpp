#include "VerilogTestBench.h"
#include <sstream>
#include <iomanip>

// helper: 將字串加上雙引號
std::string quote(const std::string &s)
{
    return "\"" + s + "\"";
}

// helper: 輸出 map 為 JSON 格式（C++14 版本）
std::string mapToJSON(const std::map<std::string, std::string> &m)
{
    std::ostringstream oss;
    oss << "{";
    bool first = true;
    for (auto it = m.begin(); it != m.end(); ++it)
    {
        if (!first)
            oss << ", ";
        oss << quote(it->first) << ": " << quote(it->second);
        first = false;
    }
    oss << "}";
    return oss.str();
}

// dump2JSON 實作
std::string VerilogTestBench::dump2JSON() const
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

    // inputs
    oss << "    " << quote("inputs") << ": [";
    for (size_t i = 0; i < input_ports.size(); ++i)
    {
        oss << quote(input_ports[i]);
        if (i != input_ports.size() - 1)
            oss << ", ";
    }
    oss << "],\n";

    // outputs
    oss << "    " << quote("outputs") << ": [";
    for (size_t i = 0; i < output_ports.size(); ++i)
    {
        oss << quote(output_ports[i]);
        if (i != output_ports.size() - 1)
            oss << ", ";
    }
    oss << "]\n";
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
            oss << ",\n";
            oss << "      " << quote("inputs") << ": " << mapToJSON(p.inputs);
        }
        if (!p.expected_outputs.empty())
        {
            if (p.inputs.empty())
                oss << ",\n";
            else
                oss << ",\n";
            oss << "      " << quote("expected_outputs") << ": " << mapToJSON(p.expected_outputs);
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

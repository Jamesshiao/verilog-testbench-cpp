// VerilogTestBench.h
#ifndef VERILOG_TEST_BENCH_H
#define VERILOG_TEST_BENCH_H

#include <string>
#include <vector>
#include <map>

// 表示 clock 結構
struct ClockConfig
{
    std::string name;
    int period; // in ns
    std::string unit;
};

// 表示 reset 結構
struct ResetConfig
{
    std::string name;
    std::string type; // e.g., "synchronous"
    bool active_high;
};

// 每個時間點的 I/O 操作與預期輸出
struct IOPattern
{
    int time; // in ns
    std::map<std::string, std::string> inputs;
    std::map<std::string, std::string> expected_outputs;
};

// 總體測試架構
class VerilogTestBench
{
public:
    std::string module;
    std::string timescale;
    ClockConfig clock;
    ResetConfig reset;
    std::vector<std::string> input_ports;
    std::vector<std::string> output_ports;
    std::vector<IOPattern> patterns;

    // 將結構內容轉成 JSON 字串
    std::string dump2JSON() const;
};

#endif // VERILOG_TEST_BENCH_H

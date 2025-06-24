#ifndef _VERILOG_TEST_BENCH_H_
#define _VERILOG_TEST_BENCH_H_

#include <string>
#include <vector>
#include <map>
#include <jsoncpp/json/json.h> // Json::Value 需要 jsoncpp

// 時脈設定
class ClockConfig
{
public:
    std::string name;
    int period;
    std::string unit;

    ClockConfig();
    ClockConfig(const std::string &name, int period, const std::string &unit);
};

// Reset 設定
class ResetConfig
{
public:
    std::string name;
    std::string type; // e.g., "synchronous"
    bool active_high;

    ResetConfig();
    ResetConfig(const std::string &name, const std::string &type, bool active_high);
};

// I/O Pattern：每一筆的 input/output
class IOPattern
{
public:
    int time;
    std::map<std::string, std::string> inputs;
    std::map<std::string, std::string> expected_outputs;

    IOPattern();
    IOPattern(int t, const std::map<std::string, std::string> &in, const std::map<std::string, std::string> &out);
};

// 主體 Test Bench 類別
class VerilogTestBench
{
protected:
    std::string module;
    std::string timescale;
    ClockConfig clock;
    ResetConfig reset;
    std::vector<std::string> input_ports;
    std::vector<std::string> output_ports;
    std::vector<IOPattern> patterns;

public:
    // Constructors
    VerilogTestBench();
    virtual ~VerilogTestBench();

    // 設定方法
    void setModule(const std::string &m);
    void setTimescale(const std::string &ts);
    void setClock(const ClockConfig &clk);
    void setReset(const ResetConfig &rst);
    void setInputs(const std::vector<std::string> &inputs);
    void setOutputs(const std::vector<std::string> &outputs);
    void addPattern(const IOPattern &pattern);

    // 將整個 testbench 輸出成 JSON 格式
    virtual std::string dump2JSON(void);

    // future:
    // virtual void JSON2Object(Json::Value *);
};

#endif /* _VERILOG_TEST_BENCH_H_ */

#include <iostream>
#include "ModuleConfig.h"

int main() {
    ModuleConfig adder(
        "adder",
        "1ns/1ps",
        ClockConfig(),
        ResetConfig(),
        IOPort({ "a", "b" }, { "sum" }),
        {
            IOPattern(Time(0),
                      { { Signal("a"), "0000" }, { Signal("b"), "0000" } },
                      { { Signal("sum"), "0000" } }),
            IOPattern(Time(12),
                      { { Signal("a"), "0010" }, { Signal("b"), "0011" } },
                      { { Signal("sum"), "0101" } })
        }
    );

    Json::Value* adder_json = adder.dump2JSON();
    std::cout << "=== adder.json ===\n" << adder_json->toStyledString() << std::endl;
    delete adder_json;

    ModuleConfig add_dff;
    add_dff.setModuleName("add_dff");
    add_dff.setTimescale("1ns/1ps");

    ClockConfig clk;
    clk.Set(Signal("clk"));
    clk.SetPeriod(10);
    clk.SetUnit("ns");
    add_dff.setClockConfig(clk);

    ResetConfig rst;
    rst.Set(Signal("rst"));
    rst.SetType("synchronous");
    rst.SetActiveHigh(true);
    add_dff.setResetConfig(rst);

    IOPort port;
    port.setInputs({ "clk", "rst", "a", "b", "sel" });
    port.setOutputs({ "result" });
    add_dff.setIOPort(port);

    const auto& adder_patterns = adder.getIOPatterns();

    IOPattern p0 = adder_patterns[0];
    p0.addInput(Signal("rst"), "1");
    p0.addInput(Signal("sel"), "0");
    p0.setExpectedOutputs({});
    add_dff.addIOPattern(p0);

    add_dff.addIOPattern(IOPattern(
        Time(5),
        { { Signal("rst"), "0" } },
        {}
    ));

    IOPattern p12 = adder_patterns[1];
    p12.addInput(Signal("sel"), "1");
    add_dff.addIOPattern(p12);

    add_dff.addIOPattern(IOPattern(
        Time(22),
        {},
        { { Signal("result"), "0101" } }
    ));

    add_dff.addIOPattern(IOPattern(
        Time(25),
        { { Signal("sel"), "0" } },
        {}
    ));

    add_dff.addIOPattern(IOPattern(
        Time(35),
        {},
        { { Signal("result"), "0010" } }
    ));

    Json::Value* add_dff_json = add_dff.dump2JSON();
    std::cout << "=== add_dff.json ===\n" << add_dff_json->toStyledString() << std::endl;
    delete add_dff_json;

    return 0;
}

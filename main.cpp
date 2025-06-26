#include <iostream>
#include "ModuleConfig.h"

int main()
{
    ModuleConfig config(
        "add_dff",
        "1ns/1ps",
        ClockConfig(Signal("clk"), 10, "ns"),
        ResetConfig(Signal("rst"), "synchronous", true),
        IOPort({ "clk", "rst", "a", "b", "sel" }, { "result" }),
        {
            IOPattern(Time(0), std::map<Signal, std::string>{
                { Signal("a"), "0000" },
                { Signal("b"), "0000" },
                { Signal("rst"), "1" },
                { Signal("sel"), "0" }
            }),
            IOPattern(Time(5), std::map<Signal, std::string>{
                { Signal("rst"), "0" }
            }),
            IOPattern(Time(12), std::map<Signal, std::string>{
                { Signal("a"), "0010" },
                { Signal("b"), "0011" },
                { Signal("sel"), "1" }
            }),
            IOPattern(Time(22),
                std::map<Signal, std::string>{},
                std::map<Signal, std::string>{
                    { Signal("result"), "0101" }
                }),
            IOPattern(Time(25), std::map<Signal, std::string>{
                { Signal("sel"), "0" }
            }),
            IOPattern(Time(35),
                std::map<Signal, std::string>{},
                std::map<Signal, std::string>{
                    { Signal("result"), "0010" }
                })
        }
    );

    Json::Value* j = config.dump2JSON();
    std::cout << j->toStyledString();
    delete j;

    return 0;
}

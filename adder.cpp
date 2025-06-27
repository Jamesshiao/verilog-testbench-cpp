#include <iostream>
#include "ModuleConfig.h"

int main() {
    ModuleConfig adder(
        "adder",                
        "1ns/1ps",                   
        ClockConfig(),              // no clock
        ResetConfig(),              // no reset
        IOPort({ "a", "b" }, { "sum" }), // I/O ports
        {
            // I/O pattern 1
            IOPattern(Time(0),
                      {
                          { Signal("a"), "0000" },
                          { Signal("b"), "0000" }
                      },
                      {
                          { Signal("sum"), "0000" }
                      }),
            // I/O pattern 2
            IOPattern(Time(12),
                      {
                          { Signal("a"), "0010" },
                          { Signal("b"), "0011" }
                      },
                      {
                          { Signal("sum"), "0101" }
                      })
        }
    );

    // output JSON
    Json::Value* j = adder.dump2JSON();
    std::cout << j->toStyledString();
    delete j;

    return 0;
}

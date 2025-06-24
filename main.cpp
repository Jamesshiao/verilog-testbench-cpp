// main.cpp
#include "VerilogTestBench.h"
#include <iostream>

int main()
{
    // 建立 TestBench 實例
    VerilogTestBench tb;

    // 模組名稱與時間單位
    tb.module = "add_dff";
    tb.timescale = "1ns/1ps";

    // Clock 與 Reset 設定
    tb.clock = {
        "clk", // name
        10,    // period
        "ns"   // unit
    };

    tb.reset = {
        "rst",         // name
        "synchronous", // type
        true           // active_high
    };

    // I/O ports
    tb.input_ports = {"clk", "rst", "a", "b", "sel"};
    tb.output_ports = {"result"};

    // 波形資料（根據你提供的 JSON）
    tb.patterns = {
        {0,
         {{"rst", "1"}, {"a", "0000"}, {"b", "0000"}, {"sel", "0"}},
         {}},
        {5,
         {{"rst", "0"}},
         {}},
        {12,
         {{"a", "0010"}, {"b", "0011"}, {"sel", "1"}},
         {}},
        {22,
         {},
         {{"result", "0101"}}},
        {25,
         {{"sel", "0"}},
         {}},
        {35,
         {},
         {{"result", "0010"}}}};

    // 輸出 JSON 到 stdout
    std::cout << tb.dump2JSON() << std::endl;

    return 0;
}

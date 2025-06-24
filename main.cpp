#include "VerilogTestBench.h"
#include <iostream>
#include <fstream>

int main()
{
    // 建立 TestBench 物件
    VerilogTestBench tb;

    // 設定基本屬性
    tb.setModule("add_dff");
    tb.setTimescale("1ns/1ps");
    tb.setClock(ClockConfig("clk", 10, "ns"));
    tb.setReset(ResetConfig("rst", "synchronous", true));
    tb.setInputs({"clk", "rst", "a", "b", "sel"});
    tb.setOutputs({"result"});

    // 加入測試時序資料
    tb.addPattern(IOPattern(0, {{"rst", "1"}, {"a", "0000"}, {"b", "0000"}, {"sel", "0"}}, {}));
    tb.addPattern(IOPattern(5, {{"rst", "0"}}, {}));
    tb.addPattern(IOPattern(12, {{"a", "0010"}, {"b", "0011"}, {"sel", "1"}}, {}));
    tb.addPattern(IOPattern(22, {}, {{"result", "0101"}}));
    tb.addPattern(IOPattern(25, {{"sel", "0"}}, {}));
    tb.addPattern(IOPattern(35, {}, {{"result", "0010"}}));

    // 輸出 JSON 到螢幕
    std::string json_output = tb.dump2JSON();
    std::cout << json_output << std::endl;

    // （可選）寫入檔案 output.json
    std::ofstream ofs("output.json");
    if (ofs.is_open())
    {
        ofs << json_output;
        ofs.close();
        std::cout << "JSON 已寫入 output.json" << std::endl;
    }
    else
    {
        std::cerr << "無法寫入 output.json" << std::endl;
    }

    return 0;
}

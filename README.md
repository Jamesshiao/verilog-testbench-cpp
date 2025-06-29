# ee1520_s2025 final
## Programs

- `./main`: display both `adder.json` and `add_dff.json`.
- `./adder`: display only `adder.json`

## MakeFile

`make`: compile and link `main` and `adder`.

`make clean`: remove `main`, `adder`, and all `.o` object files.

## How to run the programs

`make`

`./main` : output adder.json and add_dff.json. on the terminal

## Innovative Idea
In modern digital design, tools like Verilator and synthesis software often change Verilog circuits into formats like JSON or C++ to help with simulation and analysis. While this method is common for hardware structure, testbenches are still mostly written by hand and lack automation. To improve this, we created two JSON formats: one for combinational logic (like a 4-bit adder) and one for sequential circuits (like designs with flip-flops and clocks). These JSON files clearly describe how inputs and outputs should change over time, making it easier to create testbenches automatically. This helps designers check if their circuits work correctly without writing long Verilog testbenches. It also makes testing faster, more reusable, and easier to include in automated tools or hardware testing systems.

## Scenario
A Verilog design combining combinational and sequential logic is verified using a testbench under a 1ns/1ps timescale. The combinational part is a 4-bit adder with inputs "a" and "b", and output "sum". At time 0, both inputs are "0000" and the expected output is "0000". At time 12, "a" is set to "0010" and "b" to "0011", producing an expected output of "0101".
The sequential part includes a D flip-flop and a multiplexer controlled by signal "sel". When "sel" is high, the result is taken from the flip-flop output; otherwise, it reflects the adder input "a".
The full module add_dff integrates both clock and reset. It has five inputs ("clk", "rst", "a", "b", "sel") and one output ("result"). The clock "clk" runs with a 10ns period, and the reset "rst" is synchronous and active-high. Simulation starts at time 0 with reset active ("rst" = 1), inputs "a" and "b" set to "0000", and "sel" set to "0". Reset is deactivated at time 5. At time 12, "a" = "0010", "b" = "0011", and "sel" = "1", activating the sum path with expected "sum" = "0101". At time 22, output "result" is expected to be "0101". Later, "sel" switches to "0" at time 25, and by time 35, the output "result" is expected to be "0010", indicating the selected path has changed.


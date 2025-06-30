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
In modern digital design, tools like Verilator and synthesis software often change Verilog circuits into formats like JSON or C++ to help with simulation and analysis. While this method is common for hardware structure, testbenches are still mostly written by hand and lack automation. 

To improve this, we represent Verilog testbenches using JSON, allowing future tools to automatically generate Verilog testbenches from these JSON files. This approach avoids writing lengthy Verilog code manually and enables more efficient digital testing. 

## Scenario
A Verilog design combining combinational and sequential logic is verified using a testbench under a 1ns/1ps timescale. The combinational part is a 4-bit adder with inputs "a" and "b", and output "sum". At time 0, both inputs are "0000" and the expected output is "0000". At time 12, "a" is set to "0010" and "b" to "0011", producing an expected output of "0101". 

The sequential part includes a D flip-flop and a multiplexer controlled by signal "sel". When "sel" is high, the result is taken from the flip-flop output; otherwise, it reflects the adder input "a". The full module add_dff integrates both clock and reset. It has five inputs ("clk", "rst", "a", "b", "sel") and one output ("result"). The clock "clk" runs with a 10ns period, and the reset "rst" is synchronous and active-high.

At time 0 with reset("rst" = 1), inputs "a" and "b" set to "0000", and "sel" set to "0". 

At time 5, reset is deactivated ("rst" = 0). 

At time 12, "a" = "0010", "b" = "0011", and "sel" = "1".

At time 22, output "result" is expected to be "0101". 

At time 25, "sel" switches to "0".

At time 35, the output "result" is expected to be "0010".

## Scenario to JSON
### adder (first scenario)
```json
{
  "module": "adder",
  "timescale": "1ns/1ps",
  "IO ports": {
    "inputs": [
      "a",
      "b"
    ],
    "outputs": [
      "sum"
    ]
  },
  "IO patterns": [
    {
      "inputs": {
        "a": "0000",
        "b": "0000"
      },
      "expected_outputs": {
        "sum": "0000"
      },
      "time": 0
    },
    {
      "inputs": {
        "a": "0010",
        "b": "0011"
      },
      "expected_outputs": {
        "sum": "0101"
      },
      "time": 12
    }
  ]
}
```
### add_dff (full scenario)
```json
{
  "module": "add_dff",
  "timescale": "1ns/1ps",
  "clock": {
    "name": "clk",
    "period": 10,
    "unit": "ns"
  },
  "reset": {
    "name": "rst",
    "type": "synchronous",
    "active_high": true
  },
  "IO ports": {
    "inputs": ["clk", "rst", "a", "b", "sel"],
    "outputs": ["result"]
  },
  "IO patterns": [
    {
      "time": 0,
      "inputs": {"a": "0000", "b": "0000", "rst": "1", "sel": "0"}
    },
    {
      "time": 5,
      "inputs": {"rst": "0"}
    },
    {
      "time": 12,
      "inputs": {"a": "0010", "b": "0011", "sel": "1"}
    },
    {
      "time": 22,
      "expected_outputs": {"result": "0101"}
    },
    {
      "time": 25,
      "inputs": {"sel": "0"}
    },
    {
      "time": 35,
      "expected_outputs": {"result": "0010"}
    }
  ]
}
```
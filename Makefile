# 編譯器與選項
CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra -O2

# 目標檔名
TARGET = testbench

# 所有源碼檔案
SRCS = main.cpp VerilogTestBench.cpp

# 所有物件檔
OBJS = $(SRCS:.cpp=.o)

# 預設目標：編譯可執行檔
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清除編譯產生的檔案
clean:
	rm -f $(TARGET) $(OBJS)

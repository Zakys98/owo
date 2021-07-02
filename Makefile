CXX := g++
CPPFLAGS := -std=c++17 -Werror -Wextra -pedantic -g
LDFLAGS := -g
TARGET := owo
SRC_DIR := src
BUILD_DIR := build
FILES := $(BUILD_DIR)/file.o $(BUILD_DIR)/owo.o $(BUILD_DIR)/section.o $(BUILD_DIR)/controller.o $(BUILD_DIR)/data.o $(BUILD_DIR)/exception.o

all: $(BUILD_DIR) $(TARGET)

$(TARGET): $(FILES)
	$(CXX) $(LDFLAGS) $(FILES) -o $(TARGET) -lstdc++fs

$(BUILD_DIR)/file.o: $(SRC_DIR)/file.cc
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CPPFLAGS) -c $(SRC_DIR)/file.cc -o $(BUILD_DIR)/file.o -lstdc++fs

$(BUILD_DIR)/owo.o: $(SRC_DIR)/owo.cc
	$(CXX) $(CPPFLAGS) -c $(SRC_DIR)/owo.cc -o $(BUILD_DIR)/owo.o

$(BUILD_DIR)/section.o: $(SRC_DIR)/section.cc
	$(CXX) $(CPPFLAGS) -c $(SRC_DIR)/section.cc -o $(BUILD_DIR)/section.o

$(BUILD_DIR)/controller.o: $(SRC_DIR)/controller.cc
	$(CXX) $(CPPFLAGS) -c $(SRC_DIR)/controller.cc -o $(BUILD_DIR)/controller.o

$(BUILD_DIR)/data.o: $(SRC_DIR)/data.cc
	$(CXX) $(CPPFLAGS) -c $(SRC_DIR)/data.cc -o $(BUILD_DIR)/data.o

$(BUILD_DIR)/exception.o: $(SRC_DIR)/exception.cc
	$(CXX) $(CPPFLAGS) -c $(SRC_DIR)/exception.cc -o $(BUILD_DIR)/exception.o

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -f $(TARGET) $(BUILD_DIR)/*.o

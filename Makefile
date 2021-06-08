CC := g++
CPPFLAGS := -std=c++17 -Werror -Wextra -pedantic -g
TARGET := owo
SRC_DIR := src
FILES := $(SRC_DIR)/file.o $(SRC_DIR)/owo.o $(SRC_DIR)/section.o $(SRC_DIR)/controller.o $(SRC_DIR)/data.o

all: $(TARGET)

$(TARGET): $(FILES)
	$(CC) $(CPPFLAGS) $(FILES) -o $(TARGET) -lstdc++fs

$(SRC_DIR)/file.o: $(SRC_DIR)/file.cc
	$(CC) $(CPPFLAGS) -c $(SRC_DIR)/file.cc -o $(SRC_DIR)/file.o -lstdc++fs

$(SRC_DIR)/owo.o: $(SRC_DIR)/owo.cc
	$(CC) $(CPPFLAGS) -c $(SRC_DIR)/owo.cc -o $(SRC_DIR)/owo.o

$(SRC_DIR)/section.o: $(SRC_DIR)/section.cc
	$(CC) $(CPPFLAGS) -c $(SRC_DIR)/section.cc -o $(SRC_DIR)/section.o

$(SRC_DIR)/controller.o: $(SRC_DIR)/controller.cc
	$(CC) $(CPPFLAGS) -c $(SRC_DIR)/controller.cc -o $(SRC_DIR)/controller.o

$(SRC_DIR)/data.o: $(SRC_DIR)/data.cc
	$(CC) $(CPPFLAGS) -c $(SRC_DIR)/data.cc -o $(SRC_DIR)/data.o

clean:
	rm -f $(TARGET) $(SRC_DIR)/*.o

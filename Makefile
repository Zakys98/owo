CPPFLAGS = -std=c++17 -Werror -Wextra -pedantic -g
FILES = files/file.o files/owo.o files/section.o files/controller.o files/data.o

all: owo

owo: $(FILES)
	g++ $(CPPFLAGS) $(FILES) -o owo -lstdc++fs

files/file.o: files/file.cc
	g++ $(CPPFLAGS) -c files/file.cc -o files/file.o -lstdc++fs

files/owo.o: files/owo.cc
	g++ $(CPPFLAGS) -c files/owo.cc -o files/owo.o

files/section.o: files/section.cc
	g++ $(CPPFLAGS) -c files/section.cc -o files/section.o

files/controller.o: files/controller.cc
	g++ $(CPPFLAGS) -c files/controller.cc -o files/controller.o

files/data.o: files/data.cc
	g++ $(CPPFLAGS) -c files/data.cc -o files/data.o

clean:
	rm owo files/*.o

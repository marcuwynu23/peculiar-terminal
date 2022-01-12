SOURCE=$(wildcard src/*.cpp)
all: 
	g++ --std=c++11 -I include  -o dist/terminal.exe $(SOURCE)

SOURCE=$(wildcard src/*.cpp)
all: 
	g++ --std=gnu++11 -I include  -o dist/terminal.exe $(SOURCE)
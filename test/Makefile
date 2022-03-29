CC = g++
OBJECTS = dosaic.o mystring.o testso.o
EXEC = test

CXXFLAGS	:= -std=c++17 -Wall -g

SRCDIRS :=
SOURCES := $(wildcard *.cpp)
OBJECTS 	:= $(SOURCES:.cpp=.o)
INCLUDEDIRS = #/usr/include/opencv4

INCLUDES	:= $(patsubst %,-I%, $(INCLUDEDIRS:%/=%))

$(EXEC) : $(OBJECTS)
	$(CC) $(CXXFLAGS) $(OBJECTS) libdosaic.so -o $(EXEC) 

mystring.o : mystring.cpp
	$(CC) $(CXXFLAGS) -o mystring.o -c mystring.cpp
test.o : test.cpp
	$(CC) $(CXXFLAGS) -o test.o -c test.cpp

#$(OBJECTS) : $(SOURCES)
#	$(CC) $(CXXFLAGS) $(INCLUDES) $(SOURCES)



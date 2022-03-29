CC = g++


CXXFLAGS	:= -std=c++17 -Wall -fPIC -g

SO = libdosaic.so
OBJECTS = dosaic.o mystring.o testso.o -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs

INCLUDES	:= $(patsubst %,-I%, $(INCLUDEDIRS:%/=%))

$(SO) : $(OBJECTS)
	$(CC) $(CXXFLAGS) -shared -L/usr/lib/x86_64-linux-gnu $(OBJECTS) -o $(SO) 

mystring.o : mystring.cpp
	$(CC) $(CXXFLAGS)  -c mystring.cpp mystring.o
dosaic.o : dosaic.cpp
	$(CC) $(CXXFLAGS)  -c -I/usr/include/opencv4 dosaic.cpp dosaic.o
testso.o : testso.cpp
	$(CC) $(CXXFLAGS)  -c -I/usr/include/opencv4 testso.cpp testso.o

PHONY : clean
clean:
	rm -f *.o *.so
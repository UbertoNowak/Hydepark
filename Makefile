CC = gcc
CXX = g++

CFLAGS = -Wall
CXXFLAGS = -Wall -std=c++11

objects_c = algorithms const events file_descriptors pointers ownership
objects_cpp = containers reference struct
all: $(objects_c) $(objects_cpp)

$(objects_c): %: %.c
	$(CC) $(CFLAGS) -o $@ $<

$(objects_cpp): %: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

.PHONY : clean all

clean:
	rm $(objects_c) $(objects_cpp)

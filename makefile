##----------------------------------------------------------------------
##							Makefile Variables
##----------------------------------------------------------------------
TARGET := aa

CXX := g++
CXXFLAGS := -std=c++11 -g -Wall -pedantic-errors -static-libstdc++
#LDFLAGS :=-static-libstdc++
RM := rm -f *.gch

#SRC := $(shell find . -name "*.cpp")
#OBJS  := $(main.cpp, %.o, header.h,circular_linked_list.h)
##----------------------------------------------------------------------
##							Make Functions
##----------------------------------------------------------------------
all: $(OBJS)
	$(CXX) $(CXXFLAGS) main.cpp  header.h circular_linked_list.h
	chmod 777 a.out
	$(RM)

#depend: .depend

clean:
	echo "make clean"
	$(RM) *.gch

#include .depend

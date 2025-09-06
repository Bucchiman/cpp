#
# FileName:     Makefile
# Author:		8ucchiman
# CreatedDate:  2023-07-01 21:16:01
# LastModified: 2023-02-03 21:27:40 +0900
# Reference:	https://qiita.com/chibi929/items/b8c5f36434d5d3fbfa4a
# Description:	---
#



CXX := g++
OUT := main

SRCS := main.cpp $(HOME)/source/glad/src/glad.c
OBJS := $(SRCS:.cpp=.o)
OBJS := $(OBJS:.c=.o)

INCLUDES := -I/home/bucchiman/source/glad/include $(shell pkg-config --cflags glfw3)
LIBS     := $(shell pkg-config --libs glfw3) -ldl -lGL

$(OUT): $(OBJS)
	$(CXX) -o $@ $^ $(LIBS)

%.o: %.cpp
	$(CXX) $(INCLUDES) -c $< -o $@

%.o: %.c
	$(CXX) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(OUT)

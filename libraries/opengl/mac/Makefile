#
# FileName:     Makefile
# Author: 		8ucchiman
# CreatedDate:  2023-08-20 16:51:47
# LastModified: 2024-01-05 13:42:10
# Reference: 	https://qiita.com/chibi929/items/b8c5f36434d5d3fbfa4a
# Description:	---
#



CXXFLAGS = -g –Wall -std=c++11
LDLIBS = -L/opt/local/lib -lglfw3 -lGLEW -framework OpenGL \
		 -framework CoreVideo -framework IOKit -framework Cocoa
OBJECTS = $(patsubst %.cpp,%.o,$(wildcard *.cpp))
TARGET = sample

.PHONY: clean

$(TARGET): $(OBJECTS)
	$(LINK.cc) $^ $(LOADLIBES) $(LDLIBS) -o $@
clean:
	-$(RM) $(TARGET) $(OBJECTS) *~ .*~ core

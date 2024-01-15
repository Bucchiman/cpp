#
# FileName:     Makefile
# Author: 		8ucchiman
# CreatedDate:  2023-08-20 16:51:47
# LastModified: 2024-01-05 16:15:01
# Reference: 	
# Description:	---
#



#CXXFLAGS = -g –Wall -std=c++11
#LDLIBS = -L/opt/local/lib -lglfw3 -lGLEW -framework OpenGL \
#		 -framework CoreVideo -framework IOKit -framework Cocoa
#OBJECTS = $(patsubst %.cpp,%.o,$(wildcard *.cpp))
#TARGET = sample

.PHONY: clean auto

auto:
	g++ -o sample sample.cpp -lglfw -framework OpenGL 
		#-framework Cocoa # -framework IOKit -framework CoreVideo


clean:
	-$(RM) $(TARGET) $(OBJECTS) *~ .*~ core sample

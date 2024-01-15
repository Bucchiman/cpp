CXXFLAGS = -g –Wall -std=c++11 -I/opt/local/include
LDLIBS = -L/opt/local/lib -lglfw3 -lGLEW -framework OpenGL \
		 -framework CoreVideo -framework IOKit -framework Cocoa
OBJECTS = $(patsubst %.cpp,%.o,$(wildcard *.cpp))
TARGET = main
.PHONY: clean

$(TARGET): $(OBJECTS)
	g++ $^ $(LDLIBS) $(CXXFLAGS) -o $@

clean:
	-$(RM) $(TARGET) $(OBJECTS) *~ .*~ core

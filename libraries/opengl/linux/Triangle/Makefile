#
# FileName:     Makefile
# Author: 		8ucchiman
# CreatedDate:  2023-07-01 21:16:01
# LastModified: 2023-02-03 21:27:40 +0900
# Reference: 	https://qiita.com/chibi929/items/b8c5f36434d5d3fbfa4a
# Description:	---
#


.PHONY: clean

main: main.o
	#g++ -Wall -Weffc++ -o main main.o -lglut -lGLU -lGL
	cc -Wall -Weffc++ -o main main.o -lglut -lGLU -lGL

#main.o: main.cpp
#	g++ -c main.cpp

main.o: main.c
	cc -c main.cpp

clean:
	rm main.o main

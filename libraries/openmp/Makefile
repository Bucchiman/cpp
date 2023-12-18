# FileName:     Makefile
# Author: 8ucchiman
# CreatedDate:  2023-03-28 10:29:51 +0900
# LastModified: 2023-03-28 10:30:13 +0900
# Reference:    https://www.cc.u-tokyo.ac.jp/events/lectures/03/kosyu-openmp_c.pdf





.PHONY: clean



run:
	g++ -fopenmp -o hello hello_world.cpp

run_for:
	g++ -fopenmp -o for_parallel for_parallel.cpp

run_section:
	g++ -fopenmp -o section_example section_example.cpp

clean:
	rm *.png *.pdf *.jpg *.aux *.dvi *.log

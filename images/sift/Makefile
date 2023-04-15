# FileName:     Makefile
# Author: 8ucchiman
# CreatedDate:  2023-03-27 11:58:35 +0900
# LastModified: 2023-03-29 18:27:30 +0900
# Reference: 8ucchiman.jp




LIB_PATH=/usr/local/include/opencv4

run:
	g++ main.cpp -I${LIB_PATH} -lopencv_objdetect -lopencv_features2d -lopencv_imgproc -lopencv_highgui -lopencv_core
	#g++ main.cpp -I/usr/include/opencv4/ -lopencv_objdetect -lopencv_features2d -lopencv_imgproc -lopencv_highgui -lopencv_core



.PHONY: clean
clean:
	rm *.png *.pdf *.jpg *.aux *.dvi *.log a.out

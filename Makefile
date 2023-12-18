# FileName:     Makefile
# Author: 8ucchiman
# CreatedDate:  2023-03-27 11:58:35 +0900
# LastModified: 2023-03-29 09:08:15 +0000
# Reference: 8ucchiman.jp






version:
	#g++ main.cpp -I/usr/include/opencv4/ -lopencv_core -lopencv_videoio -lopencv_highgui -lopencv_imgproc
	g++ opencv_version.cpp -I/usr/local/include/opencv4/ -lopencv_objdetect -lopencv_features2d -lopencv_imgproc -lopencv_highgui -lopencv_core


.PHONY: clean
clean:
	rm *.png *.pdf *.jpg *.aux *.dvi *.log a.out

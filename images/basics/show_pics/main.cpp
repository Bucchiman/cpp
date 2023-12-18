/*
 * FileName:     main
 * Author:       8ucchiman
 * CreatedDate:  2023-04-25 18:17:08
 * LastModified: 2023-03-28 10:34:14 +0900
 * Reference:    8ucchiman.jp
 * Description:  ---
 */


#include <iostream>
#include <opencv2/opencv.hpp>


int main(int argc, char* argv[]){
    cv::Mat img = cv::imread("lena.jpg");
    cv::imshow("img", img);
    cv::waitKey();
    return 0;
}


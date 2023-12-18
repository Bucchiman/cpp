/*
 * FileName:     main
 * Author:       8ucchiman
 * CreatedDate:  2023-04-26 15:35:36
 * LastModified: 2023-03-28 10:34:14 +0900
 * Reference:    8ucchiman.jp
 * Description:  ---
 */


#include <iostream>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv4/opencv2/core/types.hpp>


int DELAY_CAPTION = 1500;
int DELAY_BLUR = 100;
int MAX_KERNEL_LENGTH = 31;

cv::Mat src;
cv::Mat dst;

char window_name[] = "Smoothing Demo";

int display_caption(const char* caption);
int display_dst(int delay);


int main(int argc, char* argv[]){
    cv::namedWindow(window_name, cv::WINDOW_AUTOSIZE);
    const char* filename = argc >=2 ? argv[1] : "lena.jpg";

    src = cv::imread(cv::samples::findFile(filename), cv::IMREAD_COLOR);
    if (src.empty()) {
        printf(" Error opening image\n");
        printf(" Usage:\n %s [image_name-- default lena.jpg] \n", argv[0]);
        return EXIT_FAILURE;
    }

    if (display_caption("Original Image") != 0) {
        return 0;
    }

    dst = src.clone();
    if (display_dst(DELAY_CAPTION) != 0) {
        return 0;
    }

    for (int i=1; i<MAX_KERNEL_LENGTH; i=i+2) {
        blur(src, dst, cv::Size(i, i), cv::Point(-1, -1));
        if (display_dst(DELAY_BLUR) != 0) {
            return 0;
        }
    }
    if (display_caption("Gaussian Blur") != 0) {
        return 0;
    }

    for (int i=1; i<MAX_KERNEL_LENGTH; i=i+2) {
        cv::GaussianBlur(src, dst, cv::Size(i, i), 0, 0);
        if (display_dst(DELAY_BLUR) != 0) {
            return 0;
        }
    }

    if (display_caption("Median Blur") != 0) {
        return 0;
    }

    for (int i=1; i<MAX_KERNEL_LENGTH; i=i+2) {
        cv::medianBlur(src, dst, i);
        if (display_dst(DELAY_BLUR) != 0) {
            return 0;
        }
    }

    if (display_caption("Bilateral Blur") != 0) {
        return 0;
    }

    for (int i=1; i<MAX_KERNEL_LENGTH; i=i+2) {
        cv::bilateralFilter(src, dst, i, i*2, i/2);
        if (display_dst(DELAY_BLUR) != 0) {
            return 0;
        }
    }
    display_caption("Done!");
    return 0;
}


int display_caption(const char* caption) {
    dst = cv::Mat::zeros(src.size(), src.type());
    cv::putText(dst,
                caption,
                cv::Point(src.cols/4, src.rows/2),
                cv::FONT_HERSHEY_COMPLEX,
                1,
                cv::Scalar(255, 255, 255));
    return display_dst(DELAY_CAPTION);
}

int display_dst(int delay) {
    cv::imshow(window_name, dst);
    int c = cv::waitKey(delay);
    if (c >= 0) { return -1; }
    return 0;
}

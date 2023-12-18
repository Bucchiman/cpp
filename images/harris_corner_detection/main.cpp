/*
 * FileName:     main
 * Author:       8ucchiman
 * CreatedDate:  2023-03-27 18:33:06 +0900
 * LastModified: 2023-03-27 19:38:40 +0900
 * Reference:    https://docs.opencv.org/3.4/d4/d7d/tutorial_harris_detector.html
 */

#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

cv::Mat src, src_gray;
int thresh = 200;
int max_thresh = 255;

const char* source_window = "Source image";
const char* corners_window = "Corners detected";


/** @brief Converts an image from one color space to another where the source image is
stored in two planes.

This function only supports YUV420 to RGB conversion as of now.

@param src1: 8-bit image (#CV_8U) of the Y plane.
@param src2: image containing interleaved U/V plane.
@param dst: output image.
@param code: Specifies the type of conversion. It can take any of the following values:
- #COLOR_YUV2BGR_NV12
- #COLOR_YUV2RGB_NV12
- #COLOR_YUV2BGRA_NV12
- #COLOR_YUV2RGBA_NV12
- #COLOR_YUV2BGR_NV21
- #COLOR_YUV2RGB_NV21
- #COLOR_YUV2BGRA_NV21
- #COLOR_YUV2RGBA_NV21
*/
void cornerHarris_demo(int, void*);


int main(int argc, char** argv){
    cv::CommandLineParser parser(argc, argv, "{@input | building.jpg | input image}");
    src = cv::imread(cv::samples::findFile(parser.get<cv::String>("@input")));
    if (src.empty()) {
        std::cout << "Could not open or find the image!\n" << std::endl;
        std::cout << "Usage: " << argv[0] << "<Input image>" << std::endl;
        return -1;
    }
    cv::cvtColor(src, src_gray, cv::COLOR_BGR2GRAY);
    cv::namedWindow(source_window);
    cv::createTrackbar("Threshold: ", source_window, &thresh, max_thresh, cornerHarris_demo);
    imshow(source_window, src);
    cornerHarris_demo(0, 0);

    cv::waitKey();
    return 0;
}

void cornerHarris_demo(int, void*) {
    int blockSize = 2;
    int apertureSize = 3;
    double k = 0.04;

    cv::Mat dst = cv::Mat::zeros(src.size(), CV_32FC1);
    cornerHarris(src_gray, dst, blockSize, apertureSize, k);

    cv::Mat dst_norm, dst_norm_scaled;
    normalize(dst, dst_norm, 0, 255, cv::NORM_MINMAX, CV_32FC1, cv::Mat());
    convertScaleAbs(dst_norm, dst_norm_scaled);

    for (int i=0; i<dst_norm.rows; i++) {
        for (int j=0; j<dst_norm.cols; j++) {
            if ( (int)dst_norm.at<float>(i, j) > thresh ) {
                circle(dst_norm_scaled, cv::Point(j, i), 5, cv::Scalar(0), 2, 8, 0);
            }
        }
    }
    cv::namedWindow(corners_window);
    imshow(corners_window, dst_norm_scaled);
}

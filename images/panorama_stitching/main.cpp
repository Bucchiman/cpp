/*
 * FileName:     main
 * Author: 8ucchiman
 * CreatedDate:  2023-03-27 17:22:55 +0900
 * LastModified: 2023-03-27 17:52:02 +0900
 * Reference: 8ucchiman.jp
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include "opencv4/opencv2/opencv.hpp"
#include "opencv4/opencv2/stitching.hpp""


/*
 * Stitcher::stitch()
 *     |
 *     +----- Stitcher::estimateTransform()
 *     |             |
 *     |             +--- Stitcher::matchImages()
 *     |             +--- Stitcher::estimateCameraParams()
 *     +----- Stitcher::composePanorama()
 *
 */

int main(void){
    using namespace cv;
    char* imageList[] = {
        "image0.jpg",
        "image1.jpg",
        "image2.jpg",
        "image3.jpg",
        "image4.jpg",
    };
    std::vector<Mat> imgArray;
    for (int i=0; i<5; i++) {
        Mat img = imread(imageList[i], IMREAD_UNCHANGED);
        imgArray.push_back(img);
    }

    Mat pano;
    Stitcher::Mode mode = Stitcher::PANORAMA;
    Ptr<cv::Stitcher> stitcher = Stitcher::create(mode);
    stitcher->stitch(imgArray, pano);
    imwrite("Panorama.png", pano);

    return EXIT_SUCCESS;
    return 0;
}

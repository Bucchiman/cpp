/*
 * FileName:     Bmods
 * Author:       8ucchiman
 * CreatedDate:  2025-05-01 11:15:05
 * LastModified: 2024-02-09 13:26:58
 * Reference:    8ucchiman.jp
 */


#include <iostream>
#include <opencv2/opencv.hpp>


int ShowVideo(int argc, char* argv[]);


int ShowVideo(int argc, char* argv[]) {
    std::string filepath = argv[1];
    cv::VideoCapture video;

    video.open(filepath);
    if (video.isOpened() == false) {
        return 0;
    }
    cv::VideoWriter writer;

    int width, height, fourcc;
    fourcc = cv::VideoWriter::fourcc('m', 'p', '4', 'v');
    double fps;
    width = (int)video.get(cv::CAP_PROP_FRAME_WIDTH);
    height = (int)video.get(cv::CAP_PROP_FRAME_HEIGHT);
    fps = video.get(cv::CAP_PROP_FPS);

    writer.open("CloneVideo.mp4", fourcc, fps, cv::Size(width, height));
    cv::Mat image;
    while (1) {
        video >> image;
        if (image.empty() == true) break;
        cv::imshow("showing", image);
        writer << image;
        if (cv::waitKey(1) == 'q') break;
    }
    printf("hello world\n");
    return 0;
}

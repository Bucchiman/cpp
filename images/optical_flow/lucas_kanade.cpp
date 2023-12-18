/*
 * FileName:     lucas_kanade
 * Author:       8ucchiman
 * CreatedDate:  2023-05-22 17:08:39
 * LastModified: 2023-03-28 10:34:14 +0900
 * Reference:    https://docs.opencv.org/3.4/d4/dee/tutorial_optical_flow.html
 * Description:  ---
 */


#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/video.hpp>
#include <opencv4/opencv2/core/types.hpp>


int main(int argc, char* argv[]){
    const std::string about =
        "This sample demonstrates Lucas-Kanade Optical Flow calculation.\n"
        "The example file can be downloaded from:\n"
        "  https://www.bogotobogo.com/python/OpenCV_Python/images/mean_shift_tracking/slow_traffic_small.mp4";
    const std::string keys =
        "{ h help |      | print this help message }"
        "{ @image | vtest.avi | path to image file }";
    cv::CommandLineParser parser(argc, argv, keys);
    parser.about(about);
    if (parser.has("help")) {
        parser.printMessage();
        return 0;
    }

    std::string filename = cv::samples::findFile(parser.get<std::string>("@image"));
    if (!parser.check()) {
        parser.printErrors();
        return 0;
    }
    cv::VideoCapture video;
    video.open(filename);
    if (!video.isOpened()) {
        std::cerr << "Unable to open file!" << std::endl;
        return 0;
    }

    // Create some random colors
    std::vector<cv::Scalar> colors;
    cv::RNG rng;
    for (int i=0; i<100; i++) {
        int r = rng.uniform(0, 256);
        int g = rng.uniform(0, 256);
        int b = rng.uniform(0, 256);
        colors.push_back(cv::Scalar(r, g, b));
    }
    cv::Mat old_frame, old_gray;
    std::vector<cv::Point2f> p0, p1;

    // Take first frame and find corners in it
    video >> old_frame;
    cv::cvtColor(old_frame, old_gray, cv::COLOR_BGR2GRAY);
    cv::goodFeaturesToTrack(old_gray, p0, 100, 0.3, 7, cv::Mat(), 7, false, 0.04);

    // Create a mask image for drawing purposes
    cv::Mat mask = cv::Mat::zeros(old_frame.size(), old_frame.type());

    while (true) {
        cv::Mat frame, frame_gray;
        video >> frame;
        if (frame.empty())
            break;
        cv::cvtColor(frame, frame_gray, cv::COLOR_BGR2GRAY);
        // calculate optical flow
        std::vector<uchar> status;
        std::vector<float> err;
        cv::TermCriteria criteria = cv::TermCriteria((cv::TermCriteria::COUNT) + (cv::TermCriteria::EPS), 10, 0.03);
        cv::calcOpticalFlowPyrLK(old_gray, frame_gray, p0, p1, status, err, cv::Size(15, 15), 2, criteria);
        std::vector<cv::Point2f> good_new;
        for (uint i=0; i<p0.size(); i++) {
            // Select good points
            if (status[i] == 1) {
                good_new.push_back(p1[i]);
                // draw the tracks
                cv::line(mask, p1[i], p0[i], colors[i], 2);
                cv::circle(frame, p1[i], 5, colors[i], -1);
            }
        }
        cv::Mat img;
        cv::add(frame, mask, img);
        cv::imshow("Frame", img);
        int keyboard = cv::waitKey(30);
        if (keyboard == 'q' || keyboard == 27) {
            break;
        }
        // Now update the previous frame and previous points
        old_gray = frame_gray.clone();
        p0 = good_new;
    }
    return 0;
}


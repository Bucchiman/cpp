/*
 * FileName:     main
 * Author:       8ucchiman
 * CreatedDate:  2023-03-28 11:43:11 +0900
 * LastModified: 2023-03-29 10:51:08 +0000
 * Reference: 	 https://zenn.dev/turing_motors/articles/daf3e8829f0967
 */



#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>
//#include <opencv2/nonfree.hpp>


int main() {
    std::vector<cv::KeyPoint> keypoints_source, keypoints_target;
    cv::Ptr<cv::Feature2D> f2d = cv::xfeatures2d::SiftFeatureDetector::create();

    f2d->detect(img_gray_source, keypoints_source);
    f2d->detect(img_gray_target, keypoints_target);

    cv::Mat descriptors_source, descriptors_target;
    f2d->compute(img_gray_source, keypoints_source, descriptors_source);
    f2d->compute(img_gray_target, keypoints_target, descriptors_target);

    cv::BFMatcher matcher;

    std::vector<cv::DMatch> knn_matches;
    matcher.knnMatch(descriptors_source, descriptors_target, knn_matches, 20);
    const float ratio_threash = .75f;
    std::vecrot<cv::DMatch> matches;

    for (size_t i=0; i<knn_matches.size(); i++) {
        if (knn_matches[i][0].distance < ratio_thresh * knn_matches[i][1].distance) {
            matches.push_back(knn_matches[i][0]);
        }
    }
    std::vector<cv::Point2f> obj;
    std::vector<cv::Point2f> scene;

    for (size_t i=0; i<matches.size(); i++) {
        obj.push_back(keypoints_source[matches[i].queryIdx].pt);
        scene.push_back(keypoints_target[matches[i].trainIdx].pt);
    }

    return 0;
}

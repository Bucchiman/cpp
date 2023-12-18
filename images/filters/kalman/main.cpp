/*
 * FileName:     main
 * Author:       8ucchiman
 * CreatedDate:  2023-06-01 12:21:05
 * LastModified: 2023-03-28 10:34:14 +0900
 * Reference:    8ucchiman.jp
 * Description:  ---
 */


#include <iostream>
#include "opencv2/video/tracking.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core/cvdef.h"
#include <stdio.h>
#define MACRO


/** @brief Converts an image from one color space to another.

The function converts an input image from one color space to another. In case of a transformation
to-from RGB color space, the order of the channels should be specified explicitly (RGB or BGR). Note
that the default color format in OpenCV is often referred to as RGB but it is actually BGR (the
bytes are reversed). So the first byte in a standard (24-bit) color image will be an 8-bit Blue
component, the second byte will be Green, and the third byte will be Red. The fourth, fifth, and
sixth bytes would then be the second pixel (Blue, then Green, then Red), and so on.

The conventional ranges for R, G, and B channel values are:
-   0 to 255 for CV_8U images
-   0 to 65535 for CV_16U images
-   0 to 1 for CV_32F images

In case of linear transformations, the range does not matter. But in case of a non-linear
transformation, an input RGB image should be normalized to the proper value range to get the correct
results, for example, for RGB \f$\rightarrow\f$ L\*u\*v\* transformation. For example, if you have a
32-bit floating-point image directly converted from an 8-bit image without any scaling, then it will
have the 0..255 value range instead of 0..1 assumed by the function. So, before calling #cvtColor ,
you need first to scale the image down:
@code
    img *= 1./255;
    cvtColor(img, img, COLOR_BGR2Luv);
@endcode
If you use #cvtColor with 8-bit images, the conversion will have some information lost. For many
applications, this will not be noticeable but it is recommended to use 32-bit images in applications
that need the full range of colors or that convert an image before an operation and then convert
back.

If conversion adds the alpha channel, its value will set to the maximum of corresponding channel
range: 255 for CV_8U, 65535 for CV_16U, 1 for CV_32F.

@param src input image: 8-bit unsigned, 16-bit unsigned ( CV_16UC... ), or single-precision
floating-point.
@param dst output image of the same size and depth as src.
@param code color space conversion code (see #ColorConversionCodes).
@param dstCn number of channels in the destination image; if the parameter is 0, the number of the
channels is derived automatically from src and code.

@see @ref imgproc_color_conversions
 */
int hoge(void);


static inline Point calcPoint(Point2f center, double R, double angle);



int hoge(void) {
    return 1;
}


static inline Point calcPoint(Point2f center, double R, double angle)
{
    return center + Point2f((float)cos(angle), (float)-sin(angle))*(float)R;
}
static void help()
{
    printf( "\nExample of c calls to OpenCV's Kalman filter.\n"
"   Tracking of rotating point.\n"
"   Point moves in a circle and is characterized by a 1D state.\n"
"   state_k+1 = state_k + speed + process_noise N(0, 1e-5)\n"
"   The speed is constant.\n"
"   Both state and measurements vectors are 1D (a point angle),\n"
"   Measurement is the real state + gaussian noise N(0, 1e-1).\n"
"   The real and the measured points are connected with red line segment,\n"
"   the real and the estimated points are connected with yellow line segment,\n"
"   the real and the corrected estimated points are connected with green line segment.\n"
"   (if Kalman filter works correctly,\n"
"    the yellow segment should be shorter than the red one and\n"
"    the green segment should be shorter than the yellow one)."
            "\n"
"   Pressing any key (except ESC) will reset the tracking.\n"
"   Pressing ESC will stop the program.\n"
            );
}


#ifdef MACRO
int main(int, char**)
{
    help();
    cv::Mat img(500, 500, CV_8UC3);
    cv::KalmanFilter KF(2, 1, 0);
    cv::Mat state(2, 1, CV_32F); /* (phi, delta_phi) */
    cv::Mat processNoise(2, 1, CV_32F);
    cv::Mat measurement = cv::Mat::zeros(1, 1, CV_32F);
    char code = (char)-1;
    for(;;)
    {
        img = cv::Scalar::all(0);
        state.at<float>(0) = 0.0f;
        state.at<float>(1) = 2.f * (float)CV_PI / 6;
        KF.transitionMatrix = (cv::Mat_<float>(2, 2) << 1, 1, 0, 1);
        setIdentity(KF.measurementMatrix);
        setIdentity(KF.processNoiseCov, cv::Scalar::all(1e-5));
        setIdentity(KF.measurementNoiseCov, cv::Scalar::all(1e-1));
        setIdentity(KF.errorCovPost, cv::Scalar::all(1));
        randn(KF.statePost, cv::Scalar::all(0), cv::Scalar::all(0.1));
        for(;;)
        {
            cv::Point2f center(img.cols*0.5f, img.rows*0.5f);
            float R = img.cols/3.f;
            double stateAngle = state.at<float>(0);
            cv::Point statePt = calcPoint(center, R, stateAngle);
            cv::Mat prediction = KF.predict();
            double predictAngle = prediction.at<float>(0);
            cv::Point predictPt = calcPoint(center, R, predictAngle);
            // generate measurement
            randn( measurement, cv::Scalar::all(0), cv::Scalar::all(KF.measurementNoiseCov.at<float>(0)));
            measurement += KF.measurementMatrix*state;
            double measAngle = measurement.at<float>(0);
            cv::Point measPt = calcPoint(center, R, measAngle);
            // correct the state estimates based on measurements
            // updates statePost & errorCovPost
            KF.correct(measurement);
            double improvedAngle = KF.statePost.at<float>(0);
            cv::Point improvedPt = calcPoint(center, R, improvedAngle);
            // plot points
            img = img * 0.2;
            drawMarker(img, measPt, cv::Scalar(0, 0, 255), cv::MARKER_SQUARE, 5, 2);
            drawMarker(img, predictPt, cv::Scalar(0, 255, 255), cv::MARKER_SQUARE, 5, 2);
            drawMarker(img, improvedPt, cv::Scalar(0, 255, 0), cv::MARKER_SQUARE, 5, 2);
            drawMarker(img, statePt, cv::Scalar(255, 255, 255), cv::MARKER_STAR, 10, 1);
            // forecast one step
            cv::Mat test = cv::Mat(KF.transitionMatrix*KF.statePost);
            drawMarker(img, calcPoint(center, R, cv::Mat(KF.transitionMatrix*KF.statePost).at<float>(0)),
                       cv::Scalar(255, 255, 0), cv::MARKER_SQUARE, 12, 1);
            line( img, statePt, measPt, cv::Scalar(0,0,255), 1, cv::LINE_AA, 0 );
            line( img, statePt, predictPt, cv::Scalar(0,255,255), 1, cv::LINE_AA, 0 );
            line( img, statePt, improvedPt, cv::Scalar(0,255,0), 1, cv::LINE_AA, 0 );
            randn( processNoise, cv::Scalar(0), cv::Scalar::all(sqrt(KF.processNoiseCov.at<float>(0, 0))));
            state = KF.transitionMatrix*state + processNoise;
            imshow( "Kalman", img );
            code = (char)cv::waitKey(1000);
            if( code > 0 )
                break;
        }
        if( code == 27 || code == 'q' || code == 'Q' )
            break;
    }
    return 0;
}
#endif

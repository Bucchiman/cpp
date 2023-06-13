/*
 * FileName:     resize
 * Author:       8ucchiman
 * CreatedDate:  2023-06-13 16:21:42
 * LastModified: 2023-03-28 10:34:14 +0900
 * Reference:    8ucchiman.jp
 * Description:  ---
 */


// let's start with including libraries 
#include<opencv2/opencv.hpp>
#include<iostream>
 
// Namespace to nullify use of cv::function(); syntax
using namespace std;
using namespace cv;
 
int main(int argc, char* argv[]) {
  // Read the image using imread function
  Mat image = imread(argv[1]);
  imshow("Original Image", image);
 
 
  // let's downscale the image using new  width and height
  int down_width = 564;
  int down_height = 210;
  Mat resized_down;
  //resize down
  resize(image, resized_down, Size(down_width, down_height), INTER_LINEAR);
  // let's upscale the image using new  width and height
  //int up_width = 600;
  //int up_height = 400;
  //Mat resized_up;
  //resize up
  //resize(image, resized_up, Size(up_width, up_height), INTER_LINEAR);
  // Display Images and press any key to continue
  //imshow("Resized Down by defining height and width", resized_down);
  //waitKey();
  if(resized_down.empty())
  {
    std::cerr << "Something is wrong with the webcam, could not get frame." << std::endl;
  }
  // Save the frame into a file
  imwrite(argv[2], resized_down); // A JPG FILE IS BEING SAVED
  //imshow("Resized Up image by defining height and width", resized_up);
  //waitKey();
 
  //destroyAllWindows();
  return 0;
}




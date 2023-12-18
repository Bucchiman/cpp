/*
 * FileName:     opencv_version
 * Author: 8ucchiman
 * CreatedDate:  2023-03-27 20:00:03 +0900
 * LastModified: 2023-03-27 20:00:35 +0900
 * Reference: 8ucchiman.jp
 */


#include <iostream>
#include <opencv2/core.hpp>

#define OPENCV_VERSION(a,b,c) (((a) << 16) + ((b) << 8) + (c))

int main()
{
  std::cout << "version: " << CV_VERSION << std::endl;
}

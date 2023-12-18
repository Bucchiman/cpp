/*
 * FileName:     main
 * Author: 8ucchiman
 * CreatedDate:  2023-03-27 11:51:26 +0900
 * LastModified: 2023-03-27 12:22:26 +0900
 * Reference: 8ucchiman.jp
 */



#include<opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main(int argc, char *argv[]){
  Mat gray_img1,gray_img2,gray_img3,diff1,diff2,frame,diff;
    // カメラからの動画を取り込むためのオブジェクトを宣言する
  VideoCapture capture;
	// カメラを起動する
	capture.open(0);
	if (capture.isOpened() == false) {
		// カメラが起動しないときは終了する
		return 0;
	}

     capture >> frame; //1フレームの画像の読み込み(グレー化)
     cv::cvtColor(frame, gray_img1, cv::COLOR_BGR2GRAY);
     capture >> frame; //2フレームの画像の読み込み(グレー化)
     cv::cvtColor(frame, gray_img2, cv::COLOR_BGR2GRAY);
     capture >> frame; //3フレームの画像の読み込み(グレー化)
     cv::cvtColor(frame, gray_img3, cv::COLOR_BGR2GRAY);

    while (1) {
        //差分1：フレーム1と2の差を求める
        cv::absdiff(gray_img1, gray_img2,diff1);
		    //差分2：フレーム2と3の差を求める
		    cv::absdiff(gray_img2, gray_img3,diff2);
		    //差分1と差分2の結果を比較(論理積)し、diffに出力
		    cv::bitwise_and(diff1,diff2,diff);
        //表示
        cv::namedWindow("diff image", cv::WINDOW_NORMAL);
        cv::imshow("diff image", diff);
        //画像を1frameずらす
        gray_img2.copyTo(gray_img1,gray_img2);
        gray_img3.copyTo(gray_img2,gray_img3);
        capture >> frame; //画像の読み込み
        cv::cvtColor(frame, gray_img3, cv::COLOR_BGR2GRAY); 
        if (waitKey(1) == 'q') break; //
        if (diff.empty() == true) break;  // 画像が読み込めなかったとき、無限ループを抜ける
	}
	return 0;  
}

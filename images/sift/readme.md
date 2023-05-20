<!--
 FileName:      readme
 Author:        8ucchiman
 CreatedDate:   2023-05-02 15:05:51
 LastModified:  2023-01-25 10:56:12 +0900
 Reference:     https://medium.com/data-breach/introduction-to-sift-scale-invariant-feature-transform-65d7f3a72d40
                http://mprg.jp/tutorials/cvtutorial_02
 Description:   ---
-->


# Scale Invariant Feature Transform

## algorithm
1. Scale-space peak selection: Potential location for finding features.
2. Keypoint Localization     : Accurately locating the feature keypoints.
3. Orientation Assignment    : Assigning orientation to keypoints.
4. Keypoint descriptor       : Describing the keypoints as a high dimensional vector.
5. Keypoint Matching


## 1. Scale-space peak selection
### DOG(Difference of Gaussian kernel)

# SIFTアルゴリズム
1. キーポイント検出
 1.1 スケールとキーポイント検出(DoG)
 1.2 キーポイントのローカライズ(サブピクセル位置推定)

2. 特徴記述
 2.1 オリエンテーションの算出(勾配方向ヒストグラム作成)
 2.2 特徴量の記述

## LoGによるスケール探索
- 

## LoGによるスケール探索の問題点
1. 特徴点の検出
2. スケール探索
-> 計算コストが非常に高い

## 解決策
DoGによって特徴点の検出とスケール探索を同時に行う。

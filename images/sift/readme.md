<!--
 FileName:      readme
 Author:        8ucchiman
 CreatedDate:   2023-05-09 17:42:42
 LastModified:  2023-01-25 10:56:12 +0900
 Reference:     http://mprg.jp/tutorials/cvtutorial_02
 Description:   ---
-->


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
